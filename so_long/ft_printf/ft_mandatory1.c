/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:40:55 by seocha            #+#    #+#             */
/*   Updated: 2022/12/07 15:17:39 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(va_list ap, int *cnt)
{
	int	val;

	val = va_arg(ap, int);
	if (ft_putchar(val, cnt) == -1)
		return ;
	(*cnt)++;
}

void	ft_str(va_list ap, int *cnt)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*cnt = -1;
			return ;
		}
		(*cnt) += 6;
	}
	else
	{
		while (*str)
		{
			if (ft_putchar(*str, cnt) == -1)
				return ;
			str++;
			(*cnt)++;
		}
	}
}

void	ft_addr(va_list ap, int *cnt)
{
	void			*addr;
	unsigned long	temp;

	addr = va_arg(ap, void *);
	if (ft_putchar('0', cnt) == -1 || ft_putchar('x', cnt) == -1)
		return ;
	(*cnt) += 2;
	if (!addr)
	{
		if (ft_putchar('0', cnt) == -1)
			return ;
		(*cnt)++;
	}
	else
	{
		temp = (unsigned long)addr;
		ft_print_hex(temp, cnt, "0123456789abcdef");
	}
}

void	ft_deci(va_list ap, int *cnt)
{
	int		val;

	val = va_arg(ap, int);
	if (val < 0)
	{
		if (ft_putchar('-', cnt) == -1)
			return ;
		(*cnt)++;
	}
	if (val == 0)
	{
		if (ft_putchar('0', cnt) == -1)
			return ;
		(*cnt)++;
	}
	else
		ft_print_deci(val, cnt);
}
