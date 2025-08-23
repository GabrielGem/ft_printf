/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:57:21 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/21 19:17:34 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_char(va_list ap, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else
		ft_putchar_fd('%', 1);
	return (1);
}
