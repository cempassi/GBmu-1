/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:34:47 by niragne           #+#    #+#             */
/*   Updated: 2020/02/17 14:10:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H
# include <stdint.h>

# define VRAM_SIZE 0x2000		// 8kiB
# define WRAM_SIZE 0x2000		// 8kiB
# define HRAM_SIZE 0x100		// 256B
# define RAM_SIZE 0x2000		// 8kiB
# define IO_PORTS_SIZE 0x100	// 256B
# define OAM_SIZE 0x9f			// 160B

# define IO_OFFSET	 0xFF00
# define LCDC_OFFSET (IO_OFFSET | 0x40)

// FLAG REGISTER: ZNHC0000
# define ZERO_FLAG			(1 << 7)
# define SUBSTRACTION_FLAG	(1 << 6)
# define HALF_CARRY_FLAG	(1 << 5)
# define CARRY_FLAG			(1 << 4)

# define INT_VBLANK 0x40

struct registers_s {
	struct {
		union {
			struct {
				uint8_t f;
				uint8_t a;
			};
			uint16_t af;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t c;
				uint8_t b;
			};
			uint16_t bc;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t e;
				uint8_t d;
			};
			uint16_t de;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t l;
				uint8_t h;
			};
			uint16_t hl;
		};
	};
	
	uint16_t	sp; // Stack pointer
	uint16_t	pc; // Program counter
};

struct	gb_cpu_s
{
	int					jmp : 1; // Flags used by the emulator. Ugly but hopefully temporary ?
	int					running : 1;
	int					paused : 1;
	uint16_t			interrupt;
	uint32_t			cycle;

	int					ime : 1; // Interrupt Master Enable Flag
	struct registers_s	reg;
	struct inst_s*		current_instruction;
	struct rom_s*		rom_ptr;
	uint8_t				vram[VRAM_SIZE];
	uint8_t				ram[RAM_SIZE];
	uint8_t				wram[WRAM_SIZE];
	uint8_t				hram[HRAM_SIZE];
	uint8_t				io_ports[IO_PORTS_SIZE];
	uint8_t				oam[OAM_SIZE];
	uint8_t				interrupt_enable_register;
};

/*

This is, as far as I understand, the memory map of the gameboy:

0000 - 7FFF (32kb) : ROM AREA
	0100 - 014F : Header
	0150 - 3FFF : Bank 0
	4000 - 7FFF : Bank 1
8000 - 97FF : TILE RAM
9800 - 9BFF : Background Data 1
9C00 - 9FFF : Background Data 2
A000 - BFFF : Extra RAM (if any)
C000 - DFFF : RAM
E000 - FDFF : Echo RAM
FE00 - FE9F : OAM
FEA0 - FEFF : Unused
FF00 - FF7F : I/O Registers
FF80 - FFFE : HRAM
FFFF		: Interrupt?

*/


#endif