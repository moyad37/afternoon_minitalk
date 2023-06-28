/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:12:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/20 13:12:45 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	counter(unsigned int n)
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

void	ft_put_hex(unsigned int n, const char x)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, x);
		ft_put_hex(n % 16, x);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + 48), 1);
		else
		{
			if (x == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (x == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char x)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, x);
	return (counter(n));
}
