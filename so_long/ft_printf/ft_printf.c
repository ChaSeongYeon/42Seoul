/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:25:55 by seocha            #+#    #+#             */
/*   Updated: 2023/01/06 10:41:14 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *cnt)
{
	if (write(1, &c, 1) == -1)
	{
		*cnt = -1;
		return (-1);
	}
	return (1);
}

static void	ft_type(char **format, va_list ap, int *cnt)
{
	(*format)++;
	if (**format == 'c')
		ft_char(ap, cnt);
	else if (**format == 's')
		ft_str(ap, cnt);
	else if (**format == 'p')
		ft_addr(ap, cnt);
	else if (**format == 'd' || **format == 'i')
		ft_deci(ap, cnt);
	else if (**format == 'x' || **format == 'X')
		ft_hex(format, ap, cnt);
	else if (**format == 'u')
		ft_udec(ap, cnt);
	else if (**format == '%')
	{
		if (ft_putchar('%', cnt) == -1)
			return ;
		(*cnt)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		cnt;
	va_list	ap;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_type((char **)&format, ap, &cnt);
			if (cnt == -1)
				return (cnt);
		}
		else
		{
			if (ft_putchar(*format, &cnt) == -1)
				return (cnt);
			cnt++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
