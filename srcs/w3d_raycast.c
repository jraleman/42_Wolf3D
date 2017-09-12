/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:42:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 09:42:41 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Gives a color to a grid.
** Grid 1 to 4 are walls, from 5 to 7 are blocks, grid 8 and 9 are "portals".
** Everything else is colored black.
*/

static void	color_grid(int grid, int *color)
{
	if (grid == 1)
		*color = NORTH_WALL;
	else if (grid == 2)
		*color = EAST_WALL;
	else if (grid == 3)
		*color = SOUTH_WALL;
	else if (grid == 4)
		*color = WEST_WALL;
	else if (grid == 5)
		*color = OBJECT_COLOR1;
	else if (grid == 6)
		*color = OBJECT_COLOR2;
	else if (grid == 7)
		*color = OBJECT_COLOR3;
	else if (grid == 8)
		*color = PORTAL_ONE;
	else if (grid == 9)
		*color = PORTAL_TWO;
	else
		*color = BLACK;
}

/*
** This is where the real shit happens.
** Each grid can either be 0 (no wall), or a positive
** value (wall with a certain color or texture).
** For every every vertical stripe of the screen, send out a ray that starts at
** the player location and with a direction that depends on both the player's
** looking direction, and the x-coordinate of the screen. Then, let this ray
** move forward on the 2D map, until it hits a map square that is a wall.
** If it hit a wall, calculate the distance of this hit point to the player,
** and use this distance to calculate how high this wall has to be drawn on
** the screen: the further away the wall, the smaller it's on screen, and
** the closer, the higher it appears to be.
** To find the first wall that a ray encounters on its way, it start at
** the player's position, and then check if the ray is inside a wall.
** If it's, the loop can stop, calculate the distance, and draw the wall with
** the correct height. If the ray position is not in a wall, it's traced
** further, adding a certain value to its position, in the direction of the
** direction of the ray, and for this new position, again check if it's
** inside a wall or not. Keep doing this until finally a wall is hit.
*/

float		w3d_raycast(t_w3d *w3d, int *color)
{
	int		x;
	int		y;
	float	raycast;

	raycast = 1.00;
	x = w3d->camera.pos_x + (raycast * (w3d->grid.x - w3d->camera.pos_x));
	y = w3d->camera.pos_y + (raycast * (w3d->grid.y - w3d->camera.pos_y));
	while (g_map[x][y] == 0)
	{
		x = w3d->camera.pos_x + (raycast * (w3d->grid.x - w3d->camera.pos_x));
		y = w3d->camera.pos_y + (raycast * (w3d->grid.y - w3d->camera.pos_y));
		raycast += A_ALIASING;
	}
	color_grid(g_map[x][y], color);
	return (raycast);
}
