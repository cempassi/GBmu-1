/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/04/27 16:06:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	renderer_loop(struct gbmu_wrapper_s* wrapper)
// {
	// Uint64 startTime = 0;
    // Uint64 endTime = 0;
    // Uint64 delta = 0;
    // Uint64 timePerFrame = 16;
	// startTime = SDL_GetTicks();
    // SDL_Surface* tmp_surface = SDL_CreateRGBSurface(0, BGMAP_SIZE, BGMAP_SIZE, 32, 0, 0, 0, 0);
	// struct tile_s tiles[TILES_COUNT];
	// while (wrapper->gb->running)
	// {
		// delta = endTime - startTime;
		// fill_tile_array(wrapper->gb, tiles);
		// if (wrapper->gb->vram_viewer_running)
			// vram_viewer_loop(wrapper, tiles);
		// main_window_loop(wrapper);
		// if (delta < timePerFrame) {
            // SDL_Delay(timePerFrame - delta);
        // }
	    // startTime = endTime;
        // endTime = SDL_GetTicks();
	// }
	// SDL_FreeSurface(tmp_surface);
	// if (wrapper->main_context->controller)
		// SDL_GameControllerClose(wrapper->main_context->controller);
// }
// 