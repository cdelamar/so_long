# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 21:54:20 by cdelamar          #+#    #+#              #
#    Updated: 2024/05/13 17:12:30 by cdelamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = lib/libft.a
LIBMLXLINUX = lib/libmlx_Linux.a

CC = cc

CFLAGS =	-g -Wall -Wextra -Werror \
			-Iinclude

LFLAGS =	-Llib \
			-lft -lmlx_Linux -lX11 -lXext

SRC_DIR = src/
OBJ_DIR = obj/
FILES =	main \
		control \
		error_args \
		error_map \
		free \
		ft_gnl \
		gnl \
		init_map \
		init_sprite \
		output \
		clone \
		flood_fill \
		ft_hexa \
		ft_put \
		ft_ptr \
		ft_printf \
		ft_custom


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C lib

re: fclean all

$(NAME): $(OBJS) $(LIBFT) $(LIBMLXLINUX)
	@echo "\033[32m✔ Compilating sources files...\033[37m"
	@$(CC) -o $@ $(OBJS) $(LFLAGS)
	@echo "\033[32m✔ Executable created.\033[37m"

$(LIBFT):
	@make -C lib

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus