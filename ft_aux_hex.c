/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:51:44 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/21 19:16:52 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_hex(va_list ap, char c)
{
	char	*result;
	char	*symbols;
	int		count;

	if (c == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	ft_putstr_fd(result, 1);
	count = ft_strlen(result);
	return (count);
}
