/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:50:24 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:46:12 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ra(t_info *info)
{
	t_node	*tmp;

	if (info->t_a->size < 2)
		return ;
	tmp = pop_top(info->t_a);
	push_bottom(info->t_a, tmp);
}

void	rb(t_info *info)
{
	t_node	*tmp;

	if (info->t_b->size < 2)
		return ;
	tmp = pop_top(info->t_b);
	push_bottom(info->t_b, tmp);
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}

void	rra(t_info *info)
{
	t_node	*tmp;

	if (info->t_a->size < 2)
		return ;
	tmp = pop_bottom(info->t_a);
	push_top(info->t_a, tmp);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	if (info->t_b->size < 2)
		return ;
	tmp = pop_bottom(info->t_b);
	push_top(info->t_b, tmp);
}
