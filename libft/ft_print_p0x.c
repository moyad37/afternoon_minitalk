/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p0x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:13:05 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/20 13:13:06 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

int	zehler(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_put_px0(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_px0(n / 16);
		ft_put_px0(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_print_px0(unsigned long long n)
{
	int	result;

	if (n == 0)
		return (write(1, "(nil)", 5));
	result = 0;
	result += write(1, "0x", 2);
	if (n != 0)
	{
		ft_put_px0(n);
		result += zehler(n);
	}
	return (result);
}
