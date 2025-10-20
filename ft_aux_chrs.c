/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:36:20 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/18 15:22:40 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_char(va_list ap, t_format *format)
{
	char	c;
	int		count;

	c = '%';
	if (format->specifier == 'c')
		c = va_arg(ap, int);
	count = 1;
	if (format->width > 1 && c != '%')
		count += ft_pad(format->width - 1, format);
	ft_putchar_fd(c, 1);
	return (count);
}

int	ft_aux_str(va_list ap, t_format *format)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	count = ft_strlen(str);
	if (format->width > count)
		count += ft_pad(format->width - count, format);
	ft_putstr_fd(str, 1);
	return (count);
}
