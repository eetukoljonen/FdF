/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:23:45 by ekoljone          #+#    #+#             */
/*   Updated: 2023/04/06 20:47:00 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function rotates the vector around the y axis
*/

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;
	int	previous_z;

	previous_x = *x;
	previous_z = *z;
	*z = previous_z * cos(beta) - previous_x * sin(beta);
	*x = previous_z * sin(beta) + previous_x * cos(beta);
}

/*
**	this function rotates the vector around the x axis
*/

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;
	int	previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(alpha) - previous_z * sin(alpha);
	*z = previous_y * sin(alpha) + previous_z * cos(alpha);
}

/*
**	this function rotates the vector around the z axis
*/

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}
