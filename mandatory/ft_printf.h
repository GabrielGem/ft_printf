/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:41:06 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/27 15:31:24 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef int					(*t_spec)(va_list ap, char flag);
typedef unsigned long int	t_uli;

enum e_defaultf
{
	STDOUT = 1
};

int	ft_printf(char const *s, ...);
int	ft_aux_char(va_list ap, char flag);
int	ft_aux_str(va_list ap, char flag);
int	ft_aux_ptr(va_list ap, char flag);
int	ft_aux_nbr(va_list ap, char flag);
int	ft_aux_unbr(va_list ap, char flag);
int	ft_aux_hex(va_list ap, char flag);

#endif
