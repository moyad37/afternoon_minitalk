/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:42 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:42 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*f;

	f = b;
	while (len > 0)
	{
		*f = (unsigned char)c;
		len--;
		f++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[50];

	strcpy(str, "Hello I am MOOOOO");
	puts(str);
	ft_memset(str, 'l', 5);
	puts(str);
	return (0);
}
*/