/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:26:29 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:25 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_info *info)
{
	int		max;
	t_node	*node;

	node = info->t_a->top;
	max = node->val;
	while (node)
	{
		if (node->val > max)
			max = node->val;
		node = node->prev;
	}
	return (max);
}

int	get_cnt(t_info *info, int num)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->t_a->top;
	while (node)
	{
		if (node->val == num)
			break ;
		i++;
		node = node->prev;
	}
	return (i);
}

static int	get_min_cnt(t_info *info, long long int num, int i)
{
	int					tmp;
	long long int		diff;
	long long int		diff_min;
	t_node				*node;

	diff_min = 4294967295;
	node = info->t_a->top;
	while (node)
	{
		if (num > node->val)
			diff = num - node->val;
		else
			diff = node->val - num;
		if (diff_min >= diff)
		{
			diff_min = diff;
			tmp = node->val;
		}
		node = node->prev;
	}
	i = get_cnt(info, tmp);
	if (tmp < num)
		i++;
	return (i);
}

static int	set_new_a(t_info *info, int num)
{
	int	cnt;
	int	max;

	cnt = 0;
	if (info->t_a->top)
	{
		max = get_max(info);
		if (num > max)
			cnt = get_cnt(info, max) + 1;
		else
			cnt = get_min_cnt(info, num, 0);
		if (cnt > info->t_a->size / 2)
			cnt = (info->t_a->size - cnt) * (-1);
	}
	return (cnt);
}

void	find_best(t_info *info, int *a, int *b)
{
	int		idx;
	int		num;
	int		new_a;
	int		new_b;
	t_node	*tmp;

	idx = 0;
	tmp = info->t_b->top;
	while (idx < info->t_b->size)
	{
		num = tmp->val;
		new_a = set_new_a(info, num);
		if (idx >= (info->t_b->size + 1) / 2)
			new_b = (info->t_b->size - idx) * (-1);
		else
			new_b = idx;
		if (idx == 0 || new_ab(*a, *b, new_a, new_b))
		{
			*a = new_a;
			*b = new_b;
		}
		tmp = tmp->prev;
		idx++;
	}
}
