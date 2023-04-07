/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:24:28 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:52:07 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function manipulates the vectors so it projects it to the
**	screen correctly
*/

t_vec	project(t_fdf *fdf, t_vec vec)
{
	vec.x *= fdf->camera->zoom;
	vec.y *= fdf->camera->zoom;
	vec.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	vec.x -= (fdf->map.width * fdf->camera->zoom) / 2;
	vec.y -= (fdf->map.height * fdf->camera->zoom) / 2;
	rotate_x(&vec.y, &vec.z, fdf->camera->alpha);
	rotate_y(&vec.x, &vec.z, fdf->camera->beta);
	rotate_z(&vec.x, &vec.y, fdf->camera->gamma);
	if (!fdf->camera->proj)
		iso_projection(&vec.x, &vec.y, vec.z);
	else if (fdf->camera->proj == 1)
		cabinet_projection(&vec.x, &vec.y, vec.z);
	vec.x += 1000 / 2 + fdf->camera->x_offset;
	vec.y += 1000 / 2 + fdf->camera->y_offset + 100;
	return (vec);
}

/*
**	this function puts the vector into isometric projection
*/

void	iso_projection(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
**	this function puts the vector into cabinet projection
*/

void	cabinet_projection(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x + cos(1) * -z;
	*y = previous_y + sin(1) * -z;
}
