/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:08:14 by seocha            #+#    #+#             */
/*   Updated: 2023/03/04 16:58:25 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_info(t_info *info, int argc, char *argv[])
{
	info->num = ft_atoi(argv[1]);
	if (info->num == 0)
		exit_error("There must be at least one philosopher.");
	info->flag = 0;
	info->must_cnt = 0;
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->must_cnt = ft_atoi(argv[5]);
		if (info->must_cnt == 0)
			exit_error("Optional argument must be greater than zero.");
	}
	else
		info->must_cnt = -1;
	info->t_start = get_time();
}

static void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(info->status), NULL))
		exit_error("Status mutex error.");
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num);
	if (!(info->forks))
		exit_error("Malloc error.");
	while (i < info->num)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			exit_error("Fork mutex error.");
		i++;
	}
}

static void	init_philo(t_info *info, t_philo **philo)
{
	int			i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->num);
	if (!(*philo))
		exit_error("Malloc error.");
	while (i < info->num)
	{
		(*philo)[i].id = i;
		(*philo)[i].l_fork = i;
		(*philo)[i].r_fork = (i + 1) % info->num;
		(*philo)[i].t_last = get_time();
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].info = info;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Argument error.");
		return (-1);
	}
	init_info(&info, argc, argv);
	init_mutex(&info);
	init_philo(&info, &philo);
	thread(&info, philo);
	return (0);
}
