/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:29 by ekoljone          #+#    #+#             */
/*   Updated: 2022/11/09 12:11:58 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a > -1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		a--;
	}
	return (NULL);
}
