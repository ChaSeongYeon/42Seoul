/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:39:34 by seocha            #+#    #+#             */
/*   Updated: 2023/08/01 14:44:21 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_left_fork(t_info *info, t_philo *philo)
{
	while (info->forks[philo->l_fork] == '1')
	{
		if (info->forks[philo->l_fork] == '0')
			info->forks[philo->l_fork] = '1';
	}
	philo_log(info, philo, "has taken a fork");
}

void	take_right_fork(t_info *info, t_philo *philo)
{
	while (info->forks[philo->r_fork] == '1')
	{
		if (info->forks[philo->r_fork] == '0')
			info->forks[philo->r_fork] = '1';
	}
	philo_log(info, philo, "has taken a fork");
}
