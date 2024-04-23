/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:18:55 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/22 23:10:59 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_sprite(t_img *img, int x, int y)
{
	char	value;

	value = img->map[y][x];
	if (value == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->f_xpm, x * 60, y * 60);
	else if (value == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->w_xpm, x * 60, y * 60);
}

void	object_sprite(t_img *img, int x, int y)
{
	char	value;
	int		p_x;
	int		p_y;

	p_x = x * 60;
	p_y = y * 60;
	value = img->map[y][x];
	if (value == 'P')
		mlx_put_image_to_window (img->mlx, img->win, img->p_xpm, p_x, p_y);
	else if (value == 'C')
		mlx_put_image_to_window (img->mlx, img->win, img->c_xpm, p_x, p_y);
	else if (value == 'E')
		mlx_put_image_to_window (img->mlx, img->win, img->e_xpm, p_x, p_y);
}

int	set_background(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->y - 1)
	{
		x = 0;
		while (x < img->x - 1)
		{
			back_sprite(img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	set_object(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->y - 1)
	{
		x = 0;
		while (x < img->x - 1)
		{
			object_sprite(img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	set_sprite(t_img *img)
{
	set_background(img);
	set_object(img);
	return (0);
}
