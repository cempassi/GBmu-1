/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:16:47 by niragne           #+#    #+#             */
/*   Updated: 2020/05/04 19:19:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gb.h"

struct gb_cpu_s;

void	fatal(struct gb_cpu_s* gb)
{
	save_game_crash(gb);
	abort();
}