/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:46:31 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/23 00:36:42 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_img *img)
{
	char	*line;

	line = get_next_line(img->fd);
	if (!line)
		error_message(MAP_IS_EMPTY);
	img->y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(img->fd);
		img->y++;
	}
	free(line);
	img->map = (char **)malloc(sizeof(char *) * (img->y - 1));
}

void	init_map(t_img *img)
{
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(img->fd2);
	if (!line)
		error_message(MAP_IS_EMPTY);
	img->x = ft_strlen(line);
	if (img->map == NULL)
		return ;
	img->map[y] = ft_strdup(line);
	if (img->x > 0 && line[img->x - 1] == '\n')
		img->map[y][img->x - 1] = '\0';
	free(line);
	while (y < img-> y)
	{
		line = get_next_line(img->fd2);
		if (!line)
			break ;
		if ((int)ft_strlen(line) >= img->x && line[img->x - 1] == '\n')
			line[img->x - 1] = '\0';
		y++;
		img->map[y] = ft_strdup(line);
		free(line);
	}
}

void	adjust_last_character(t_img *img)
{
	int	i;
	int	len;

	i = 0;
	while (i < img->y)
	{
		len = ft_strlen(img->map[i]);
		if (len > 0 && img->map[i][len - 1] == '\n')
			img->map[i][len - 1] = '\0';
		i++;
	}
}

bool	correct_value(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < img->y - 1)
	{
		i = 0;
		while (img->map[j][i])
		{
			if (!ft_strchr("01PCE", img->map[j][i]))
				return (false);
			else if (img->map[j][i] == 'P')
			{
				img->player_y = j;
				img->player_x = i;
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool	valid_map(t_img *img)
{
	if (is_rectangle(img) == false)
	{
		free_img_map(img);
		error_message(NOT_A_RECTANGLE);
	}
	if (closed_map(img) == false)
	{
		free_img_map(img);
		error_message(MAP_NOT_CLOSED);
	}
	if (correct_value(img) == false)
	{
		free_img_map(img);
		error_message(INCORRECT_VALUE);
	}
	count_exit_collect(img);
	count_error (img);
	if (reachable_items(img) == false)
	{
		free_img_map(img);
		ft_freetab(img->f_map);
		on_destroy(img);
		error_message(CANT_REACH);
	}
	return (true);
}
