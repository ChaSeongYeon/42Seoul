/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:31:43 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 12:23:42 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	ft_isspace(char c)
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
	int			len;
	long long	result;

	len = 0;
	result = 0;
	str = ft_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (exit_error("The argument must be a positive number."));
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
		len++;
		if (result > 2147483647 || len > 10)
			return (exit_error("The argument is out of range."));
	}
	if (*str != '\0')
		return (exit_error("The argument is not numeric."));
	return ((int)result);
}
