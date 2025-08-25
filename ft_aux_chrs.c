/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:36:20 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/24 16:00:02 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_char(va_list ap, char flag)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_aux_str(va_list ap, char flag)
{
	int		count;
	char	*str;

	flag = 0;
	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}
