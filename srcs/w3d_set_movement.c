/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:14:43 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 10:14:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Move the camera forward.
*/

static void	move_up(t_w3d *w3d, float speed)
{
	speed *= SPD_MOVEMENT;
	w3d->camera.mov_x = w3d->camera.pos_x \
						+ (speed * cos((w3d->camera.angle / 180.00) * M_PI));
	w3d->camera.mov_y = w3d->camera.pos_y \
						+ (speed * sin((w3d->camera.angle / 180.00) * M_PI));
}

/*
** Move the camera backwards.
*/

static void	move_down(t_w3d *w3d, float speed)
{
	speed *= SPD_MOVEMENT;
	w3d->camera.mov_x = w3d->camera.pos_x \
						- (speed * cos((w3d->camera.angle / 180.00) * M_PI));
	w3d->camera.mov_y = w3d->camera.pos_y \
						- (speed * sin((w3d->camera.angle / 180.00) * M_PI));
}

/*
** Move the camera to the left (strafe).
*/

static void	move_left(t_w3d *w3d, float speed)
{
	speed *= SPD_STRAFE;
	w3d->camera.mov_x = w3d->camera.pos_x \
						- (speed * sin((w3d->camera.angle / 180.00) * M_PI));
	w3d->camera.mov_y = w3d->camera.pos_y \
						+ (speed * cos((w3d->camera.angle / 180.00) * M_PI));
}

/*
** Move the camera to the right (strafe).
*/

static void	move_right(t_w3d *w3d, float speed)
{
	speed *= SPD_STRAFE;
	w3d->camera.mov_x = w3d->camera.pos_x \
						+ (speed * sin((w3d->camera.angle / 180.00) * M_PI));
	w3d->camera.mov_y = w3d->camera.pos_y \
						- (speed * cos((w3d->camera.angle / 180.00) * M_PI));
}

/*
** Set the movement of the camera.
** If the sprint key (shift) is being pressed, duplicate the speed.
** The rotation stays the same, one (1) degree at a time.
*/

void		w3d_set_movement(t_w3d *w3d)
{
	float	speed;

	speed = (w3d->key.sprint == 1) ? SPD_SPRINT : 1.00;
	if (w3d->key.move_up == 1)
		move_up(w3d, speed);
	if (w3d->key.move_down == 1)
		move_down(w3d, speed);
	if (w3d->key.move_left == 1)
		move_left(w3d, speed);
	if (w3d->key.move_right == 1)
		move_right(w3d, speed);
	if (w3d->key.rotate_left == 1)
		w3d->camera.angle += SPD_ANGLE;
	if (w3d->key.rotate_right == 1)
		w3d->camera.angle -= SPD_ANGLE;
}
