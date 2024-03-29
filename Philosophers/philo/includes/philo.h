/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:26 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 15:33:43 by seocha           ###   ########.fr       */
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
	int				flag_die;
	int				all_eat;
	int				must_eat_cnt;
	char			*forks;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		t_start;
	pthread_mutex_t	status;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	cnt_m;
	pthread_mutex_t	flag_m;
	pthread_mutex_t	*forks_m;
}	t_info;

typedef struct s_phio
{
	int			id;
	int			l_fork;
	int			r_fork;
	int			eat_cnt;
	long long	t_last;
	pthread_t	th;
	t_info		*info;
}	t_philo;

/* simul.c */
int			thread(t_info *info, t_philo *philo);

/* error_free.c */
int			exit_error(char *str);
void		philo_log(t_info *info, t_philo *philo, char *str);
void		check_die(t_info *info, t_philo *philo);
void		check_finished(t_info *info);
void		free_thread(t_info *info, t_philo *philo);

/* utils.c */
long long	get_time(void);
int			ft_atoi(const char *str);

/* fork.c */
void		take_left_fork(t_info *info, t_philo *philo);
void		take_right_fork(t_info *info, t_philo *philo);

#endif