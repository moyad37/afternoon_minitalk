/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:41 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/07 18:12:33 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	if (nitems == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (NULL);
	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	p = malloc(nitems * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nitems);
	return (p);
}
/*
int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}
*/