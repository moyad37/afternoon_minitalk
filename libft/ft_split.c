/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:42 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:42 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_c(char const *s, char c);
static char	**put_array(char **my_array, int counter, char const *s, char c);
static char	*get_str(char const *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**my_array;
	int		counter;

	if (!s)
		return (NULL);
	counter = count_c(s, c);
	my_array = malloc(sizeof(char *) * (counter + 1));
	if (!my_array)
		return (NULL);
	my_array = put_array(my_array, counter, s, c);
	return (my_array);
}

int	count_c(char const *s, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[z])
	{
		if (s[z] == c && s[z + 1] != c && s[z + 1] != '\0')
			i++;
		if (s[z] != c && i == 0)
			i++;
		z++;
	}
	return (i);
}

static char	**put_array(char **my_array, int counter, char const *s, char c)
{
	int		i;
	size_t	z;
	char	*tmp;

	i = -1;
	while (++i < counter)
	{
		tmp = get_str(s, c);
		my_array[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (!my_array[i])
			return (NULL);
		z = -1;
		while (++z < ft_strlen(tmp))
			my_array[i][z] = tmp[z];
		my_array[i][z] = '\0';
		if (!(i == counter - 1))
		{
			while (*s == c)
				s++;
			s += ft_strlen(tmp) + 1;
		}
		free(tmp);
	}
	my_array[i] = NULL;
	return (my_array);
}

static char	*get_str(char const *s, char c)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	while (*s == c)
		s++;
	tmp = ft_strchr(s, c);
	if (!tmp)
		len = ft_strlen(s);
	else
		len = tmp - s;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*months;
	char	**tokens;
		int i;

	months = ",,,,   JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	printf("months=[%s]\n\n", months);
	tokens = ft_split(months, ',');
	if (tokens)
	{
		for (i = 0; *(tokens + i); i++)
		{
			printf("month=[%s]\n", *(tokens + i));
			free(*(tokens + i));
		}
		printf("\n");
		free(tokens);
	}
	return (0);
}
*/