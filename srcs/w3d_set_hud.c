/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:26:33 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/26 11:26:34 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Function to put a string in a specific coordinate (taken as argument),
** on the mlx window.
*/

static void	draw_hud_str(t_w3d *w3d, int y, int color, char *str)
{
	mlx_string_put(w3d->mlx.init, w3d->mlx.win, \
					WIN_WIDTH - 267, WIN_HEIGHT - y, color, str);
}

/*
** Draw werblazkowiczmon, son of William "B.J." Blazkowicz and WereGarurumon.
**
** IMPORTANT! I made an edit in mlx_new_image.m: Line 126
** Now we can put characters to draw squares on the background of the avatar! :)
** But later, I thought that I could just draw a square, fuck me... :'(
** I mean, it works, so I won't touch this.
*/

static void	draw_werblazkowiczmon(t_w3d *w3d)
{
	draw_hud_str(w3d, 240, WHITE, "████████");
	draw_hud_str(w3d, 225, WHITE, "████████");
	draw_hud_str(w3d, 210, WHITE, "████████");
	draw_hud_str(w3d, 195, WHITE, "████████");
	draw_hud_str(w3d, 180, WHITE, "████████");
	draw_hud_str(w3d, 165, WHITE, "████████");
	draw_hud_str(w3d, 150, WHITE, "████████");
	draw_hud_str(w3d, 135, WHITE, "████████");
	draw_hud_str(w3d, 120, WHITE, "████████");
	draw_hud_str(w3d, 105, WHITE, "████████");
	draw_hud_str(w3d, 90, WHITE, "████████");
	draw_hud_str(w3d, 75, WHITE, "████████");
	draw_hud_str(w3d, 240, WHITE, "       /.\\      _-'   ");
	draw_hud_str(w3d, 225, WHITE, "     _/|..\\-''- _ /   ");
	draw_hud_str(w3d, 210, WHITE, "__-',{ |....666...\\   ");
	draw_hud_str(w3d, 195, WHITE, ",,,,/..............\\  ");
	draw_hud_str(w3d, 180, WHITE, ",,,,/.......'o...|o }  ");
	draw_hud_str(w3d, 165, WHITE, ",,,,|............\\ ;  ");
	draw_hud_str(w3d, 150, WHITE, ",,,,..............',   ");
	draw_hud_str(w3d, 135, WHITE, ",,,,,,,\\_........,__\\");
	draw_hud_str(w3d, 120, WHITE, ",,,,,,,,,''-_....\\.// ");
	draw_hud_str(w3d, 105, WHITE, ",,,,,,,,,,,/ '-____'   ");
	draw_hud_str(w3d, 90, WHITE, ",,,,,,,,,,/             ");
	draw_hud_str(w3d, 75, WHITE, ",,,,,,,,_'              ");
	draw_hud_str(w3d, 45, WHITE, "-=* Werblazkowiczmon *=-");
}

/*
** Draw the all the controls on the window.
*/

static void	draw_controls(t_w3d *w3d)
{
	draw_hud_str(w3d, 530, WHITE, "[W][A][S][D]   : Movement");
	draw_hud_str(w3d, 515, WHITE, "[Q][E]         : Strafe");
	draw_hud_str(w3d, 500, WHITE, "[SHIFT]        : Sprint");
	draw_hud_str(w3d, 485, WHITE, "[TAB]          : Hide HUD");
	draw_hud_str(w3d, 470, WHITE, "[O]            : No Clip");
	draw_hud_str(w3d, 455, WHITE, "[RIGHT CLICK]  : Gun");
	draw_hud_str(w3d, 440, WHITE, "[LEFT CLICK]   : Knife");
	draw_hud_str(w3d, 425, WHITE, "[MIDDLE CLICK] : Stealth");
}

/*
** Draw all the stats on the window.
*/

static void	draw_stats(t_w3d *w3d)
{
	draw_hud_str(w3d, 390, GREEN, "Gesund   :  69%");
	draw_hud_str(w3d, 370, GREEN, "            //////---");
	draw_hud_str(w3d, 340, BLUE, "Ruestung :  42%");
	draw_hud_str(w3d, 320, BLUE, "            ////-----");
	draw_hud_str(w3d, 290, YELLOW, "Geld     :  420 / 500");
	draw_hud_str(w3d, 270, YELLOW, "            ////////-");
}

/*
** Set the hud on the window.
*/

void		w3d_set_hud(t_w3d *w3d)
{
	if (w3d->key.hud == 1)
	{
		draw_controls(w3d);
		draw_stats(w3d);
		draw_werblazkowiczmon(w3d);
	}
}
