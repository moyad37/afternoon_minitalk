/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/14 12:16:43 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*my;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	my = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!my)
		return (NULL);
	while (s[i] != '\0')
	{
		my[i] = (*f)(i, s[i]);
		i++;
	}
	my[i] = '\0';
	return (my);
}
