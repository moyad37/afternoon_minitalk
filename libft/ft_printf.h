/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:19:16 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/20 13:19:18 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
int		ft_print_char(int c);
int		ft_print_hex(unsigned int n, const char x);
int		ft_print_px0(unsigned long long n);
int		ft_print_percent(void);
int		ft_print_string(char *str);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printf(const char *str, ...);

#endif
