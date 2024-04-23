/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:46:37 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/23 00:02:53 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_alloc(int y, int x)
{
	int		i;
	char	**output;

	i = 0;
	output = (char **)malloc(sizeof(char *) * y);
	if (output == NULL)
		return (NULL);
	while (i < y)
	{
		output[i] = (char *)malloc(sizeof(char) * x);
		i++;
	}
	return (output);
}

int	on_destroy(t_img *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->p_xpm);
	mlx_destroy_image(data->mlx, data->f_xpm);
	mlx_destroy_image(data->mlx, data->w_xpm);
	mlx_destroy_image(data->mlx, data->e_xpm);
	mlx_destroy_image(data->mlx, data->c_xpm);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	force_quit(t_img *img)
{
	free_img_map(img);
	on_destroy(img);
	return (0);
}

void	ft_mlx(t_img *img)
{
	mlx_hook(img->win, KeyPress, KeyPressMask, &player_controls, img);
	mlx_hook(img->win, DestroyNotify, StructureNotifyMask, &on_destroy, img);
	mlx_hook(img->win, Expose, ExposureMask, &set_sprite, img);
	mlx_hook(img->win, 17, StructureNotifyMask, &force_quit, img);
	mlx_loop(img->mlx);
}

int	main(int argc, char **argv)
{
	t_img	img;

	img.x = 0;
	img.y = 1;
	img.map = NULL;
	img.f_map = NULL;
	if (valid_args(argc, argv) == true)
	{
		img.fd = open(argv[1], O_RDONLY);
		set_map(&img);
		close(img.fd);
		img.fd2 = open(argv[1], O_RDONLY);
		init_map(&img);
		close(img.fd2);
		if (valid_map(&img) == true)
		{
			img.step = 0;
			img.mlx = mlx_init();
			img.win = mlx_new_window(img.mlx, 1200, 1200, "so_long");
			set_img(&img);
			set_sprite(&img);
			ft_mlx(&img);
		}
	}
}
