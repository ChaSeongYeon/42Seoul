/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:50:22 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:24 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_info *info, int flag)
{
	int	temp;

	if (info->t_a->size < 2)
		return ;
	temp = info->t_a->top->val;
	info->t_a->top->val = info->t_a->top->prev->val;
	info->t_a->top->prev->val = temp;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_info *info, int flag)
{
	int	temp;

	if (info->t_b->size < 2)
		return ;
	temp = info->t_b->top->val;
	info->t_b->top->val = info->t_b->top->prev->val;
	info->t_b->top->prev->val = temp;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_info *info)
{
	sa(info, 0);
	sb(info, 0);
	ft_printf("ss\n");
}

void	pa(t_info *info)
{
	t_node	*tmp;

	if (info->t_b->size < 1)
		return ;
	tmp = pop_top(info->t_b);
	push_top(info->t_a, tmp);
	ft_printf("pa\n");
}

void	pb(t_info *info)
{
	t_node	*tmp;

	if (info->t_a->size < 1)
		return ;
	tmp = pop_top(info->t_a);
	push_top(info->t_b, tmp);
	ft_printf("pb\n");
}
