/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:42:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:49:14 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function initializes the fdf struct
*/

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->camera = NULL;
	fdf->map.map_arr = 0;
	fdf->map.clr_arr = 0;
	fdf->map.allocated_rows = 0;
	if (!fdf)
		error_exit(MALLOC_ERROR, fdf);
	return (fdf);
}

/*
**	this function intializes the camera struct and
**	gets the proper scaling value for the zoom variable
*/

void	init_camera(t_fdf *fdf)
{
	int	a;
	int	b;

	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!fdf->camera)
		error_exit(MALLOC_ERROR, fdf);
	a = 1000 / fdf->map.width / 2;
	b = 1000 / fdf->map.height / 2;
	if (b > a)
		b = a;
	fdf->camera->zoom = b;
	fdf->camera->proj = 0;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	fdf->camera->z_divisor = 1;
	fdf->camera->x_offset = 0;
	fdf->camera->y_offset = 0;
}

/*
**	this function initializes minilibx
*/

void	init_mlx(t_fdf *fdf)
{
	fdf->img.mlx = mlx_init();
	if (!fdf->img.mlx)
		error_exit(MLX_ERROR, fdf);
	fdf->img.mlx_win = mlx_new_window(fdf->img.mlx, 1000, 1000, "fdf");
	if (!fdf->img.mlx_win)
		error_exit(MLX_ERROR, fdf);
	fdf->img.img = mlx_new_image(fdf->img.mlx, 1000, 1000);
	if (!fdf->img.img)
		error_exit(MLX_ERROR, fdf);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	if (!fdf->img.addr)
		error_exit(MLX_ERROR, fdf);
}
