/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:37:45 by niragne           #+#    #+#             */
/*   Updated: 2020/03/04 16:35:08 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# include "gb.h"
# include "SDL.h"

# define VRAM_WINDOW_WIDTH 256
# define VRAM_WINDOW_HEIGHT 512
# define VRAM_SURFACE_WIDTH 1024
# define VRAM_SURFACE_HEIGHT 2048

# define MAIN_WINDOW_WIDTH 512
# define MAIN_WINDOW_HEIGHT 512
# define MAIN_SURFACE_WIDTH 1024
# define MAIN_SURFACE_HEIGHT 1024

# define TILE_SURFACE_WIDTH		64
# define TILE_SURFACE_HEIGHT	64

struct	sdl_context_s
{
	SDL_Window *win;
	SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

struct 	tile_s
{
	uint16_t	pixels_raw[8];
	uint8_t		index[8][8];
	SDL_Surface	*surface;
};


void	vram_viewer_loop(struct gbmu_wrapper_s* wrapper);
int     init_vram_viewer(struct sdl_context_s* context);
int     init_main_window(struct sdl_context_s* context);
int     init_sdl();

#endif