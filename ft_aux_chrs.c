/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:36:20 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/17 10:01:54 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_char(va_list ap, t_format *flags)
{
	char	c;
	int		count;

	c = '%';
	if (flags->specifier == 'c')
		c = va_arg(ap, int);
	count = 1;
	if (flags->width > 1 && c != '%')
		count += ft_pad(flags->width - 1, flags);
	ft_putchar_fd(c, 1);
	return (count);
}

int	ft_aux_str(va_list ap, t_format *flags)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	count = ft_strlen(str);
	if (flags->width > count)
		count += ft_pad(flags->width - count, flags);
	ft_putstr_fd(str, 1);
	return (count);
}
