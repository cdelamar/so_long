# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 15:13:39 by cdelamar          #+#    #+#              #
#    Updated: 2024/05/13 17:04:38 by cdelamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_atoi \
	ft_bzero \
	ft_itoa \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_tolower \
	ft_toupper \
	ft_split \
	ft_strtrim \
	ft_strjoin \
	ft_strlcpy \
	ft_strdup \
	ft_strnstr \
	ft_strlcat \
	ft_strrchr \
	ft_strchr \
	ft_substr \
	ft_memcpy \
	ft_strmapi \
	ft_striteri \
	ft_strncmp \
	ft_strlen \
	ft_memcpy \
	ft_memchr \
	ft_memmove \
	ft_memset \
	ft_calloc \
	ft_memcmp \
	ft_putchar_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_putendl_fd

BONUS =	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus : $(OBJS_BONUS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
