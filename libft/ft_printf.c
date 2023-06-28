/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:15:50 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/20 13:15:52 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_print_char(va_arg(args, int));
	else if (c == 's')
		result += ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		result += ft_print_px0(va_arg(args, unsigned long long));
	else if (c == 'd')
		result += ft_print_nbr(va_arg(args, int));
	else if (c == 'i')
		result += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		result += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		result += write(1, "%", 1);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	va_start(args, str);
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_format(args, str[i + 1]);
			i++;
		}
		else
			result += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
/*
int	main(void)
{
    ft_printf(" %c \n %s \n %p \n %d \n %i \n %u \n %x \n %X \n %%", 'c',
		"Hallo", 0, 534, 534, 534, -5, -5);
	// ft_printf("%s", "rt");
	// ft_printf("%p" , 5344);
    return (0);
}
*/