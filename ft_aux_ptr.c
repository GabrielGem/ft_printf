/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:56:01 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/22 20:24:16 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_ptr(va_list ap, char c)
{
	char				*symbols;
	char				*address;
	int					count;
	unsigned long int	ptr;

	c = 0;
	symbols = "0123456789abcdef";
	count = 0;
	ptr = va_arg(ap, unsigned long int);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = ft_uitoa_base(ptr, symbols);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(address, 1);
	count = ft_strlen(address) + 2;
	free(address);
	return (count);
}
