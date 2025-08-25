/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:11:59 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/24 16:21:51 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_nbr(va_list ap, char flag)
{
	int		count;
	char	*result;
	char	*symbols;

	(void)flag;
	count = 0;
	symbols = "0123456789";
	result = ft_itoa_base(va_arg(ap, int), symbols);
	ft_putstr_fd(result, 1);
	count = ft_strlen(result);
	free(result);
	return (count);
}

int	ft_aux_unbr(va_list ap, char flag)
{
	int		count;
	char	*result;
	char	*symbols;

	(void)flag;
	count = 0;
	symbols = "0123456789";
	result = ft_uitoa_base(va_arg(ap, unsigned int), symbols);
	ft_putstr_fd(result, 1);
	count = ft_strlen(result);
	free(result);
	return (count);
}

int	ft_aux_hex(va_list ap, char flag)
{
	char	*result;
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (flag == 'X')
		symbols = "0123456789ABCDEF";
	result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	ft_putstr_fd(result, 1);
	count = ft_strlen(result);
	free(result);
	return (count);
}
