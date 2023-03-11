/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:16:21 by seocha            #+#    #+#             */
/*   Updated: 2023/03/11 22:50:51 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* memset */
# include <string.h>

/* printf */
# include <stdio.h>

/* malloc, free */
# include <stdlib.h>

/* write, usleep */
# include <unistd.h>

/* gettimeofday */
# include <sys/time.h>

/* pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
	pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock */
# include <pthread.h>

typedef struct s_info
{
	int				num;
	int				flag;
	int				must_cnt;
	int				all_eat;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			t_start;
	pthread_mutex_t	status;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_phio
{
	int			id;
	int			l_fork;
	int			r_fork;
	int			t_last;
	int			eat_cnt;
	t_info		*info;
	pthread_t	th;
}	t_philo;

/* simul.c */
void	thread(t_info *info, t_philo *philo);
void	philo_log(t_info *info, t_philo *philo, char *str);

/* error.c */
void	exit_error(char *str);
void	check_finished(t_info *info, t_philo *philo);
void	destroy_free(t_info *info, t_philo *philo);

/* utils.c */
long	get_time(void);
int		ft_atoi(const char *str);

#endif