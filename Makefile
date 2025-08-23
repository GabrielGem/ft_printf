# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 16:27:23 by gabrgarc          #+#    #+#              #
#    Updated: 2025/08/21 19:14:58 by gabrgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -I./libft/libft.h

SRCS = \
	ft_printf.c \
	ft_aux_char.c \
	ft_aux_hex.c \
	ft_aux_nbr.c \
	ft_aux_ptr.c \
	ft_aux_str.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

ALL_OBJS = $(OBJS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT) all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT) fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
