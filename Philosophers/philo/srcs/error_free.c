/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:56 by seocha            #+#    #+#             */
/*   Updated: 2023/04/08 14:28:48 by seocha           ###   ########.fr       */
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
	int			i;
	long long	now;

	while (!(info->flag))
	{
		i = 0;
		if ((info->must_cnt != 0) && (info->all_eat == info->num))
			info->flag = 1;
		while (i < info->num && !(info->flag))
		{
			now = get_time();
			read_lock(info);
			if (now - philo[i].t_last >= info->t_die && !(info->flag))
			{
				philo_log(info, philo, "died");
				write_lock(info);
				info->flag = 1;
				write_unlock(info);
			}
			read_unlock(info);
			i++;
		}
	}
}

void	free_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	free(philo);
	free(info->forks);
	pthread_mutex_destroy(&(info->rw));
}
