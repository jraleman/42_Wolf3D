/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:05:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/25 10:05:43 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Hook to exit the program cleanly, by clicking the red button in the winow's
** frame thingy from the mac window.
*/

static int	exit_hook(t_w3d *w3d)
{
	mlx_destroy_window(w3d->mlx.init, w3d->mlx.win);
	exit(0);
}

/*
** Hook used when a key is released, reset the value of a key back to zero.
*/

static int	key_release_hook(int key, t_w3d *w3d)
{
	if (key == KEY_ESCAPE)
		exit_hook(w3d);
	else if (key == KEY_ANSI_W || key == KEY_UPARROW)
		w3d->key.move_up = 0;
	else if (key == KEY_ANSI_S || key == KEY_DOWNARROW)
		w3d->key.move_down = 0;
	else if (key == KEY_ANSI_A || key == KEY_LEFTARROW)
		w3d->key.rotate_left = 0;
	else if (key == KEY_ANSI_D || key == KEY_RIGHTARROW)
		w3d->key.rotate_right = 0;
	else if (key == KEY_ANSI_Q)
		w3d->key.move_left = 0;
	else if (key == KEY_ANSI_E)
		w3d->key.move_right = 0;
	else if (key == KEY_SHIFT)
		w3d->key.sprint = 0;
	w3d_set_movement(w3d);
	w3d_set_map(w3d);
	return (0);
}

/*
** Hook used when a key is released, updates the value of a key to one,
** indicating that it's being pressed.
*/

static int	key_press_hook(int key, t_w3d *w3d)
{
	if (key == KEY_ESCAPE)
		exit_hook(w3d);
	else if (key == KEY_ANSI_W || key == KEY_UPARROW)
		w3d->key.move_up = 1;
	else if (key == KEY_ANSI_S || key == KEY_DOWNARROW)
		w3d->key.move_down = 1;
	else if (key == KEY_ANSI_A || key == KEY_LEFTARROW)
		w3d->key.rotate_left = 1;
	else if (key == KEY_ANSI_D || key == KEY_RIGHTARROW)
		w3d->key.rotate_right = 1;
	else if (key == KEY_ANSI_Q)
		w3d->key.move_left = 1;
	else if (key == KEY_ANSI_E)
		w3d->key.move_right = 1;
	else if (key == KEY_SHIFT)
		w3d->key.sprint = 1;
	else if (key == KEY_ANSI_O)
		w3d->key.no_clip = ((w3d->key.no_clip == 1) ? 0 : 1);
	else if (key == KEY_TAB)
		w3d->key.hud = ((w3d->key.hud == 1) ? 0 : 1);
	else if (key == KEY_F1)
		w3d->key.debug = ((w3d->key.debug == 1) ? 0 : 1);
	w3d_set_movement(w3d);
	w3d_set_map(w3d);
	return (0);
}

/*
** Hook used to change a weapon via the click of the mouse.
*/

static int	mouse_hook(int button, int x, int y, t_w3d *w3d)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (button == MOUSE_LEFT_CLK)
		{
			w3d->weapon.gun = 1;
			w3d->weapon.knife = 0;
		}
		else if (button == MOUSE_RIGHT_CLK)
		{
			w3d->weapon.gun = 0;
			w3d->weapon.knife = 1;
		}
		else if (button == MOUSE_MIDDLE_CLK)
			w3d->weapon.stealth = (w3d->weapon.stealth == 1) ? 0 : 1;
	}
	w3d_set_map(w3d);
	return (0);
}

/*
** Set mlx the hooks (keys, mouse, and exit).
*/

void		w3d_set_hooks(t_w3d *w3d)
{
	mlx_hook(w3d->mlx.win, 2, 0, key_press_hook, w3d);
	mlx_hook(w3d->mlx.win, 3, 0, key_release_hook, w3d);
	mlx_hook(w3d->mlx.win, 4, 0, mouse_hook, w3d);
	mlx_hook(w3d->mlx.win, 17, 0, exit_hook, w3d);
}
