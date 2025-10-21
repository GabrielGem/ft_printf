/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:42:18 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/20 20:48:01 by gabrgarc         ###   ########.fr       */
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

int	sign(t_format *format, int num)
{
	if ((format->flags & PLUS) && num >= 0)
		ft_putchar_fd('+', 1);
	if ((format->flags & SPACE) && num >= 0)
		ft_putchar_fd(' ', 1);
	if (num < 0)
		ft_putchar_fd('-', 1);
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

char	*precision(t_format *format, char *num)
{
	int		len;
	int		i;
	int		j;
	int		lending_zeros;
	char	*new_str;

	if (num[0] == '0' && format->precision == 0) // 0 print nothing
	{
		free(num);
		new_str = ft_calloc(1, 1);
		return (new_str);
	}
	len = ft_strlen(num);
	lending_zeros = format->precision - len;
	if (format->precision > len)
		new_str = malloc(sizeof(char) * format->precision + 1);
	i = 0;
	while (lending_zeros - i)
		new_str[i++] = '0';
	j = 0;
	while (len - j)
		new_str[i++] = num[j++];
	free(num);
	return (new_str);
}
