/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:42:18 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/18 16:31:15 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	sign(t_format *format)
{
	if (format->flags & PLUS)
		ft_putchar_fd('+', 1);
	if (format->flags & SPACE)
		ft_putchar_fd(' ', 1);
	return (1);
}

int	prefix(t_format *format)
{
	if (format->specifier == 'x')
		ft_putstr_fd("0x", 1);
	if (format->specifier == 'X')
		ft_putstr_fd("0X", 1);
	return (2);
}
