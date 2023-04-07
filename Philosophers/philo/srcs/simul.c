/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:50:41 by seocha            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/01 22:00:55 by seocha           ###   ########.fr       */
=======
/*   Updated: 2023/04/07 15:36:26 by seocha           ###   ########.fr       */
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

<<<<<<< HEAD
static void	take_time(t_info *info, long long time)
=======
static void	take_time(long long time, t_info *info)
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
{
	long long	start;
	long long	end;

	start = get_time();
	while (!(info->flag))
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

	now = get_time();
	pthread_mutex_lock(&(info->status));
	if (!(info->flag))
		printf("%lld %d %s\n", now - info->t_start, philo->id + 1, str);
	pthread_mutex_unlock(&(info->status));
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
<<<<<<< HEAD
		take_time(info, info->t_eat);
=======
		take_time(info->t_eat, info);
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
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
		usleep(1000);
	else
		usleep(500);
	while (!info->flag)
	{
		eat(info, philo);
		if (philo->eat_cnt == info->must_cnt)
		{
			info->all_eat++;
			break ;
		}
		philo_log(info, philo, "is sleeping");
<<<<<<< HEAD
		take_time(info, info->t_sleep);
=======
		take_time(info->t_sleep, info);
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
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
<<<<<<< HEAD
		if (pthread_create(&(philo[i].th), NULL, &simulation, &(philo[i])))
=======
		if (pthread_create(&(philo[i].th), NULL, simulation, &(philo[i])))
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
			exit_error("Fail to create thread");
		i++;
	}
	check_finished(info, philo);
	i = 0;
	while (i < info->num)
		pthread_join(philo[i++].th, NULL);
<<<<<<< HEAD
	free_thread(info, philo);
=======
	destroy_free(info, philo);
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
}
