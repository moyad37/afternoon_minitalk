/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:43 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

//The function takes a single argument
int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
	}
	return (ch);
}
/*
int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, ft_tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_tolower(c));
	c = '9';
	printf("\n%c -> %c", c, ft_tolower(c));
	return (0);
}
*/