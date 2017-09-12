/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:30:31 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/26 15:30:34 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Function to put a string in a specific coordinate (taken as argument),
** on the mlx window.
** Joins the info and value into a single string, so it can be printed.
*/

static void	debug_message(t_w3d *w3d, int pos_y, char *info, char *value)
{
	char	*message;

	message = ft_strjoin(info, value);
	mlx_string_put(w3d->mlx.init, w3d->mlx.win, 50, pos_y, WHITE, message);
	free(message);
}

/*
** Set the debug menu on the window.
** Also, NO LEAKS! :D
*/

void		w3d_set_debug(t_w3d *w3d)
{
	char	*on;
	char	*off;
	char	*pos_x;
	char	*pos_y;
	char	*camera_angle;

	on = "Ja";
	off = "Nein";
	pos_x = ft_itoa(w3d->camera.pos_x);
	pos_y = ft_itoa(w3d->camera.pos_y);
	camera_angle = ft_itoa(ft_degrees_to_angle(w3d->camera.angle));
	debug_message(w3d, 30, "Angle  : ", camera_angle);
	debug_message(w3d, 50, "Sprint : ", (w3d->key.sprint == 1 ? on : off));
	debug_message(w3d, 70, "NoClip : ", (w3d->key.no_clip == 1 ? on : off));
	debug_message(w3d, 90, "Up     : ", (w3d->key.move_up == 1 ? on : off));
	debug_message(w3d, 110, "Down   : ", (w3d->key.move_down == 1 ? on : off));
	debug_message(w3d, 130, "Left   : ", (w3d->key.move_left == 1 ? on : off));
	debug_message(w3d, 150, "Right  : ", (w3d->key.move_right == 1 ? on : off));
	debug_message(w3d, 170, "Pos X : ", pos_x);
	debug_message(w3d, 190, "Pos Y : ", pos_y);
	free(pos_x);
	free(pos_y);
	free(camera_angle);
}
