/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:19:05 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:22 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_info *info)
{
	rra(info, 0);
	rrb(info, 0);
	ft_printf("rrr\n");
}

void	rotate_both(t_info *info, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rr(info);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(info);
		(*a)++;
		(*b)++;
	}
}

void	rotate_a(t_info *info, int *a)
{
	while (*a > 0)
	{
		ra(info, 1);
		(*a)--;
	}
	while (*a < 0)
	{
		rra(info, 1);
		(*a)++;
	}
}

void	rotate_b(t_info *info, int *b)
{
	while (*b > 0)
	{
		rb(info, 1);
		(*b)--;
	}
	while (*b < 0)
	{
		rrb(info, 1);
		(*b)++;
	}
}

void	rotate_last(t_info *info)
{
	int	i;

	i = get_cnt(info, get_max(info));
	if (i > (info->t_a->size / 2))
	{
		while (i < info->t_a->size - 1)
		{
			rra(info, 1);
			i++;
		}
	}
	else
	{
		while (i > -1)
		{
			ra(info, 1);
			i--;
		}
	}
}
