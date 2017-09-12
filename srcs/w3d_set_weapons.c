/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weapons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:36:12 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/26 12:36:13 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Function to put a string in a specific coordinate (taken as argument),
** on the mlx window.
*/

static void	draw_weapon_str(t_w3d *w3d, int y, int color, char *str)
{
	mlx_string_put(w3d->mlx.init, w3d->mlx.win, \
					WIN_WIDTH - 650, WIN_HEIGHT - y, color, str);
}

/*
** Draw a gun.
*/

static void	draw_gun(t_w3d *w3d)
{
	draw_weapon_str(w3d, 320, WHITE, "   _||___");
	draw_weapon_str(w3d, 300, WHITE, "  /......\\");
	draw_weapon_str(w3d, 280, WHITE, "  |\\......\\");
	draw_weapon_str(w3d, 260, WHITE, "  \\ \\......\\");
	draw_weapon_str(w3d, 240, WHITE, "  /\\ \\......\\");
	draw_weapon_str(w3d, 220, WHITE, " |  \\ \\......\\");
	draw_weapon_str(w3d, 200, WHITE, " | \\ \\ \\......\\");
	draw_weapon_str(w3d, 180, WHITE, " |  | \\ \\......\\");
	draw_weapon_str(w3d, 160, WHITE, "  \\ |_|\\ \\......\\");
	draw_weapon_str(w3d, 140, WHITE, "   \\   |\\ \\......\\");
	draw_weapon_str(w3d, 120, WHITE, "    \\__|-\\ \\......\\");
	draw_weapon_str(w3d, 100, WHITE, "       |--\\ \\  ____\\");
	draw_weapon_str(w3d, 80, WHITE, "       |---\\ \\/+++++\\");
	draw_weapon_str(w3d, 60, WHITE, "       |----\\ |+++++|");
	draw_weapon_str(w3d, 40, WHITE, "       |----|\\|_____|");
	draw_weapon_str(w3d, 20, WHITE, "       |----|=====|");
}

/*
** Draw a knife... it's NOT a sword >:(
*/

static void	draw_knife(t_w3d *w3d)
{
	draw_weapon_str(w3d, 260, WHITE, " ,.");
	draw_weapon_str(w3d, 240, WHITE, " \\%%`.");
	draw_weapon_str(w3d, 220, WHITE, "  `.%%`.");
	draw_weapon_str(w3d, 200, WHITE, "    `.%%`.");
	draw_weapon_str(w3d, 180, WHITE, "      `.%%`.");
	draw_weapon_str(w3d, 160, WHITE, "        `.%%`.");
	draw_weapon_str(w3d, 140, WHITE, "          `.%%`.    __");
	draw_weapon_str(w3d, 120, WHITE, "            `.%%`.  \\ \\");
	draw_weapon_str(w3d, 100, WHITE, "              `.%%`./_/");
	draw_weapon_str(w3d, 80, WHITE, "                `./ /.");
	draw_weapon_str(w3d, 60, WHITE, "               __/\\/:/;.");
	draw_weapon_str(w3d, 40, WHITE, "               \\__/  `:/;.");
	draw_weapon_str(w3d, 20, WHITE, "                       `:/;.,");
}

/*
** Set the weapons.
** Stealth takes a priority, meaning that if the stealth is on, one cannot
** change between the gun and the knife.
*/

void		w3d_set_weapons(t_w3d *w3d)
{
	if (w3d->weapon.stealth == 1)
	{
		if (w3d->weapon.gun == 1)
			draw_gun(w3d);
		else if (w3d->weapon.knife == 1)
			draw_knife(w3d);
	}
}
