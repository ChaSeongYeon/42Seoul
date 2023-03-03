/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:50:24 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:23 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_info *info, int flag)
{
	t_node	*tmp;

	if (info->t_a->size < 2)
		return ;
	tmp = pop_top(info->t_a);
	push_bottom(info->t_a, tmp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_info *info, int flag)
{
	t_node	*tmp;

	if (info->t_b->size < 2)
		return ;
	tmp = pop_top(info->t_b);
	push_bottom(info->t_b, tmp);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_info *info)
{
	ra(info, 0);
	rb(info, 0);
	ft_printf("rr\n");
}

void	rra(t_info *info, int flag)
{
	t_node	*tmp;

	if (info->t_a->size < 2)
		return ;
	tmp = pop_bottom(info->t_a);
	push_top(info->t_a, tmp);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_info *info, int flag)
{
	t_node	*tmp;

	if (info->t_b->size < 2)
		return ;
	tmp = pop_bottom(info->t_b);
	push_top(info->t_b, tmp);
	if (flag == 1)
		ft_printf("rrb\n");
}
