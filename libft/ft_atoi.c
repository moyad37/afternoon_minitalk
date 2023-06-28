/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:41 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:41 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				p_m;

	i = 0;
	p_m = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		p_m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0 && p_m == -1 && nb)
			return (0);
		if (nb < 0 && p_m == 1)
			return (-1);
		i++;
	}
	return (nb * p_m);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi(" +1234ab567"));
	printf("%d\n", ft_atoi(" 	---+234\rab567"));
	printf("%d\n", ft_atoi(" \n\t\r\v\f---+--2147483648ab567"));
}
*/