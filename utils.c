/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:42:34 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/29 14:39:42 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_arg_digit(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "error in ARGS it have to be 3\n", 30);
		return (0);
	}
	else if (check_arg_digit(av[1]) == 0)
	{
		write(2, "check pid it have to contain just numbers\n", 42);
		return (0);
	}
	else
		return (1);
}
