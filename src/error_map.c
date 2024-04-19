/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:43:10 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 07:53:29 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	w_top(t_img *img)
{
	int	i;

	i = 0;
	while (img->map[0][i])
	{
		if (img->map[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	w_bot(t_img *img)
{
	int	i;

	i = 0;
	while (img->map[img->y - 2][i])
	{
		if (img->map[img->y - 2][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	w_sides(t_img *img)
{
	int	j;

	j = 0;
	while (j < img->y - 1)
	{
		if (img->map[j][0] != '1' || img->map[j][img->x - 2] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	is_rectangle(t_img *img)
{
	int	i;
	int	j;
	int	first;

	i = 0;
	j = 0;
	first = 0;
	while (img->map[0][first])
		first++;
	while (j < img->y -1)
	{
		i = 0;
		while (img->map[j][i])
			i++;
		if (i != first)
			return (false);
		j++;
	}
	return (true);
}

bool	closed_map(t_img *img)
{
	if (w_top(img) == true && w_bot(img) == true && w_sides(img) == true)
		return (true);
	else
		return (false);
}

