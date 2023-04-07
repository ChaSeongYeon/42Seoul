/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:56 by seocha            #+#    #+#             */
/*   Updated: 2023/04/07 16:29:59 by seocha           ###   ########.fr       */
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
		{
			info->flag = 1;
			break ;
		}
		while (i < info->num)
		{
			now = get_time();
			if (now - philo[i].t_last >= info->t_die)
			{
				philo_log(info, philo, "died");
				info->flag = 1;
				break ;
			}
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
	pthread_mutex_destroy(&(info->status));
}
