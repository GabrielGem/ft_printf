/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:37:25 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/18 16:25:53 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

typedef unsigned int	t_ui;

void	normal_flags(char c, char *str, char *ptr, int num, t_ui unbr)
{
	int	i, j;

	printf("\n---character---\n");
	i = ft_printf("[%c]\t", c);
	printf("my: %d\n", i);
	j = printf("[%c]\t", c);
	printf("or: %d\n", j);

	printf("\n---string---\n");
	i = ft_printf("[%s]\t", str);
	printf("my: %d\n", i);
	j = printf("[%s]\t", str);
	printf("or: %d\n", j);

	printf("\n---pointer---\n");
	i = ft_printf("[%p]\t", ptr);
	printf("my: %d\n", i);
	j = printf("[%p]\t", ptr);
	printf("or: %d\n", j);

	i = ft_printf("[%p]\t", NULL);
	printf("my: %d\n", i);
	j = printf("[%p]\t", NULL);
	printf("or: %d\n", j);

	printf("\n---decimal---\n");
	i = ft_printf("[%d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%d]\t", num);
	printf("or: %d\n", j);

	printf("\n---unsigned---\n");
	i = ft_printf("[%u]\t", unbr);
	printf("my: %d\n", i);
	j = printf("[%u]\t", unbr);
	printf("or: %d\n", j);

	printf("\n---hexadecimal---\n");
	i = ft_printf("[%X][%x]\t", num, num);
	printf("my: %d\n", i);
	j = printf("[%X][%x]\t", num, num);
	printf("or: %d\n", j);

	printf("\n---percent---\n");
	i = ft_printf("[%%]\t");
	printf("my: %d\n", i);
	j = printf("[%%]\t");
	printf("or: %d\n", j);
}

void	width(char c, char *str, char *ptr, int num, t_ui unbr)
{
	int	i, j;

	printf("\n---width---\n");

	i = ft_printf("[%10c]\t", c);
	printf("my: %d\n", i);
	j = printf("[%10c]\t", c);
	printf("or: %d\n", j);

	i = ft_printf("[%10s]\t", str);
	printf("my: %d\n", i);
	j = printf("[%10s]\t", str);
	printf("or: %d\n", j);

	i = ft_printf("[%20p]\t", ptr);
	printf("my: %d\n", i);
	j = printf("[%20p]\t", ptr);
	printf("or: %d\n", j);

	i = ft_printf("[%20p]\t", NULL);
	printf("my: %d\n", i);
	j = printf("[%20p]\t", NULL);
	printf("or: %d\n", j);

	i = ft_printf("[%10d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%10d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%20u]\t", unbr);
	printf("my: %d\n", i);
	j = printf("[%20u]\t", unbr);
	printf("or: %d\n", j);

	i = ft_printf("[%10x][%10X]\t", unbr, unbr);
	printf("my: %d\n", i);
	j = printf("[%10x][%10X]\t", unbr, unbr);
	printf("or: %d\n", j);
}

void	minus(char c, char *str, char *ptr, int num, t_ui unbr)
{
	int	i, j;

	printf("\n---minus---\n");

	i = ft_printf("[%-10c]\t", c);
	printf("my: %d\n", i);
	j = printf("[%-10c]\t", c);
	printf("or: %d\n", j);

	i = ft_printf("[%-10s]\t", str);
	printf("my: %d\n", i);
	j = printf("[%-10s]\t", str);
	printf("or: %d\n", j);

	i = ft_printf("[%-20p]\t", ptr);
	printf("my: %d\n", i);
	j = printf("[%-20p]\t", ptr);
	printf("or: %d\n", j);

	i = ft_printf("[%-20p]\t", NULL);
	printf("my: %d\n", i);
	j = printf("[%-20p]\t", NULL);
	printf("or: %d\n", j);

	i = ft_printf("[%-10d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%-10d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%-20u]\t", unbr);
	printf("my: %d\n", i);
	j = printf("[%-20u]\t", unbr);
	printf("or: %d\n", j);

	i = ft_printf("[%-10x][%-10X]\t", unbr, unbr);
	printf("my: %d\n", i);
	j = printf("[%-10x][%-10X]\t", unbr, unbr);
	printf("or: %d\n", j);
}

void	zero(int num, t_ui unbr)
{
	int		i, j;

	printf("\n---zero---\n");

	i = ft_printf("[%010d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%010d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%020u]\t", unbr);
	printf("my: %d\n", i);
	j = printf("[%020u]\t", unbr);
	printf("or: %d\n", j);

	i = ft_printf("[%010x][%010X]\t", unbr, unbr);
	printf("my: %d\n", i);
	j = printf("[%010x][%010X]\t", unbr, unbr);
	printf("or: %d\n", j);
}

void	hashtag(t_ui unbr)
{
	int	i, j;

	printf("\n---hashtag---\n");

	i = ft_printf("[%#10x][%#10X]\t", unbr, unbr);
	printf("my: %d\n", i);
	j = printf("[%#10x][%#10X]\t", unbr, unbr);
	printf("or: %d\n", j);
}

void	space(int num)
{
	int	i, j;

	printf("\n---space---\n");

	i = ft_printf("[% d]\t", num);
	printf("my: %d\n", i);
	j = printf("[% d]\t", num);
	printf("or: %d\n", j);

	num *= -1;
	i = ft_printf("[% d]\t", num);
	printf("my: %d\n", i);
	j = printf("[% d]\t", num);
	printf("or: %d\n", j);
}

void	plus(int num)
{
	int	i, j;

	printf("\n---plus---\n");

	i = ft_printf("[%+d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+d]\t", num);
	printf("or: %d\n", j);

	num *= -1;
	i = ft_printf("[%+d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+d]\t", num);
	printf("or: %d\n", j);
}

void	mix_flags(char c, char *str, char *ptr, int num, t_ui unbr)
{
	int	i, j;

	(void)c;
	(void)str;
	(void)ptr;

	printf("\n---mix_flags---\n");
	
	i = ft_printf("[%-+20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%-+20d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%- 20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%- 20d]\t", num);
	printf("or: %d\n", j);

	num *= -1;
	i = ft_printf("[%-+20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%-+20d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%- 20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%- 20d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%-#20x][%-#20X]\t", unbr, unbr);
	printf("my: %d\n", i);
	j = printf("[%-#20x][%-#20X]\t", unbr, unbr);
	printf("or: %d\n", j);

	i = ft_printf("[%+-20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+-20d]\t", num);
	printf("or: %d\n", j);

	num *= -1;
	i = ft_printf("[%+-20d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+-20d]\t", num);
	printf("or: %d\n", j);

	i = ft_printf("[%+020d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+020d]\t", num);
	printf("or: %d\n", j);

	num *= -1;
	i = ft_printf("[%+020d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%+020d]\t", num);
	printf("or: %d\n", j);
}

int	main(void)
{
	char	c = 'g';
	char	*str = "dell";
	char	*ptr = &c;
	int		num = 6010;
	t_ui	unbr = -6010;

	normal_flags(c, str, ptr, num, unbr);
	width(c, str, ptr, num, unbr);
	minus(c, str, ptr, num, unbr);
	zero(num, unbr);
	hashtag(unbr);
	space(num);
	plus(num);
	mix_flags(c, str, ptr, num, unbr);
}
