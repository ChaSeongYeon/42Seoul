/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:36:45 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:22 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*newnode(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit_error();
	node->val = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_top(t_stack *stack, t_node *node)
{
	if (!node)
		exit_error();
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else if (stack->size == 1)
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->top = node;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		exit_error();
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else if (stack->size == 1)
	{
		stack->top->prev = node;
		node->next = stack->top;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
		stack->bottom = node;
	}
	stack->size++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else if (stack->size == 2)
	{
		stack->bottom->next = NULL;
		stack->top->prev = NULL;
		stack->top = stack->bottom;
	}
	else
	{
		stack->top = stack->top->prev;
		stack->top->next = NULL;
	}
	tmp->prev = NULL;
	stack->size--;
	return (tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else if (stack->size == 2)
	{
		stack->bottom = stack->top;
		stack->bottom->prev = NULL;
		stack->top->prev = NULL;
	}
	else
	{
		stack->bottom = stack->bottom->next;
		stack->bottom->prev = NULL;
	}
	tmp->next = NULL;
	stack->size--;
	return (tmp);
}
