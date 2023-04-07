/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_b16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:44:00 by ekoljone          #+#    #+#             */
/*   Updated: 2023/03/13 15:04:43 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	this function convers the hexa letters
**	to an integer value
*/

int	convert_atof(char atof)
{
	int	conversion;

	conversion = 0;
	if (atof == 'a' || atof == 'A')
		conversion = 10;
	else if (atof == 'b' || atof == 'B')
		conversion = 11;
	else if (atof == 'c' || atof == 'C')
		conversion = 12;
	else if (atof == 'd' || atof == 'D')
		conversion = 13;
	else if (atof == 'e' || atof == 'E')
		conversion = 14;
	else if (atof == 'f' || atof == 'F')
		conversion = 15;
	return (conversion);
}

/*
**	this function counts the string lenght while
**	the characters are hexa characters
*/

int	hexa_strlen(char *string)
{
	int	lenght;

	lenght = 0;
	while (*string)
	{
		if ((*string >= '0' && *string <= '9')
			|| (*string >= 'a' && *string <= 'f')
			|| (*string >= 'A' && *string <= 'F'))
			lenght++;
		string++;
	}
	return (lenght);
}

/*
**	this function takes and hexadecimal string and
**	converts it to a integer value
*/

int	atoi_b16(char *s)
{
	int	conversion;
	int	res;
	int	sign;
	int	len;

	res = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	len = hexa_strlen(s) - 1;
	while ((*s >= '0' && *s <= '9')
		|| (*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F'))
	{
		if ((*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F'))
			conversion = convert_atof(*s);
		else
			conversion = *s - 48;
		res += conversion * pow(16, len--);
		s++;
	}
	return (res * sign);
}
