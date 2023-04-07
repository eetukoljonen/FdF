/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:35:29 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 13:01:24 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function iterates through the splitted array and
**	fills the 2d int arrays with the information that the map provided
*/

void	fill(t_fdf *fdf, char **i)
{
	int			clm;
	static int	row;

	clm = 0;
	while (i[clm] && ft_is_number(i[clm]))
	{
		if (clm >= fdf->map.width || (clm <= fdf->map.width - 1
				&& !ft_is_number(i[clm])))
		{
			free_string_array(i);
			error_exit(INVALID_MAP, fdf);
		}
		if (ft_strchr(i[clm], 'x'))
			fdf->map.clr_arr[row][clm] = atoi_b16(ft_strchr(i[clm], 'x') + 1);
		else
			fdf->map.clr_arr[row][clm] = 0;
		fdf->map.map_arr[row][clm] = ft_atoi(i[clm]);
		clm++;
	}
	if (clm < fdf->map.width)
		error_exit(INVALID_MAP, fdf);
	row++;
}

/*
**	fill_arrays goes through every line and calls fill function which
**	fills the arrays
*/

void	fill_arrays(t_fdf *fdf, int fd)
{
	char	*line;
	char	**i;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = ft_split(line, ' ');
		free(line);
		fill(fdf, i);
		free_string_array(i);
	}
	close(fd);
}

/*
**	this function return the height of the map
*/

int	get_height(int fd, char *row)
{
	int	height;

	height = 1;
	while (1)
	{
		free(row);
		row = get_next_line(fd);
		if (!row)
			break ;
		height++;
	}
	return (height);
}

/*
**	this function gets the map width by splitting the first line
**	and the the height by calling get_next_line	until theres no more
**	lines
*/

void	get_size(int fd, t_fdf *fdf)
{
	int		width;
	char	*row;
	char	**i;

	row = get_next_line(fd);
	if (!row)
		error_exit(INVALID_MAP, fdf);
	i = ft_split(row, ' ');
	width = 0;
	while (i[width] && ft_is_number(i[width]))
		width++;
	if (width < 2)
		error_exit(INVALID_MAP, fdf);
	fdf->map.height = get_height(fd, row);
	fdf->map.width = width;
	free_string_array(i);
	close(fd);
}

/*
**	this function first gets the size of the map
**	then it allocates the correct amount of memory for the
**	2d int arrays
*/

void	read_map(char *arg, t_fdf *fdf)
{
	int	row;
	int	fd;

	row = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_exit(OPEN_ERROR, fdf);
	get_size(fd, fdf);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_exit(OPEN_ERROR, fdf);
	fdf->map.map_arr = (int **)malloc(sizeof(int *) * fdf->map.height);
	fdf->map.clr_arr = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (!fdf->map.map_arr || !fdf->map.clr_arr)
		error_exit(MALLOC_ERROR, fdf);
	while (row < fdf->map.height)
	{
		fdf->map.map_arr[row] = (int *)malloc(sizeof(int) * fdf->map.width);
		fdf->map.clr_arr[row] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!fdf->map.map_arr[row] || !fdf->map.clr_arr[row])
			error_exit(MALLOC_ERROR, fdf);
		row++;
		fdf->map.allocated_rows = row;
	}
	fill_arrays(fdf, fd);
}
