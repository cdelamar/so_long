/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:46:37 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 23:17:42 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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


int	test(void) // int keysym ?
{
	//sleep();
	return (0);
}

void	ft_mlx(t_img *img)
{
	mlx_hook(img->win, KeyPress, KeyPressMask, &player_controls, img);
	mlx_hook(img->win, DestroyNotify, StructureNotifyMask, &on_destroy, img);
	mlx_hook(img->win, Expose, ExposureMask, &set_sprite, img);
	mlx_loop(img->mlx);
}

int main(int argc, char **argv)
{
	t_img	img;

	img.x = 0;
	img.y = 1;
	img.map = NULL;
	img.f_map = NULL;
	img.fd = open(argv[1], O_RDONLY);
	if (valid_args(argc, argv, &img) == true)
	{

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