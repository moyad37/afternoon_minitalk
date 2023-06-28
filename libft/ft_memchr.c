/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
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

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	//char	*ret;
	// const char str[] = "http://www.tutorialspoint.com";
	// const char ch = '.';
	//ret = ft_memchr(((void *)0), '\0', 12);
	printf("%s", ft_memchr(((void *)0), '\0', 0x12));
	return (0);
}
*/
