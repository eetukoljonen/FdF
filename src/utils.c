/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:19:42 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/17 12:53:14 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function checks if the string is a number
*/

int	ft_is_number(char *s)
{
	if (*s == '\n')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s != '\n' && *s != ',')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/*
**	this function initializes new vector with the correct coordinates
**	and gets the z value and the color value from the 2d integer map array
**	and 2d integer color array
*/

t_vec	new_vec(t_fdf *fdf, int x, int y)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = fdf->map.map_arr[y][x];
	vec.color = fdf->map.clr_arr[y][x];
	if (!vec.color)
		vec.color = 16777215;
	return (vec);
}
