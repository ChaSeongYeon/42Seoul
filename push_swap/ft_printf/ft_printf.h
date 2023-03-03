/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:34 by seocha            #+#    #+#             */
/*   Updated: 2022/12/08 09:21:10 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/*ft_printf.c function*/
int		ft_putchar(char c, int *cnt);
void	ft_type(char **format, va_list ap, int *cnt);
int		ft_printf(const char *format, ...);

/*ft_mandatory.c function*/
void	ft_char(va_list ap, int *cnt);
void	ft_str(va_list ap, int *cnt);
void	ft_addr(va_list ap, int *cnt);
void	ft_deci(va_list ap, int *cnt);
void	ft_udec(va_list ap, int *cnt);
void	ft_hex(char **format, va_list ap, int *cnt);
void	ft_print_hex(unsigned long num, int *cnt, char *str);
void	ft_print_deci(long long num, int *cnt);

#endif