/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:56:01 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/17 10:02:01 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_ptr(va_list ap, t_format *flags)
{
	char				*address;
	int					count;
	unsigned long int	ptr;

	count = 0;
	ptr = va_arg(ap, unsigned long int);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = ft_uitoa_base(ptr, "0123456789abcdef");
	count = ft_strlen(address) + 2;
	if (flags->width > count)
		count += ft_pad(flags->width - count, flags);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(address, 1);
	free(address);
	return (count);
}
