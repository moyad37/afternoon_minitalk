/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:41 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:41 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	int	c;

    c = '5';
    printf("This is 1 if digit and 0 if not, and your arg is ---> %d",
		ft_isdigit(c));
}
*/