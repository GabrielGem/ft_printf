/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:56:03 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/15 17:23:12 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isspecifier(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	isflag(char c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}

t_format	initformat(void)
{
	t_format	form;

	form.flags = 0;
	form.precision = 0;
	form.width = 0;
	form.specifier = 0;
	form.ft_specifier = NULL;
	form.index_spec = 0;
	return (form);
}
