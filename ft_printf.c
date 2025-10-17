/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:53:22 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/17 10:13:21 by gabrgarc         ###   ########.fr       */
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
	['u'] = ft_aux_unbr,
	['x'] = ft_aux_hex,
	['X'] = ft_aux_hex,
	['%'] = ft_aux_char
	};

	return (map[specifier]);
}

int	handleformat(va_list ap, const char *str, t_format *flags)
{
	int	count;

	count = 0;
	flags->index_spec = parse(str, flags);
	if (!flags->ft_specifier)
		return (-1);
	if (flags->flags & MINUS)
		flags->width *= -1;
	count += flags->ft_specifier(ap, flags);
	if ((flags->flags & MINUS) && ((flags->width * -1) > count))
		count += ft_pad((flags->width * -1) - count, flags);
	return (count);
}

int	parse(const char *str, t_format *parameters)
{
	char		*start;

	start = (char *)str;
	while ((isspecifier(*str) || isflag(*str) || ft_isdigit(*str)) && *str)
	{
		if (*str == '-')
			parameters->flags |= MINUS;
		if (*str == '+')
			parameters->flags |= PLUS;
		if (*str == ' ')
			flag_space(parameters);
		if (*str == '#')
			parameters->flags |= HASHTAG;
		if (*str == '0' && parameters->width == 0 && !(parameters->flags & MINUS))
			parameters->flags |= ZERO;
		if (*str == '.')
			parameters->flags |= DOT;
		if (ft_isdigit(*str))
			flag_width(parameters, *str);
		if (isspecifier(*str))
		{
			parameters->specifier = *str;
			parameters->ft_specifier = spec_map(*str);
			return (str - start + 2);
		}
		str++;
	}
	return (str - start + 2);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	t_format	flags;

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
			flags = initformat();
			count += handleformat(ap, (s + 1), &flags);
			s += flags.index_spec; // save info about where the flags end
		}
	}
	va_end(ap);
	return (count);
}
