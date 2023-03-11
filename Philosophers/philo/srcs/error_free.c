/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:40:35 by seocha            #+#    #+#             */
/*   Updated: 2023/03/11 23:07:51 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	exit_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	check_finished(t_info *info, t_philo *philo)
{
	int		i;
	long	now;

	while (!info->flag)
	{
		i = 0;
		if (info->must_cnt != -1 && info->all_eat == info->num)
			info->flag = 1;
		while (i < info->num)
		{
			now = get_time();
			if (now - philo[i].t_last >= info->t_die)
			{
				philo_log(info, philo, "died");
				info->flag = 1;
			}
			i++;
		}
	}
}

void	destroy_free(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->status));
	while (i < info->num)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		free(&philo[i]);
		i++;
	}
}
