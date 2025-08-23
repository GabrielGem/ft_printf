/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:24:37 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/22 14:13:49 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
