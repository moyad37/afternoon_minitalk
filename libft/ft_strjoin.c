/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:43 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
char	*first_part(char *p, char const *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

char	*secund_part(char *p, char const *s2, int i)
{
	int	z;

	z = 0;
	while (s2[z] != '\0')
	{
		p[i] = s2[z];
		i++;
		z++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!p)
		return (NULL);
	p = first_part(p, s1);
	p = secund_part(p, s2, i);
	return (p);
}
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		z;
	char	*my;

	i = 0;
	z = 0;
	my = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!my)
		return (NULL);
	while (s1[i] != '\0')
	{
		my[i] = s1[i];
		i++;
	}
	while (s2[z] != '\0')
	{
		my[i] = s2[z];
		i++;
		z++;
	}
	my[i] = '\0';
	return (my);
}
