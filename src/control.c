/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:36:44 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 22:35:13 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_controls(int keysym, t_img *img)
{
	if (keysym == KEY_ESCAPE)
	{
		ft_freetab(img->map);
		on_destroy(img);
	}
	if (keysym == ARROW_UP)
		player_move(img, img->player_y - 1, img->player_x);
	if (keysym == ARROW_DOWN)
		player_move(img, img->player_y + 1, img->player_x);
	if (keysym == ARROW_LEFT)
		player_move(img, img->player_y, img->player_x - 1);
	if (keysym == ARROW_RIGHT)
		player_move(img, img->player_y, img->player_x + 1);
	return (0);
}

void	player_move(t_img *img, int y, int x)
{
	img->prev_x = img->player_x;
	img->prev_y = img->player_y;

	if (img->map[y][x] == '0')
	{
		ft_move(img, x, y);
		set_object(img);
	}
	if (img->map[y][x] == 'C')
	{
		ft_move(img, x, y);
		img->n_collect--;
		set_object(img);
	}
	if (img->map[y][x] == 'E' && img->n_collect == 0)
	{
		ft_move(img, x, y);
		set_object(img);
		free_img_map(img);
		on_destroy(img);
	}
}

void	ft_move(t_img *img, int x, int y)
{
	img->player_x = x;
	img->player_y = y;
	img->map[y][x] = 'P';
	img->map[img->prev_y][img->prev_x] = '0';
	mlx_put_image_to_window(img->mlx, img->win, img->f_xpm, img->prev_x * 60, img->prev_y * 60);
	img->step++;
	ft_printf("step : %d\n", img->step);
}
void	set_img(t_img *i)
{
	i->h = 60;
	i->w = 60;
	i->f_addr = "sprites/floor.xpm";
	i->w_addr = "sprites/wall.xpm";
	i->p_addr = "sprites/player.xpm";
	i->c_addr = "sprites/collectible.xpm";
	i->e_addr = "sprites/exit.xpm";
	i->f_xpm = mlx_xpm_file_to_image(i->mlx, i->f_addr, &(i->h), &(i->w));
	i->w_xpm = mlx_xpm_file_to_image(i->mlx, i->w_addr, &(i->h), &(i->w));
	i->p_xpm = mlx_xpm_file_to_image(i->mlx, i->p_addr, &(i->h), &(i->w));
	i->c_xpm = mlx_xpm_file_to_image(i->mlx, i->c_addr, &(i->h), &(i->w));
	i->e_xpm = mlx_xpm_file_to_image(i->mlx, i->e_addr, &(i->h), &(i->w));
}

