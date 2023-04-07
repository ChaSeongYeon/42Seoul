/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:27:15 by seocha            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/01 20:20:21 by seocha           ###   ########.fr       */
=======
/*   Updated: 2023/04/07 15:31:03 by seocha           ###   ########.fr       */
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit_error("Failed to get time.");
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
<<<<<<< HEAD
=======
	int			cnt;
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
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
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
		cnt++;
	}
<<<<<<< HEAD
	if (*str != '\0' || result > 2147483647)
=======
	if (*str != '\0' || cnt > 10)
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
		exit_error("The argument is not numeric or out of range.");
	return ((int)result);
}
