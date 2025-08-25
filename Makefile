# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 16:27:23 by gabrgarc          #+#    #+#              #
#    Updated: 2025/08/24 14:45:33 by gabrgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = \
	ft_printf.c \
	ft_aux_chrs.c \
	ft_aux_nbrs.c \
	ft_aux_ptr.c 

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
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
