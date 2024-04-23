/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:39:35 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/23 00:04:32 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

bool	valid_args(int argc, char **argv)
{
	if (argc != 2)
		error_message(INVALID_ARGC);
	if (rev_strncmp(argv[1], ".ber", 4) != 0)
		error_message(FILE_NOT_FOUND);
	return (true);
}

void	set_counter(t_img *img)
{
	img->n_x = 0;
	img->n_y = 0;
	img->n_collect = 0;
	img->n_player = 0;
	img->n_exit = 0;
}

int	count_exit_collect(t_img *img)
{
	set_counter(img);
	while (img->n_y < img->y - 1)
	{
		img->n_x = 0;
		while (img->map[img->n_y][img->n_x])
		{
			if (img->map[img->n_y][img->n_x] == 'C')
				img->n_collect++;
			if (img->map[img->n_y][img->n_x] == 'E')
				img->n_exit++;
			if (img->map[img->n_y][img->n_x] == 'P')
				img->n_player++;
			img->n_x++;
		}
		img->n_y++;
	}
	return (0);
}

int	count_error(t_img *img)
{
	if (img->n_exit != 1)
	{
		free_img_map(img);
		error_message(GAME_EXIT);
	}
	if (img->n_player != 1)
	{
		free_img_map(img);
		error_message(GAME_PLAYER);
	}
	if (img->n_collect < 1)
	{
		free_img_map(img);
		error_message(GAME_COLLECTIBLE);
	}
	return (0);
}
