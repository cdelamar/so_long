/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:54:02 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/13 17:57:39 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
check if replace
(ft_strchr("0EC"~
to
(ft_strchr("0C"~

check if replace
if (!ft_strchr(img->f_map[j], 'C') && !ft_strchr(img->f_map[j], 'E'))
to
if (!ft_strchr(img->f_map[j], 'C'))
*/

void	flood_fill_c(t_img *img, int y, int x)
{
	if (ft_strchr("0C", img->f_map[y][x]))
		img->f_map[y][x] *= -1;
	if (ft_strchr("0C", img->f_map[y + 1][x]))
		flood_fill_c(img, y + 1, x);
	if (ft_strchr("0C", img->f_map[y - 1][x]))
		flood_fill_c(img, y - 1, x);
	if (ft_strchr("0C", img->f_map[y][x + 1]))
		flood_fill_c(img, y, x + 1);
	if (ft_strchr("0C", img->f_map[y][x - 1]))
		flood_fill_c(img, y, x - 1);
}

void	flood_fill_e(t_img *img, int y, int x)
{
	if (ft_strchr("0EC", img->f_map[y][x]))
		img->f_map[y][x] *= -1;
	if (ft_strchr("0EC", img->f_map[y + 1][x]))
		flood_fill_e(img, y + 1, x);
	if (ft_strchr("0EC", img->f_map[y - 1][x]))
		flood_fill_e(img, y - 1, x);
	if (ft_strchr("0EC", img->f_map[y][x + 1]))
		flood_fill_e(img, y, x + 1);
	if (ft_strchr("0EC", img->f_map[y][x - 1]))
		flood_fill_e(img, y, x - 1);
}

void	back_to_positive(t_img *img)
{
	int	i;
	int	j;

	j = -1;
	while (img->f_map[++j])
	{
		i = -1;
		while (img->f_map[j][++i])
		{
			if (img->f_map[j][i] < 0)
				img->f_map[j][i] *= -1;
		}
	}
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
	j = -1;
	flood_fill_c(img, y, x);
	while (++j < img->y - 2)
		if (ft_strchr(img->f_map[j], 'C'))
			cant_reach(img);
	back_to_positive(img);
	flood_fill_e(img, y, x);
	j = 0;
	while (j < img->y - 2)
		if (ft_strchr(img->f_map[j++], 'E'))
			cant_reach(img);
	i = 0;
	while (img->f_map[i])
		free(img->f_map[i++]);
	free(img->f_map);
	return (true);
}

void	cant_reach(t_img *img)
{
	ft_freetab(img->f_map);
	free_img_map(img);
	error_message(CANT_REACH);
}
