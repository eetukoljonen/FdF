/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:20 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:42:04 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function determines which projection we want
**	0 == isometric
**	1 == cabinet
**	2 == parallel
*/

void	change_proj(t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (fdf->camera->proj == 0)
		fdf->camera->proj = 1;
	else if (fdf->camera->proj == 1)
		fdf->camera->proj = 2;
	else
		fdf->camera->proj = 0;
	draw(fdf);
}

/*
**	this funtion flattens the map by cahnging z_divisor
**	of the camera struct
*/

void	flatten(t_fdf *fdf, int keycode)
{
	if (keycode == 24)
		fdf ->camera->z_divisor -= 0.1;
	if (keycode == 27)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf);
}

/*
**	this rotates the map by changing the camera
**	structs alpha, beta and gamma values
*/

void	rotate(t_fdf *fdf, int keycode)
{
	if (keycode == 13)
		fdf->camera->alpha += 0.05;
	else if (keycode == 1)
		fdf->camera->alpha -= 0.05;
	else if (keycode == 0)
		fdf->camera->beta -= 0.05;
	else if (keycode == 2)
		fdf->camera->beta += 0.05;
	else if (keycode == 37)
			fdf->camera->gamma += 0.05;
	else if (keycode == 40)
			fdf->camera->gamma -= 0.05;
	draw(fdf);
}

/*
**	this function gets called every time when key is pressed
**	then it goes to the correct function according what key
**	was pressed
*/

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		free_everything(fdf);
		mlx_destroy_window(fdf->img.mlx, fdf->img.mlx_win);
		exit(0);
	}
	else if (keycode == 69 || keycode == 78)
		zoom_picture(fdf, keycode);
	else if (keycode == 126 || keycode == 125
		|| keycode == 124 || keycode == 123)
		move_picture(fdf, keycode);
	else if (keycode == 35)
		change_proj(fdf);
	else if (keycode == 13 || keycode == 0
		|| keycode == 1 || keycode == 2 || keycode == 40 || keycode == 37)
		rotate(fdf, keycode);
	else if (keycode == 24 || keycode == 27)
		flatten(fdf, keycode);
	return (0);
}

/*
**	this function uses the mlx_hook functions to key presses
**	and window closing
*/

void	controls(t_fdf *fdf)
{
	mlx_hook(fdf->img.mlx_win, 2, 0, key_handle, fdf);
	mlx_hook(fdf->img.mlx_win, 17, 0, close_window, fdf);
}
