/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:24:40 by seocha            #+#    #+#             */
/*   Updated: 2023/04/08 14:24:04 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_time(long long time)
{
	long long	start;
	long long	end;

	start = get_time();
	while (1)
	{
		end = get_time();
		if ((end - start) >= time)
			break ;
		usleep(10);
	}
}

void	philo_log(t_info *info, t_philo *philo, char *str)
{
	long long	now;

	read_lock(info);
	now = get_time();
	if (!(info->flag))
		printf("%lld %d %s\n", now - info->t_start, philo->id + 1, str);
	read_unlock(info);
}

static void	eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks[philo->l_fork]));
	philo_log(info, philo, "has taken a fork");
	if (info->num != 1)
	{
		pthread_mutex_lock(&(info->forks[philo->r_fork]));
		philo_log(info, philo, "has taken a fork");
		philo_log(info, philo, "is eating");
		philo->t_last = get_time();
		(philo->eat_cnt)++;
		take_time(info->t_eat);
		pthread_mutex_unlock(&(info->forks[philo->r_fork]));
	}
	pthread_mutex_unlock(&(info->forks[philo->l_fork]));
}

static void	*simulation(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = arg;
	info = philo->info;
	if (philo->id % 2)
		usleep(100);
	else
		usleep(50);
	while (!(info->flag))
	{
		eat(info, philo);
		if (philo->eat_cnt == info->must_cnt)
		{
			write_lock(info);
			(info->all_eat)++;
			write_unlock(info);
			break ;
		}
		philo_log(info, philo, "is sleeping");
		take_time(info->t_sleep);
		philo_log(info, philo, "is thinking");
	}
	return (0);
}

void	thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		philo[i].t_last = get_time();
		if (pthread_create(&(philo[i].th), NULL, simulation, &(philo[i])))
			exit_error("Fail to create thread");
		i++;
	}
	check_finished(info, philo);
	i = 0;
	while (i < info->num)
		pthread_join(philo[i++].th, NULL);
	free_thread(info, philo);
}
