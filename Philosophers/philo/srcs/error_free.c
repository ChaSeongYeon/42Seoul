/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:40:35 by seocha            #+#    #+#             */
<<<<<<< HEAD:Philosophers/philo/srcs/error_free.c
/*   Updated: 2023/04/01 22:09:20 by seocha           ###   ########.fr       */
=======
/*   Updated: 2023/04/07 15:43:37 by seocha           ###   ########.fr       */
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f:Philosophers/philo/srcs/error.c
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
<<<<<<< HEAD:Philosophers/philo/srcs/error_free.c
		if ((info->must_cnt != 0) && (info->all_eat == info->num))
=======
		if ((info->must_cnt != -1) && (info->all_eat == info->num))
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f:Philosophers/philo/srcs/error.c
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

<<<<<<< HEAD:Philosophers/philo/srcs/error_free.c
void	free_thread(t_info *info, t_philo *philo)
=======
void	destroy_free(t_info *info, t_philo *philo)
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f:Philosophers/philo/srcs/error.c
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
