/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:12:53 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/20 13:12:57 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		size;
	char	*my;

	my = ft_itoa(n);
	size = 0;
	size = ft_print_string(my);
	free(my);
	return (size);
}
