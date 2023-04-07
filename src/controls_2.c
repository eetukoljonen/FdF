/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:32:56 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:38:23 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function calls free_everything and the exits the program
*/

int	close_window(t_fdf *fdf)
{
	free_everything(fdf);
	mlx_destroy_window(fdf->img.mlx, fdf->img.mlx_win);
	exit(0);
	return (0);
}

/*
**	this function manipulates the zoom value of the camera struct
*/

void	zoom_picture(t_fdf *fdf, int keycode)
{
	if (keycode == 69)
		fdf->camera->zoom += 1;
	else
		fdf->camera->zoom -= 1;
	draw(fdf);
}

/*
**	this function translates the map by manipulating the x and y offset
**	of the camera struct
*/

void	move_picture(t_fdf *fdf, int keycode)
{
	if (keycode == 125)
		fdf->camera->y_offset += 8;
	else if (keycode == 126)
		fdf->camera->y_offset -= 8;
	else if (keycode == 124)
		fdf->camera->x_offset += 8;
	else if (keycode == 123)
		fdf->camera->x_offset -= 8;
	draw(fdf);
}
