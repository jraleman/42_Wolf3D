/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:43:51 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 09:43:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Put a pixel on the image, showing it on the window. <3
*/

static void	put_pixel(t_w3d *w3d, int color, int x, float ray)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	y = ((WIN_HEIGHT / 2) * w3d->image.size) + (x * w3d->image.bpp / 8);
	while (i < (WIN_HEIGHT / (2 * ray)))
	{
		j = 0;
		while (j < (w3d->image.bpp / 8))
		{
			w3d->image.data[(j + y - (i * w3d->image.size)) / 4] = color;
			w3d->image.data[(j + y + (i * w3d->image.size)) / 4] = color;
			j += 1;
		}
		i += 1;
	}
}

/*
** Draw the grids (including walls), using ray casting (see raycast.c).
*/

static void	draw_grids(t_w3d *w3d)
{
	int		i;
	int		color;
	float	tmp_y;
	float	ray;

	i = 0;
	w3d->grid.angle = (w3d->camera.angle / 180.00) * M_PI;
	while (i < WIN_WIDTH)
	{
		tmp_y = ((WIN_WIDTH / 2) - (float)i) / WIN_WIDTH;
		w3d->grid.x = cos(w3d->grid.angle) - tmp_y * sin(w3d->grid.angle);
		w3d->grid.y = sin(w3d->grid.angle) + tmp_y * cos(w3d->grid.angle);
		w3d->grid.x += w3d->camera.pos_x;
		w3d->grid.y += w3d->camera.pos_y;
		ray = w3d_raycast(w3d, &color);
		put_pixel(w3d, color, i, ray);
		i += 1;
	}
}

/*
** Draw the background (sky and flood).
** The sky is being drawn as a beautiful gradient, while the floor is just
** one color.
*/

static void	draw_background(t_w3d *w3d)
{
	int		i;

	i = 0;
	while (i < (w3d->image.size * WIN_HEIGHT / 2))
	{
		w3d->image.data[i / 4] = GRADIENT(i);
		i += 1;
	}
	while (i < (w3d->image.size * WIN_HEIGHT))
	{
		w3d->image.data[i / 4] = FLOOR_COLOR;
		i += 1;
	}
}

/*
** Set the map, calling all the necessary functions.
*/

void		w3d_set_map(t_w3d *w3d)
{
	draw_background(w3d);
	draw_grids(w3d);
	w3d_set_collision(w3d);
	mlx_put_image_to_window(w3d->mlx.init, w3d->mlx.win, w3d->mlx.img, 0, 0);
	w3d_set_hud(w3d);
	w3d_set_weapons(w3d);
	if (w3d->key.debug == 1)
		w3d_set_debug(w3d);
}
