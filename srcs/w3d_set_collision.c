/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:05:05 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 10:05:08 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Set the collision in the map. All the grids, and walls, cannot be
** walkthrough. If the no_clip key is on, just the walls cannot be walkthrough.
*/

void	w3d_set_collision(t_w3d *w3d)
{
	int		x;
	int		y;

	x = (int)(w3d->camera.mov_x);
	y = (int)(w3d->camera.mov_y);
	if ((w3d->camera.mov_x > 0 && w3d->camera.mov_x < MAP_WIDTH) \
		&& (w3d->camera.mov_y > 0 && w3d->camera.mov_y < MAP_HEIGHT))
	{
		if (g_map[x][y] == 0 || (w3d->key.no_clip == 1 && g_map[x][y] != 1 \
			&& g_map[x][y] != 2 && g_map[x][y] != 3 && g_map[x][y] != 4) \
			|| g_map[x][y] == 8 || g_map[x][y] == 9)
		{
			w3d->camera.pos_x = w3d->camera.mov_x;
			w3d->camera.pos_y = w3d->camera.mov_y;
		}
	}
}
