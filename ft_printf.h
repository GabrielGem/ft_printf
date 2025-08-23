/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:41:06 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/21 19:16:16 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(char const *s, ...);

typedef int	(*t_spec)(va_list ap, char flag);

int	ft_aux_char(va_list ap, char c);
int	ft_aux_str(va_list ap, char c);
int	ft_aux_ptr(va_list ap, char c);
int	ft_aux_nbr(va_list ap, char c);
int	ft_aux_hex(va_list ap, char c);

//typedef enum e_specifier
//{
//	ERROR,
//	C,  // caracter
//	S,  // string
//	P,  // pointer address
//	D,  // signed decimal integer
//	I,  // signed decimal integer
//	U,  // unsigned decimal integer
//	X,  // unsigned hexadecimal integer
//	UX, // unsigned hexadecimal integer
//	COUNT
//};

//typedef struct s_format
//{
//	int		minus;
//	int		plus;
//	int		space;
//	int		hashtag;
//	int		zero;
//	int		witdh;
//	int		precision;
//	char	specifier;
//}	t_format;

#endif
