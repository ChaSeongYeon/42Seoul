/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:40:58 by seocha            #+#    #+#             */
/*   Updated: 2022/12/08 09:13:57 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_udec(va_list ap, int *cnt)
{
	unsigned int	val;

	val = va_arg(ap, unsigned int);
	if (val == 0)
	{
		if (ft_putchar('0', cnt) == -1)
			return ;
		(*cnt)++;
	}
	else
		ft_print_deci(val, cnt);
}

void	ft_hex(char **format, va_list ap, int *cnt)
{
	unsigned int	val;
	char			*str;

	str = NULL;
	val = va_arg(ap, unsigned int);
	if (val == 0)
	{
		if (ft_putchar('0', cnt) == -1)
			return ;
		(*cnt)++;
	}
	else
	{
		if (**format == 'x')
			str = "0123456789abcdef";
		else if (**format == 'X')
			str = "0123456789ABCDEF";
		ft_print_hex(val, cnt, str);
	}
}

void	ft_print_hex(unsigned long num, int *cnt, char *str)
{
	char	hex[16];
	int		idx;

	idx = 0;
	while (num > 0)
	{
		hex[idx] = str[num % 16];
		num /= 16;
		idx++;
		(*cnt)++;
	}
	idx--;
	while (idx >= 0)
	{
		if (ft_putchar(hex[idx], cnt) == -1)
			return ;
		idx--;
	}
}

void	ft_print_deci(long long num, int *cnt)
{
	char	str[10];
	int		idx;

	idx = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		str[idx] = "0123456789"[num % 10];
		num /= 10;
		idx++;
		(*cnt)++;
	}
	idx--;
	while (idx >= 0)
	{
		if (ft_putchar(str[idx], cnt) == -1)
			return ;
		idx--;
	}
}
