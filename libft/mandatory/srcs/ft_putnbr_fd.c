/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:14:01 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:11 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_print_num(int a, int fd)
{
	a += 48;
	ft_putchar_fd(a, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	r;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		ft_print_num(2, fd);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n < 10)
		ft_print_num(n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		r = n % 10;
		ft_print_num(r, fd);
	}
}
