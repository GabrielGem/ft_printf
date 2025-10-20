# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 16:27:23 by gabrgarc          #+#    #+#              #
#    Updated: 2025/10/18 15:04:10 by gabrgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

SRCS = \
	ft_printf.c \
	ft_aux_chrs.c \
	ft_aux_nbrs.c \
	ft_aux_ptr.c \
	printf_utils.c \
	flags_utils.c \
	padded.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_DIR = libft/

ALL_OBJS = $(OBJS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
