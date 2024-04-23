/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:51:42 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/23 18:10:43 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"

# define INVALID_ARGC    	"invalid or wrong number of arguments"
# define FILE_NOT_FOUND  	"file not found or not a .ber file"
# define MAP_IS_EMPTY    	"map is empty"
# define NOT_A_RECTANGLE 	"map is not a rectangle"
# define FD_ERROR        	"cannot open the file"
# define MAP_NOT_CLOSED  	"map is not closed"
# define INCORRECT_VALUE		"incorrect value"
# define GAME_EXIT			"incorrect exit ('E') value"
# define GAME_PLAYER			"incorrect player ('P') value"
# define GAME_COLLECTIBLE	"incorrect collectible ('C') value"
# define CANT_REACH			"cant reach exit or collectible"

# define DESTROY_NOTIFY		17

# define ARROW_UP  				65362
# define ARROW_DOWN  			65364
# define ARROW_LEFT  			65361
# define ARROW_RIGHT 			65363

# define KEY_Q					113
# define KEY_ESCAPE  			65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		5
# endif

typedef struct s_img
{
	int		h;
	int		w;
	int		y;
	int		x;
	int		n_player;
	int		n_collect;
	int		n_exit;
	int		n_x;
	int		n_y;
	int		step;
	int		fd;
	int		fd2;
	int		prev_x;
	int		prev_y;
	int		flood_y;
	int		flood_x;
	int		player_x;
	int		player_y;
	int		collectible;
	int		exit;
	int		player;

	char	**map;
	char	**f_map;
	char	*p_addr;
	char	*f_addr;
	char	*w_addr;
	char	*e_addr;
	char	*c_addr;

	void	*p_xpm;
	void	*f_xpm;
	void	*w_xpm;
	void	*e_xpm;
	void	*c_xpm;

	void	*mlx;
	void	*win;
}	t_img;

void		error_message(char *str);
void		map_settings(t_img *img);
int			ft_putchar(int c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_printf(const char *format, ...);
int			ft_unsigned_nbr(unsigned int n);
int			ft_print_hex(unsigned long num, const char format);
void		ft_put_hex(unsigned long num, const char format);
int			ft_hex_len(unsigned long num);
int			ft_percent(void);
int			print_address(void *ptr);
size_t		ft_strlen(const char *s);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			rev_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t size);
char		*ft_strcpy(char *dest, const char *src);
char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		set_img(t_img *img);
void		which_sprite(t_img *img, int x, int y);
int			set_sprite(t_img *img);
void		back_sprite(t_img *img, int x, int y);
void		object_sprite(t_img *img, int x, int y);
int			set_background(t_img *img);
int			set_object(t_img *img);
char		**map_alloc(int y, int x);
void		set_map(t_img *img);
int			on_destroy(t_img *data);
void		print_map(t_img *img);
bool		valid_shape(char **map);
bool		valid_args(int argc, char **argv);
void		error_message(char *str);
bool		closed_map(t_img *img);
bool		ft_check_format(char **map);
void		adjust_last_character(t_img *img);
bool		is_rectangle(t_img *img);
bool		valid_map(t_img *img);
void		flood_fill(t_img *img, int y, int x);
bool		reachable_items(t_img *img);
void		clone(t_img *img);
int			player_controls(int keysym, t_img *img);
void		player_move(t_img *img, int x, int y);
int			count_exit_collect(t_img *img);
void		set_counter(t_img *img);
int			count_error(t_img *img);
void		free_map(t_img *img);
void		ft_freetab(char **tab);
void		free_img_map(t_img *img);
void		cant_reach(t_img *img);
void		ft_move(t_img *img, int x, int y);
void		init_map(t_img *img);
#endif