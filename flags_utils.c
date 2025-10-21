/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:36:26 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/20 17:26:01 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_space(t_format *parameters)
{
	parameters->flags |= SPACE;
	if (parameters->flags & PLUS)
		parameters->flags &= ~SPACE;
}

void	flag_minus(t_format *parameters)
{
	parameters->flags |= MINUS;
	if (parameters->flags & ZERO)
		parameters->flags &= ~ZERO;
}

void	flag_width(t_format *parameters, char c)
{
	if (parameters->flags & DOT)
	{
		parameters->precision = (parameters->precision * 10) + c - '0';
		return ;
	}
	parameters->width = (parameters->width * 10) + c - '0';
}
