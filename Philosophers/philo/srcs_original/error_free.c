/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:56 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 15:28:20 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_log(t_info *info, t_philo *philo, char *str)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(&(info->status));
	pthread_mutex_lock(&(info->flag_m));
	if (!(info->flag_die))
		printf("%lld %d %s\n", now - info->t_start, philo->id + 1, str);
	pthread_mutex_unlock(&(info->flag_m));
	pthread_mutex_unlock(&(info->status));
}

int	exit_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

static void	check_die(t_info *info, t_philo *philo, int i, long long now)
{
	while (i < info->num)
	{
		now = get_time();
		pthread_mutex_lock(&(info->eat_m));
		if ((now - philo[i].t_last) >= info->t_die)
		{
			pthread_mutex_unlock(&(info->eat_m));
			philo_log(info, &philo[i], "died");
			pthread_mutex_lock(&(info->flag_m));
			info->flag_die = 1;
			pthread_mutex_unlock(&(info->flag_m));
			break ;
		}
		pthread_mutex_unlock(&(info->eat_m));
		i++;
	}
}

void	check_finished(t_info *info, t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&(info->flag_m));
	while (!(info->flag_die))
	{
		pthread_mutex_unlock(&(info->flag_m));
		i = 0;
		pthread_mutex_lock(&(info->cnt_m));
		if ((info->must_eat_cnt != 0) && (info->all_eat == info->num))
		{	
			pthread_mutex_unlock(&(info->cnt_m));
			pthread_mutex_lock(&(info->flag_m));
			info->flag_die = 1;
			break ;
		}
		pthread_mutex_unlock(&(info->cnt_m));
		check_die(info, philo, 0, 0);
		pthread_mutex_lock(&(info->flag_m));
	}
	pthread_mutex_unlock(&(info->flag_m));
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
	free(info->forks);
	free(philo);
	pthread_mutex_destroy(&(info->status));
	pthread_mutex_destroy(&(info->flag_m));
	pthread_mutex_destroy(&(info->eat_m));
	pthread_mutex_destroy(&(info->cnt_m));
}
