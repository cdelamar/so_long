/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:31:49 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 07:56:11 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clone(t_img *img)
{
	int	i;
	int	j;

	j = 0;
	img->f_map = (char **)malloc(sizeof(char *) * img->y);
	if (img->f_map == NULL)
		return ;
	while (j < img->y - 1)
	{
		i = 0;
		img->f_map[j] = (char *)malloc(sizeof(char) * (img->x + 1));
		if (img->f_map[j] == NULL)
		{
			ft_freetab(img->f_map);
			free(img->f_map);
		}
		while (i < img-> x)
		{
			img->f_map[j][i] = img->map[j][i];
			i++;
		}
		img->f_map[j][i] = '\0';
		j++;
	}
	img->f_map[j] = NULL;
}
