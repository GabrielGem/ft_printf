/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:11:59 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/21 19:17:45 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_nbr(va_list ap, char c)
{
	char	*result;
	char	*symbols;
	int		count;

	count = 0;
	result = "";
	symbols = "0123456789";
	if (c == 'd' || c == 'i')
		result = ft_itoa_base(va_arg(ap, int), symbols);
	else
		result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	ft_putstr_fd(result, 1);
	count = ft_strlen(result);
	return (count);
}
