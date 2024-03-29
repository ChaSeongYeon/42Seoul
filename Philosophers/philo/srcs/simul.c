/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:24:40 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 16:36:47 by seocha           ###   ########.fr       */
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
		usleep(1000);
	}
}

static void	eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks_m[philo->l_fork]));
	take_left_fork(info, philo);
	pthread_mutex_lock(&(info->flag_m));
	if (info->num != 1 && !(info->flag_die))
	{
		pthread_mutex_unlock(&(info->flag_m));
		pthread_mutex_lock(&(info->forks_m[philo->r_fork]));
		take_right_fork(info, philo);
		philo_log(info, philo, "is eating");
		philo->t_last = get_time();
		pthread_mutex_lock(&(info->eat_m));
		(philo->eat_cnt)++;
		pthread_mutex_unlock(&(info->eat_m));
		take_time(info->t_eat);
		info->forks[philo->r_fork] = '0';
		pthread_mutex_unlock(&(info->forks_m[philo->r_fork]));
		pthread_mutex_lock(&(info->flag_m));
	}
	pthread_mutex_unlock(&(info->flag_m));
	info->forks[philo->l_fork] = '0';
	pthread_mutex_unlock(&(info->forks_m[philo->l_fork]));
}

static void	sleep_think(t_info *info, t_philo *philo)
{
	check_die(info, philo);
	if (info->num != 1)
		philo_log(info, philo, "is sleeping");
	if (info->t_eat + info->t_sleep >= info->t_die || info->num == 1)
	{
		while ((get_time() - philo->t_last) < info->t_die)
			;
		check_die(info, philo);
		return ;
	}
	take_time(info->t_sleep);
	philo_log(info, philo, "is thinking");
	usleep(1000);
}

static void	*simulation(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = arg;
	info = philo->info;
	if (philo->id % 2)
		usleep(info->t_eat * 1000 + 100);
	pthread_mutex_lock(&(info->flag_m));
	while (!(info->flag_die))
	{
		pthread_mutex_unlock(&(info->flag_m));
		eat(info, philo);
		if (philo->eat_cnt == info->must_eat_cnt)
		{
			pthread_mutex_lock(&(info->cnt_m));
			info->all_eat++;
			pthread_mutex_unlock(&(info->cnt_m));
		}
		if (info->must_eat_cnt != 0)
			check_finished(info);
		sleep_think(info, philo);
		pthread_mutex_lock(&(info->flag_m));
	}
	pthread_mutex_unlock(&(info->flag_m));
	return (0);
}

int	thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		philo[i].t_last = get_time();
		if (pthread_create(&(philo[i].th), NULL, simulation, &(philo[i])))
			return (exit_error("Fail to create thread"));
		i++;
	}
	i = 0;
	while (i < info->num)
		pthread_join(philo[i++].th, NULL);
	free_thread(info, philo);
	return (0);
}
