/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:11:59 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/17 17:11:48 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_nbr(va_list ap, t_format *flags)
{
	int		count;
	int		num;
	char	*result;

	count = 0;
	num = va_arg(ap, int);
	result = ft_itoa(num);
	count = ft_strlen(result);
	if (((flags->flags & PLUS) || (flags->flags & SPACE)) && num > 0)
		count += sign(flags);
	if (flags->width > count)
		count += ft_pad(flags->width - count, flags);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_unbr(va_list ap, t_format *flags)
{
	int		count;
	char	*result;

	count = 0;
	result = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789");
	count = ft_strlen(result);
	if (flags->width > count)
		count += ft_pad((flags->width - count), flags);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_hex(va_list ap, t_format *flags)
{
	char	*result;
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (flags->specifier == 'X')
		symbols = "0123456789ABCDEF";
	result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	count = ft_strlen(result);
	if (flags->flags & HASHTAG)
		count += prefix(flags);
	if ((flags->flags & HASHTAG) && flags->width > count + 2)
		count += ft_pad(flags->width - count, flags);
	if (!(flags->flags & HASHTAG) && flags->width > count)
		count += ft_pad((flags->width - count), flags);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}
