/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:08:54 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:20 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	new_ab(int a, int b, int new_a, int new_b)
{
	int	ab_sum;
	int	new_sum;

	ab_sum = ft_abs(a) + ft_abs(b);
	new_sum = ft_abs(new_a) + ft_abs(new_b);
	if (ab_sum > new_sum)
		return (1);
	return (0);
}

static void	sort_3(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->t_a->top->val;
	b = info->t_a->top->prev->val;
	c = info->t_a->bottom->val;
	if (a > b && b < c && c > a)
		sa(info, 1);
	else if (a > b && b < c && c < a)
		ra(info, 1);
	else if (a < b && b > c && c < a)
		rra(info, 1);
	else if (a > b && b > c && c < a)
	{
		sa(info, 1);
		rra(info, 1);
	}
	else if (a < b && b > c && c > a)
	{
		sa(info, 1);
		ra(info, 1);
	}
}

static void	quick_sort(t_info *info)
{
	int		pvt_1;
	int		pvt_2;
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	pvt_1 = info->arr[info->size / 3];
	pvt_2 = info->arr[info->size * 2 / 3];
	while (cnt < info->size && info->t_a->size > 3)
	{
		tmp = info->t_a->top;
		if (tmp->val <= pvt_1)
		{
			pb(info);
			rb(info, 1);
		}
		else if (tmp->val > pvt_1 && tmp->val <= pvt_2)
			pb(info);
		else
			ra(info, 1);
		cnt++;
	}
	while (info->t_a->size > 3)
		pb(info);
	sort_3(info);
}

static void	greedy_sort(t_info *info)
{
	int	a;
	int	b;

	while (info->t_b->size)
	{
		find_best(info, &a, &b);
		rotate_both(info, &a, &b);
		rotate_a(info, &a);
		rotate_b(info, &b);
		pa(info);
	}
	rotate_last(info);
}

void	sort(t_info *info)
{
	if (info->t_a->size == 2)
	{
		if (info->t_a->top->val > info->t_a->bottom->val)
			sa(info, 1);
	}
	else
	{
		quick_sort(info);
		greedy_sort(info);
	}
}
