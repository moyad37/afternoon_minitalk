/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
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

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (!*str++)
			return (NULL);
	return ((char *)str);
}

/*
int	main(void)
{
	const char	*str;
	int			ch;
	char		*ret;

	str = "teste";
	ch = 'e';
	ret = ft_strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}
*/
