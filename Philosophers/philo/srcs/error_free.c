/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:56 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 16:40:58 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_log(t_info *info, t_philo *philo, char *str)
{
	pthread_mutex_lock(&(info->status));
	pthread_mutex_lock(&(info->flag_m));
	if (!(info->flag_die))
		printf("%lld %d %s\n", get_time() - info->t_start, philo->id + 1, str);
	pthread_mutex_unlock(&(info->flag_m));
	pthread_mutex_unlock(&(info->status));
}

int	exit_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

void	check_die(t_info *info, t_philo *philo)
{
	if ((get_time() - philo->t_last) >= info->t_die)
	{
		philo_log(info, philo, "died");
		pthread_mutex_lock(&(info->flag_m));
		info->flag_die = 1;
		pthread_mutex_unlock(&(info->flag_m));
	}
}

void	check_finished(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(info->cnt_m));
	if ((info->must_eat_cnt != 0) && (info->all_eat == info->num))
	{	
		pthread_mutex_unlock(&(info->cnt_m));
		pthread_mutex_lock(&(info->flag_m));
		info->flag_die = 1;
		pthread_mutex_unlock(&(info->flag_m));
	}
	pthread_mutex_unlock(&(info->cnt_m));
}

void	free_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		pthread_mutex_destroy(&(info->forks_m[i]));
		i++;
	}
	free(info->forks_m);
	free(info->forks);
	free(philo);
	pthread_mutex_destroy(&(info->status));
	pthread_mutex_destroy(&(info->flag_m));
	pthread_mutex_destroy(&(info->eat_m));
	pthread_mutex_destroy(&(info->cnt_m));
}
