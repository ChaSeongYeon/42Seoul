/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:31:43 by seocha            #+#    #+#             */
/*   Updated: 2023/04/08 11:15:47 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit_error("Failed to get time.");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
	int			cnt;
	long long	result;

	cnt = 0;
	result = 0;
	str = ft_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			exit_error("The argument must be a positive number.");
		str++;
	}
	while (ft_isdigit(*str) && cnt < 11)
	{
		result = result * 10 + *str - '0';
		str++;
		cnt++;
	}
	if (*str != '\0' || result > 2147483647 || cnt > 10)
		exit_error("The argument is not numeric or out of range.");
	return ((int)result);
}
