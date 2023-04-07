/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:11:44 by ekoljone          #+#    #+#             */
/*   Updated: 2022/11/09 17:06:38 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	ctr;
	int	ctr2;

	ctr = 0;
	ctr2 = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[ctr2] != '\0' && len > 0)
	{
		while (needle[ctr] == haystack[ctr2] && len-- > 0)
		{
			ctr++;
			ctr2++;
			if (needle[ctr] == '\0')
				return ((char *)&haystack[ctr2 - ctr]);
		}
		ctr2 -= ctr;
		len += ctr;
		len--;
		ctr = 0;
		ctr2++;
	}
	return (NULL);
}
