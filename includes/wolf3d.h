/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:54:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/15 18:54:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
** Required header files.
*/

# include <math.h>
# include <unistd.h>
# include <stdlib.h>

/*
** User defined header files.
*/

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "mouse.h"

/*
** Macros the window size (width and height).
*/

# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

/*
** Macros for general colors.
*/

# define WHITE			(0xffffff)
# define BLUE			(0xc24643)
# define GREEN			(0x75a557)
# define YELLOW			(0xfdd305)
# define GRAY			(0x5d5d5d)
# define BLACK			(0x111111)

/*
** Macros for the map color, grids, objects, etc...
*/

# define SKY_COLOR		(0x00e1c1f1)
# define FLOOR_COLOR	(0x004b2d01)
# define NORTH_WALL		(0x00b17e64)
# define SOUTH_WALL		(0x00b88a73)
# define EAST_WALL		(0x00c09783)
# define WEST_WALL		(0x00c8a492)
# define OBJECT_COLOR1	(0x00011F4B)
# define OBJECT_COLOR2	(0x001a355d)
# define OBJECT_COLOR3	(0x00334b6e)
# define PORTAL_ONE		(0xaf007ce7)
# define PORTAL_TWO		(0xafe76b00)

/*
** Macros used for the anti-aliasing, and gradient (presion and macro function).
*/

# define A_ALIASING		(0.0050)
# define SPD_WALK		(1.0000)
# define SPD_SPRINT		(2.0000)
# define SPD_MOVEMENT	(0.0750)
# define SPD_STRAFE		(0.0150)
# define SPD_ANGLE		(1.5000)
# define GRAD_PREC		(0.0001)
# define GRADIENT(i)	((SKY_COLOR - i) * GRAD_PREC)

/*
** Macros used for the width and the height of the map.
*/

# define MAP_WIDTH		(25)
# define MAP_HEIGHT		(25)

/*
** Global variable used for the map.
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern int		g_map[MAP_WIDTH][MAP_HEIGHT];

# endif

/*
** Redefine some of the keys from the keyboard (not following a standard).
*/

# undef KEY_CONTROL
# define KEY_CONTROL	(0X100)
# undef KEY_SHIFT
# define KEY_SHIFT		(0X101)
# undef KEY_COMMAND
# define KEY_COMMAND	(0X103)
# undef KEY_OPTION
# define KEY_OPTION		(0X105)

/*
** Wolf3D Structures
**
** @t_mlx : Required minilibx arguments.
**             init -> set up a connection to the graphical system.
**             win -> manages the window.
**             img -> manipulates the image.
** @t_img : Used to create a new image.
**             data -> information about the image, allowing to be modified.
**             size -> move from one line to another in the image.
**             endian -> how the pixel color in the image needs to be stored.
**             bpp -> filled with number of bits to represent a pixel color.
** @t_key : Keys used to control the enviroment.
**             hud -> toggle (show / hide) the HUD.
**             debug -> toggle (show / hide) the debug stats menu thingy.
**             sprint -> makes the movement faster.
**             no_clip -> walk through walls.
**             move_up -> move the camera forward.
**             move_down -> move the camera backwards.
**             move_left -> move the camera to the left.
**             move_right -> move the camera to the right.
**             rotate_left -> rotate to the left (increase angle).
**             rotate_right -> rotate to the right (decrease angle).
** @t_wep : Used to draw a weapon (no pun intended).
**             stealth -> no weapons (stealth mode).
**             gun -> draw a gun.
**             knife -> draw a knife.
** @t_cam : Camera structure, pretty much what's being seen on the screen.
**             angle -> manipulates the camera angle.
**             pos_x -> the current x position on the map.
**             pos_y -> the current y position on the map.
**             mov_x -> calculates the x position movement.
**             mov_y -> calculates the y position movement.
** @t_grd : Map's grid, every little box and space on the map.
**          Used by ray casting. :)
**             x -> Width of the grid.
**             y -> Height of the grind.
**             angle -> Angle of the grid.
** @t_w3d : nested structure that calls all the other structures. :)
*/

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_img
{
	int		bpp;
	int		size;
	int		endian;
	int		*data;
}				t_img;

typedef struct	s_key
{
	int		hud;
	int		debug;
	int		sprint;
	int		no_clip;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}				t_key;

typedef struct	s_wep
{
	int		stealth;
	int		gun;
	int		knife;
}				t_wep;

typedef struct	s_cam
{
	float	angle;
	float	mov_x;
	float	mov_y;
	float	pos_x;
	float	pos_y;
}				t_cam;

typedef struct	s_grid
{
	float	x;
	float	y;
	float	angle;
}				t_grid;

typedef struct	s_w3d
{
	t_mlx	mlx;
	t_img	image;
	t_key	key;
	t_wep	weapon;
	t_cam	camera;
	t_grid	grid;
}				t_w3d;

/*
** Function prototypes.
*/

void			w3d_set_hooks(t_w3d *w3d);
void			w3d_set_movement(t_w3d *w3d);
void			w3d_set_map(t_w3d *w3d);
void			w3d_set_collision(t_w3d *w3d);
void			w3d_set_hud(t_w3d *w3d);
void			w3d_set_debug(t_w3d *w3d);
void			w3d_set_weapons(t_w3d *w3d);
float			w3d_raycast(t_w3d *w3d, int *color);

#endif
