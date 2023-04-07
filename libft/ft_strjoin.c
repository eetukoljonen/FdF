/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:14:50 by ekoljone          #+#    #+#             */
/*   Updated: 2022/11/07 14:32:20 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*ptr;
	int		ctr;

	ctr = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (*s1 != 0)
	{
		ptr[ctr] = *s1;
		ctr++;
		s1++;
	}
	while (*s2 != 0)
	{
		ptr[ctr] = *s2;
		ctr++;
		s2++;
	}
	ptr[ctr] = 0;
	return (ptr);
}
