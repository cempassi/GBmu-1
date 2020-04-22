/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:11:30 by niragne           #+#    #+#             */
/*   Updated: 2020/04/22 21:41:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int		display_test(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	int i = 0;
	int j = 0;
	int index = 0;

	int scy = read_8(wrapper->gb, SCY_OFFSET) / 8;
	int scx = (read_8(wrapper->gb, SCX_OFFSET)) / 8 ;

	while (i < USERSCREEN_WIDTH / TILE_SURFACE_WIDTH)
	{
		j = 0;
		while (j < USERSCREEN_HEIGHT / TILE_SURFACE_HEIGHT)
		{
			uint16_t tile_index = wrapper->gb->vram[BGMAP1_OFFSET + (i + scx) % 32 + ((j + scy) % 32) * 32];
			if (tile_index + 0x100 < 256 + 128)
				tile_index += 0x100;
			SDL_Rect pos = (SDL_Rect) {i * 8 , j * 8, TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
			print_tile(wrapper->main_context, array + tile_index, 0, pos);
			j++;
		}
		i++;
		index++;
	}
	i = 0;
	index = 0;
	while (i < OAM_SIZE)
	{
		uint8_t y = 	wrapper->gb->oam[i + 0];
		uint8_t x = 	wrapper->gb->oam[i + 1];
		uint8_t tile =	wrapper->gb->oam[i + 2];
		uint8_t attr =	wrapper->gb->oam[i + 3];
		// if (wrapper->gb->paused == 0)
			// printf("X = %x Y = %x TILE = %x ATTR = %x\n", x, y, tile, attr);
		SDL_Rect pos1 = (SDL_Rect) {x - 8, y - 16,  TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
		SDL_Rect pos2 = (SDL_Rect) {x - 8, y - 8,  TILE_SURFACE_WIDTH, TILE_SURFACE_HEIGHT};
		print_tile(wrapper->main_context, array + tile, attr, pos1);
		print_tile(wrapper->main_context, array + tile + 1, attr, pos2);
		i += 4;
	}
	// if (wrapper->gb->paused == 0)
		// printf("\n");
	return (0);
}

void	main_window_loop(struct gbmu_wrapper_s* wrapper, struct tile_s* array)
{
	SDL_Event event;

   	while (SDL_PollEvent(&event)) 
	{
   		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				wrapper->gb->running = 0;
			if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
				wrapper->gb->paused = 1;
		}
   	}
	if (!wrapper->gb->paused)
		handle_joypad(wrapper->gb);

	SDL_FillRect(wrapper->main_context->surface, NULL, 0);
	if (display_test(wrapper, array))
	{
		printf("jette toi dans lcanal\n");
		wrapper->gb->running = 0;
	}
	wrapper->main_context->texture = SDL_CreateTextureFromSurface(wrapper->main_context->renderer, wrapper->main_context->surface);
	SDL_RenderCopy(wrapper->main_context->renderer, wrapper->main_context->texture, NULL, NULL);
	SDL_RenderPresent(wrapper->main_context->renderer);
	SDL_DestroyTexture(wrapper->main_context->texture);
}