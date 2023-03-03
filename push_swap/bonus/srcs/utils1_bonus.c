/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:03:04 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:46:09 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * (-1));
	return (num);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static const char	*ft_space(const char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else
			break ;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	str = ft_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result = result * sign;
	if (*str != '\0' || result > 2147483647 || result < -2147483648)
		exit_error();
	return ((int)result);
}
