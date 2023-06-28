/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/11 10:04:08 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*big;
	const char	*small;
	size_t		i;

	if (*to_find == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (*str != '\0' && len > 0)
	{
		big = str;
		small = to_find;
		i = len;
		while (*small != '\0' && *big == *small && i--)
		{
			big++;
			small++;
		}
		if (*small == '\0')
			return ((char *)str);
		str++;
		--len;
	}
	return (NULL);
}
