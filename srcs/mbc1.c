/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:53:11 by niragne           #+#    #+#             */
/*   Updated: 2020/05/06 15:05:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>

#include "gb.h"
#include "mbc.h"
#include "cpu.h"
#include "rom.h"
#ifdef WITH_LIBYACC
# include "libyacc_wrapper.h"
#endif

/**
 * @brief Dump the current MBC rom to a file. For debugging purposes.
 * 
 * @param gb 
 */
void	dump_mbc(struct gb_cpu_s* gb)
{
	FILE* f = fopen("clang.gb", "wb");
	if (f == NULL)
		return ;
	for (size_t j = 0; j < 0x4000; j++)
	{
		uint8_t r = read_8_force(gb, j);
		fwrite(&r, 1, 1, f);
	}
	for (gb->mbc.bank = 1; gb->mbc.bank < gb->mbc.max_rom_banks; gb->mbc.bank++)
	{
		for (size_t j = 0x4000; j < 0x8000; j++)
		{
			uint8_t r = read_8(gb, j);
			fwrite(&r, 1, 1, f);
		}
	}
	fclose(f);
}

uint8_t	read_mbc1(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode)
{
	if (addr < 0x100 && !gb->booted)
	{
		return (((uint8_t*)(gb->boot_rom))[addr]);
	}
	else if (addr < 0x4000)
	{
		return (((uint8_t*)(gb->rom_ptr->ptr))[addr]);
	}
	else if (addr < 0x8000)
	{
		uint8_t tmp;
		if (gb->mbc.mode == MBC_MODE_RAM || gb->rom_ptr->header->rom_size <= 0x04)
			tmp = gb->mbc.bank & 0b11111;
		else
			tmp = gb->mbc.bank;
		if (tmp != 0)
		{
			if (tmp * 0x4000 + addr - 0x4000 > gb->rom_ptr->st.st_size)
			{
				printf("fatal: attempting to read outside the cartridge at %x in bank %x. aborting...\n", addr, tmp);
				fatal(gb);
				return (0);
			}
			return (((uint8_t*)(gb->rom_ptr->ptr))[tmp * 0x4000 + addr - 0x4000]);
		}
		else
			return (((uint8_t*)(gb->rom_ptr->ptr))[addr % 0x4000]);
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to read from disabled RAM at %x\n", addr);
			return (0xff);
		}
		uint32_t index;
		if (gb->mbc.mode == MBC_MODE_RAM)
			index = addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE;
		else
			index = addr - 0xa000;
		if (index >= gb->mbc.ram_size)
		{
			printf("warning: attempting to read %x at invalid ram bank %x\n", addr, gb->mbc.ram_bank);				
			return (0xff);
		}
		else
			return (((uint8_t*)(gb->extra_ram))[index]);	
	}
	return (0xff);
}

void	write_mbc1(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode)
{
	if (addr < 0x2000)
	{
		if (x == 0x0a)
		{
			// if (get_verbose(gb->debugger) >= 1)
				// printf("RAM ENABLED (%4x)\n", addr);
			gb->ram_enabled = 1;
		}
		else
		{
			// if (get_verbose(gb->debugger) >= 1)
			// 	printf("RAM DISABLED (%4x)\n", addr);
			gb->ram_enabled = 0;
		}
		return ;
	}
	else if (addr < 0x4000)
	{
		if (gb->mbc.mode == MBC_MODE_ROM)
			gb->mbc.bank = (gb->mbc.bank & 0b1100000) | (x & 0b11111);
		else
			gb->mbc.bank = (x & 0b11111);
		if (gb->mbc.bank == 0x00 || gb->mbc.bank == 0x20 || gb->mbc.bank == 0x40 || gb->mbc.bank == 0x60)
			gb->mbc.bank += 1;
		gb->mbc.bank &= (gb->mbc.rom_size / 0x4000) - 1;
		return ;
	}
	else if (addr < 0x6000)
	{
		if (gb->mbc.mode == MBC_MODE_RAM)
		{
			gb->mbc.ram_bank = (x & 0b11);
			gb->mbc.ram_bank &= (gb->mbc.ram_size / 0x2000) - 1;
		}
		else
		{
			gb->mbc.bank = (gb->mbc.bank & 0b11111) | ((x & 0b11) << 5);	
			if (gb->mbc.bank == 0x20 || gb->mbc.bank == 0x40 || gb->mbc.bank == 0x60)
				gb->mbc.bank += 1;
			gb->mbc.bank &= (gb->mbc.rom_size / 0x4000) - 1;
		}
		return ;
	}
	else if (addr < 0x8000)
	{
		if (x == 0)
			gb->mbc.mode = MBC_MODE_ROM;
		else if (x == 1)
			gb->mbc.mode = MBC_MODE_RAM;
		printf("SWITCHING MBC MODE %x \n", gb->mbc.mode);
		return ;
	}
	else if (addr < 0xc000)
	{
		if (!gb->ram_enabled)
		{
			printf("warning: attempting to write to disabled RAM at %x\n", addr);
			return ;
		}
		uint32_t index;
		if (gb->mbc.mode == MBC_MODE_RAM)
			index = addr - 0xa000 + gb->mbc.ram_bank * EXTRA_RAM_SIZE;
		else
			index = addr - 0xa000;		
		if (index >= gb->mbc.ram_size)
		{
			printf("warning: attempting to write at %x in invalid extra ram bank %x\n", addr, gb->mbc.ram_bank);				
			return ;
		}
		else
			((uint8_t*)(gb->extra_ram))[index] = x;
		return;
	}
}
