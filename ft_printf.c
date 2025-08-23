/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:53:22 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/22 14:01:25 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	spec_map(int specifier)
{
	static t_spec	map[127] = {
	['c'] = ft_aux_char,
	['s'] = ft_aux_str,
	['p'] = ft_aux_ptr,
	['d'] = ft_aux_nbr,
	['i'] = ft_aux_nbr,
	['u'] = ft_aux_nbr,
	['x'] = ft_aux_hex,
	['X'] = ft_aux_hex,
	['%'] = ft_aux_char
	};

	return (map[specifier]);
}

int	handleflags(va_list ap, char specifier)
{
	int		count;
	t_spec	ft;

	count = 0;
	ft = spec_map(specifier);
	count += ft(ap, specifier);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (!(*s == '%'))
		{
			count += write(1, s, 1);
			s++;
		}
		else
		{
			count += handleflags(ap, *(s + 1));
			s += 2;
		}
	}
	va_end(ap);
	return (count);
}
