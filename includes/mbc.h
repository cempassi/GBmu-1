/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 10:37:00 by niragne           #+#    #+#             */
/*   Updated: 2022/01/07 08:52:40 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#define BUILT_IN_RAM_SIZE 0x200 // built in ram inside MBC2 chip

struct	gb_cpu_s;

enum	mbc_mode_e
{
	MBC_MODE_ROM,
	MBC_MODE_RAM,
	MBC_MODE_RTC
};

enum	memory_mode_e
{
	MEM_SYSTEM,
	MEM_DEBUGGER,
	MEM_FORCE
};
# define MBC_ATTR_RAM		(1 << 0)
# define MBC_ATTR_BATTERY	(1 << 1)
# define MBC_ATTR_TIMER		(1 << 2)
# define MBC_ATTR_RUMBLE	(1 << 3)
# define MBC_ATTR_SENSOR	(1 << 4)

typedef uint8_t mbc_attr_t;

struct	mbc_s
{
	char*			name;
	enum mbc_mode_e	mode;
	uint8_t			(*read)(struct gb_cpu_s*, uint16_t, enum memory_mode_e);
	void			(*write)(struct gb_cpu_s*, uint16_t, uint8_t, enum memory_mode_e);
	uint16_t		bank;
	uint16_t		ram_bank;
	uint8_t			rtc;
	uint32_t		rom_size;
	uint32_t		ram_size;
	uint32_t		max_rom_banks;
	mbc_attr_t		attr;
};

struct mbc_s get_mbc(int index);

void	write_no_mbc(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode);
uint8_t	read_no_mbc(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode);

void	write_mbc1(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode);
uint8_t	read_mbc1(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode);

void	write_mbc2(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode);
uint8_t	read_mbc2(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode);

void	update_rtc(struct gb_cpu_s* gb);
void	write_mbc3(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode);
uint8_t	read_mbc3(struct gb_cpu_s* gb, uint16_t addr);

void	write_mbc5(struct gb_cpu_s* gb, uint16_t addr, uint8_t x, enum memory_mode_e mode);
uint8_t	read_mbc5(struct gb_cpu_s* gb, uint16_t addr, enum memory_mode_e mode);

void	dump_mbc(struct gb_cpu_s* gb);
