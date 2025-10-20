/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:11:59 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/18 16:43:27 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_nbr(va_list ap, t_format *format)
{
	int		count;
	int		num;
	char	*result;

	count = 0;
	num = va_arg(ap, int);
	result = ft_itoa(num);
	count = ft_strlen(result);
	if (((format->flags & PLUS) || (format->flags & SPACE)) && num > 0)
		count += sign(format);
	if (format->width > count)
		count += ft_pad(format->width - count, format);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_unbr(va_list ap, t_format *format)
{
	int		count;
	char	*result;

	count = 0;
	result = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789");
	count = ft_strlen(result);
	if (format->width > count)
		count += ft_pad((format->width - count), format);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_hex(va_list ap, t_format *format)
{
	char	*result;
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (format->specifier == 'X')
		symbols = "0123456789ABCDEF";
	result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	count = ft_strlen(result);
	if (format->flags & HASHTAG)
		count += prefix(format);
	if ((format->flags & HASHTAG) && format->width > count + 2)
		count += ft_pad(format->width - count, format);
	if (!(format->flags & HASHTAG) && format->width > count)
		count += ft_pad((format->width - count), format);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}
