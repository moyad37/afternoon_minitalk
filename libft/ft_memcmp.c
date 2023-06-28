/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:42 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:42 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i)))
			return (*(unsigned char *)(str1 + i) - *(unsigned char *)(str2
					+ i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;

	memcpy(str1, "abc", 6);
	memcpy(str2, "ABC", 6);
	ret = ft_memcmp(str1, str2, 5);
	printf("%d", ret);
	return (0);
}
*/
