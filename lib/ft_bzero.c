/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:11:26 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/19 16:37:07 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	tab[60] = "test before ft_bzero";
	printf ("%s\n", tab);
	ft_bzero(tab, 60);
	printf ("after ft_bzero :\n");
	printf ("%s\n", tab);

	char	tabtest[60] = "test before bzero";
	printf ("%s\n", tabtest);
	bzero(tabtest, 60);
	printf ("after bzero :\n");
	printf ("%s\n", tabtest);
	return (0);
}*/