/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:54:02 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/22 23:33:27 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_img *img, int y, int x)
{
	if (ft_strchr("0EC", img->f_map[y][x]))
		img->f_map[y][x] *= -1;
	if (ft_strchr("0EC", img->f_map[y + 1][x]))
		flood_fill(img, y + 1, x);
	if (ft_strchr("0EC", img->f_map[y - 1][x]))
		flood_fill(img, y - 1, x);
	if (ft_strchr("0EC", img->f_map[y][x + 1]))
		flood_fill(img, y, x + 1);
	if (ft_strchr("0EC", img->f_map[y][x - 1]))
		flood_fill(img, y, x - 1);
}

bool	reachable_items(t_img *img)
{
	int	x;
	int	y;
	int	j;
	int	i;

	clone(img);
	x = img->player_x;
	y = img->player_y;
	j = 0;
	flood_fill(img, y, x);
	while (j < img->y - 2)
	{
		if (!ft_strchr(img->f_map[j], 'C') && !ft_strchr(img->f_map[j], 'E'))
			j++;
		else
			cant_reach(img);
	}
	i = 0;
	while (img->f_map[i])
	{
		free(img->f_map[i]);
		i++;
	}
	free(img->f_map);
	return (true);
}

void	cant_reach(t_img *img)
{
	ft_freetab(img->f_map);
	free_img_map(img);
	error_message(CANT_REACH);
}
