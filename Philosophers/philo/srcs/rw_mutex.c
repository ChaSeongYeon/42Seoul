/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:43:50 by seocha            #+#    #+#             */
/*   Updated: 2023/04/08 14:20:25 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	read_lock(t_info *info)
{
	pthread_mutex_lock(&(info->rw));
	while (info->writer)
		usleep(1);
	(info->readers)++;
	pthread_mutex_unlock(&(info->rw));
}

void	read_unlock(t_info *info)
{
	pthread_mutex_lock(&(info->rw));
	(info->readers)--;
	pthread_mutex_unlock(&(info->rw));
}

void	write_lock(t_info *info)
{
	pthread_mutex_lock(&(info->rw));
	while (info->writer || (info->readers > 0))
		usleep(1);
	info->writer = 1;
	pthread_mutex_unlock(&(info->rw));
}

void	write_unlock(t_info *info)
{
	pthread_mutex_lock(&(info->rw));
	info->writer = 0;
	pthread_mutex_unlock(&(info->rw));
}
