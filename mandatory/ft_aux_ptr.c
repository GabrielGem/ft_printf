/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:56:01 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/09/11 19:38:31 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_ptr(va_list ap, char flag)
{
	t_uli	ptr;
	char	*symbols;
	char	*address;
	int		count;

	(void)flag;
	symbols = "0123456789abcdef";
	count = 0;
	ptr = va_arg(ap, t_uli);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", STDOUT);
		return (5);
	}
	address = ft_uitoa_base(ptr, symbols);
	ft_putstr_fd("0x", STDOUT);
	ft_putstr_fd(address, STDOUT);
	count = ft_strlen(address) + 2;
	free(address);
	return (count);
}
