#ifndef GB_H
# define GB_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <stdint.h>
# include "op.h"

extern struct inst_s op_tab[256];

struct rom_hdr_s
{
	uint8_t	entry[4];
	uint8_t	logo[48];
	uint8_t	title[16];
	uint8_t	manufacturer_code[2];
	uint8_t	sgb_flag;
	uint8_t type;
	uint8_t	rom_size;
	uint8_t ram_size;
	uint8_t lang;
	uint8_t manufacturer_code_extend;
	uint8_t version;
	uint8_t complement_check;
	uint8_t checksum[2];
};

struct rom_s
{
	struct rom_hdr_s*	header;
	void*				ptr;	
};

void	init_cpu(struct gb_cpu_s* gb);
int		handle_instruction(struct gb_cpu_s* gb);
uint8_t	update_current_instruction(struct gb_cpu_s* gb);
void	init_op_tab(void);

/*
** Debug
*/
void	debug_print_registers(struct registers_s reg);
void	debug_print_gb(struct gb_cpu_s* gb);
void	debug_print_instruction(struct inst_s* inst);
void	debug_print_rom(struct rom_s* rom);
void	debug_print_rom_hdr(struct rom_hdr_s* hdr);
void	debug_print_gb_flags(struct gb_cpu_s* gb);

#endif