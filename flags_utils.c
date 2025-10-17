/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:36:26 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/17 19:35:42 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_space(t_format *parameters)
{
	parameters->flags |= SPACE;
	if (parameters->flags & PLUS)
		parameters->flags &= ~SPACE;
}

void	flag_minus(t_format *parameters)
{
	parameters->flags |= MINUS;
	if (parameters->flags & ZERO)
		parameters->flags &= ~ZERO;
}

void	flag_width(t_format *parameters, char c)
{
	if (parameters->flags & DOT)
	{
		parameters->precision = (parameters->width * 10) + c - '0';
		return ;
	}
	parameters->width = (parameters->width * 10) + c - '0';
}

char	*string_width(t_format *parameters, char *str)
{
	int		len;
	int		width;
	char	*new_str;

	len = ft_strlen(str);
	width = parameters->width;
	if (!(width > len))
		return (str);
	new_str = malloc(width + 1);
	new_str[width] = '\0';
	while (len)
		new_str[--width] = str[--len];
	free(str);
	while (width)
		new_str[--width] = ' ';
	return (new_str);
}

int	ft_pad(int size, t_format *parameters)
{
	char	c;
	int		printd;

	printd = size;
	c = ' ';
	if (parameters->flags & ZERO)
		c = '0';
	if (size < 0)
		return (0);
	while (size--)
		ft_putchar_fd(c, 1);
	return (printd);
}

int	sign(t_format *flags)
{
	if ((flags->flags & PLUS))
		ft_putchar_fd('+', 1);
	if ((flags->flags & SPACE))
		ft_putchar_fd(' ', 1);
	return (1);
}

int	prefix(t_format *flags)
{
	if (flags->specifier == 'x')
		ft_putstr_fd("0x", 1);
	if (flags->specifier == 'X')
		ft_putstr_fd("0X", 1);
	return (2);
}

char	*string_realloc(t_format *parameters, char *str)
{
	int		len;
	char	*new_str;

	len = ft_strlen(str) + 1;
	new_str = malloc(len + 1);
	new_str[len] = '\0';
	if (parameters->flags & PLUS)
		new_str[0] = '+';
	if (parameters->flags & SPACE)
		new_str[0] = ' ';
	while (--len)
		new_str[len] = str[len - 1];
	free(str);
	return (new_str);
}
