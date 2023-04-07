/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:38:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:47:16 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	if an error occurs this funtion calls free_everything and outputs
**	the error message and exits the program
*/

void	error_exit(char *s, t_fdf *fdf)
{
	free_everything(fdf);
	ft_putstr_fd(s, 2);
	exit(1);
}

/*
**	this functions frees string array
*/

void	free_string_array(char **args)
{
	int	index;

	index = 0;
	while (args[index])
		free(args[index++]);
	free(args);
}

/*
**	this function frees 2d integer arrays
*/

void	free_arrays(t_map map)
{
	int	row;

	row = 0;
	while (row < map.allocated_rows)
	{
		if (map.map_arr[row])
			free(map.map_arr[row]);
		if (map.clr_arr[row])
			free(map.clr_arr[row]);
		row++;
	}
	if (map.clr_arr)
		free(map.clr_arr);
	if (map.map_arr)
		free(map.map_arr);
}

/*
**	this function calls every free function
**	and frees all dynamically allocated memory
*/

void	free_everything(t_fdf *fdf)
{
	if (fdf->camera)
		free(fdf->camera);
	if (fdf)
	{
		if (fdf->map.map_arr)
			free_arrays(fdf->map);
		free(fdf);
	}
}
