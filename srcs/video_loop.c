/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:27:32 by niragne           #+#    #+#             */
/*   Updated: 2020/03/05 15:03:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include "renderer.h"

void	renderer_loop(struct gbmu_wrapper_s* wrapper)
{
	struct tile_s tiles[TILES_COUNT];
	while (wrapper->gb->running)
	{
		fill_tile_array(wrapper->gb, tiles);
		vram_viewer_loop(wrapper, tiles);
		main_window_loop(wrapper, tiles);
	}
}
