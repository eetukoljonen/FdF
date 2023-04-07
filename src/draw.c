/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:13:10 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:44:04 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function puts the pixel to the correct x y coordinate
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < 1000) && (y < 1000 && y > 0))
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/*
**	this function prints the instuction list
*/

void	print_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 1, 0xffffff, "Change projection: P");
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 25, 0xffffff, "Move: < ^ v >");
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 50, 0xffffff, "Zoom: Numpad +  -");
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 75, 0xffffff, "Rotate XY: W A S D");
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 100, 0xffffff, "Rotate Z: K L");
	mlx_string_put(fdf->img.mlx,
		fdf->img.mlx_win, 3, 125, 0xffffff, "Flatten: Mainpad +  -");
}

/*
**	this function returns the positive absolute value of an integer
*/

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

/*
**	this is an implementation of the bresenham's line drawing
**	algorithm that determines the path from the start vector to
**	the end vector
*/

void	plotline(t_fdf *fdf, t_vec v1, t_vec v2)
{
	fdf->bres.dx = ft_abs(v2.x - v1.x);
	fdf->bres.dy = -ft_abs(v2.y - v1.y);
	fdf->bres.sx = -1;
	if (v1.x < v2.x)
		fdf->bres.sx = 1;
	fdf->bres.sy = -1;
	if (v1.y < v2.y)
		fdf->bres.sy = 1;
	fdf->bres.error[0] = fdf->bres.dx + fdf->bres.dy;
	while (v1.x != v2.x || v1.y != v2.y)
	{
		my_mlx_pixel_put(&fdf->img, v1.x, v1.y, v1.color);
		fdf->bres.error[1] = 2 * fdf->bres.error[0];
		if (fdf->bres.error[1] >= fdf->bres.dy)
		{
			fdf->bres.error[0] += fdf->bres.dy;
			v1.x += fdf->bres.sx;
		}
		if (fdf->bres.error[1] <= fdf->bres.dx)
		{
			fdf->bres.error[0] += fdf->bres.dx;
			v1.y += fdf->bres.sy;
		}
	}
	my_mlx_pixel_put(&fdf->img, v1.x, v1.y, v1.color);
}

/*
**	this funtion sends the x and y coordinates to the new_vec and project
**	function which manipulate the coordinates so it projects to the screen
**	correctly then it sends the manipulated coordinates to the plotline
**	function
*/

void	draw(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	ft_bzero(fdf->img.addr, 1000 * 1000 * (fdf->img.bits_per_pixel / 8));
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x != fdf->map.width - 1)
				plotline(fdf, project(fdf, new_vec(fdf, x, y)),
					project(fdf, new_vec(fdf, x + 1, y)));
			if (y != fdf->map.height - 1)
				plotline(fdf, project(fdf, new_vec(fdf, x, y)),
					project(fdf, new_vec(fdf, x, y + 1)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->img.mlx, fdf->img.mlx_win, fdf->img.img, 0, 0);
	print_instructions(fdf);
}
