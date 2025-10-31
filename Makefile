# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 16:27:23 by gabrgarc          #+#    #+#              #
#    Updated: 2025/10/30 16:46:25 by gabrgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

MANDATORY = mandatory/
BONUS_DIR = bonus/
OBJDIR = objdir/
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

SRCS = \
	ft_printf.c \
	ft_aux_chrs.c \
	ft_aux_nbrs.c \
	ft_aux_ptr.c

SRCS_BONUS = \
	ft_printf_bonus.c \
	ft_aux_chrs_bonus.c \
	ft_aux_nbrs_bonus.c \
	ft_aux_ptr_bonus.c \
	printf_utils_bonus.c \
	flags_utils_bonus.c \
	padded_bonus.c

OBJS_NAMES = $(SRCS:.c=.o)
OBJS_BONUS_NAMES = $(SRCS_BONUS:.c=.o)

OBJS := $(addprefix $(OBJDIR), $(OBJS_NAMES))
OBJS_BONUS := $(addprefix $(OBJDIR), $(OBJS_BONUS_NAMES))

SRCS := $(addprefix $(MANDATORY), $(SRCS))
SRCS_BONUS := $(addprefix $(BONUS_DIR), $(SRCS_BONUS))

ifeq ($(findstring bonus,$(MAKECMDGOALS)),bonus)
	OBJS = $(OBJS_BONUS)
	SRCS = $(SRCS_BONUS)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	rm -f $(NAME)
	cp -p $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(OBJDIR)%.o: $(MANDATORY)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -Imandatory -c $< -o $@

$(OBJDIR)%.o: $(BONUS_DIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -Ibonus -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
