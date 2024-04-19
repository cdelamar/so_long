/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:57:30 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 22:32:37 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	free_img_map(t_img *img)
{
	int	i;

	i = 0;
	while (i < ((img->y) - 1))
	{
		if(img->map[i])
			free(img->map[i]);
		i++;
	}
	free(img->map);
}
