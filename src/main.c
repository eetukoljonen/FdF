/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:21 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:49:46 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this program is creating a simple wireframe model
**	represantation of 3D landscape by linkin various
**	points (x, y, z) thanks to line segments
**	using our schools own graphic library minilibx
*/

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc == 2)
	{
		fdf = init_fdf();
		read_map(argv[1], fdf);
		init_camera(fdf);
		init_mlx(fdf);
		draw(fdf);
		controls(fdf);
		mlx_loop(fdf->img.mlx);
	}
	return (0);
}
