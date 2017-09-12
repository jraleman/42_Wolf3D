/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:06:13 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 10:06:14 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Array used to get the position of the grids and wall from the map.
*/

int		g_map[25][25] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 2},
	{4, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 9, 7, 7, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
};

/*
** Initialize some of the variables, like mlx, keys, weapons, and camera,
** from the w3d structure.
*/

static t_w3d	*init_w3d_values(void)
{
	t_w3d		*w3d;

	if (!(w3d = (t_w3d *)malloc(sizeof(t_w3d))))
		ft_puterror("Memory Allocation failed! :O", 1);
	w3d->mlx.init = mlx_init();
	w3d->mlx.win = mlx_new_window(w3d->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
					"Wolf3D - Effortless Edition :)");
	w3d->mlx.img = mlx_new_image(w3d->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	w3d->image.data = (int *)mlx_get_data_addr(w3d->mlx.img, &w3d->image.bpp, \
						&w3d->image.size, &w3d->image.endian);
	w3d->key.hud = 1;
	w3d->key.sprint = 0;
	w3d->key.no_clip = 0;
	w3d->key.rotate_left = 0;
	w3d->key.rotate_right = 0;
	w3d->weapon.stealth = 1;
	w3d->weapon.gun = 1;
	w3d->weapon.knife = 0;
	w3d->camera.mov_x = 0.00;
	w3d->camera.mov_y = 0.00;
	w3d->camera.pos_x = 18.0;
	w3d->camera.pos_y = 3.0;
	w3d->camera.angle = 110.00;
	return (w3d);
}

/*
** Get things rolling, calls the main function.
**
** List of sources used:
**   Ray casting -> http://lodev.org/cgtutor/raycasting.html
**   Colors      -> http://www.color-hex.com/color-palette/814
*/

int				main(void)
{
	t_w3d		*w3d;

	w3d = init_w3d_values();
	w3d_set_hooks(w3d);
	w3d_set_map(w3d);
	mlx_loop(w3d->mlx.init);
	return (0);
}
