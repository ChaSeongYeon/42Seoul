/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:40:35 by seocha            #+#    #+#             */
/*   Updated: 2023/03/04 16:45:46 by seocha           ###   ########.fr       */
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

	i = 0;
	while (!info->flag)
	{
		if (info->must_cnt != -1 && info->all_eat == info->num)
			info->flag = 1;
		else
		{
			while (i < info->num)
			{
				now = get_time();
				if (now - philo[i].t_last >= info->t_die)
				{
					philo_log(info, philo, "died");
					info->flag = 1;
				}
				i++;
			}
		}
	}
}
