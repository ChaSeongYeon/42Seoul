/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:19:05 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:46:11 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
}

static void	is_oper(t_info *info, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		sa(info);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		sb(info);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ss(info);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		pa(info);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		pb(info);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ra(info);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		rb(info);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		rr(info);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		rra(info);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		rrb(info);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		rrr(info);
	else
		exit_error();
}

void	check_inst(t_info *info)
{
	char	*oper;

	oper = get_next_line(0);
	while (oper != NULL)
	{
		is_oper(info, oper);
		free(oper);
		oper = get_next_line(0);
	}
}

int	is_sorted(t_info *info)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (info->t_a->size != info->size || info->t_b->size != 0)
		return (0);
	tmp = info->t_a->top;
	while (tmp)
	{
		if (tmp->val != info->arr[i])
			return (0);
		tmp = tmp->prev;
		i++;
	}
	return (1);
}
