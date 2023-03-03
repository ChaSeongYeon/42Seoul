/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:50:20 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:44:42 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ft_printf */
# include "../../ft_printf/ft_printf.h"

/* read, write*/
# include <unistd.h>

/* malloc, free, exit*/
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_info
{
	int		size;
	int		*arr;
	t_stack	*t_a;
	t_stack	*t_b;
}	t_info;

/* operate1.c functions */
void	sa(t_info *info, int flag);
void	sb(t_info *info, int flag);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);

/* operate2.c functions */
void	ra(t_info *info, int flag);
void	rb(t_info *info, int flag);
void	rr(t_info *info);
void	rra(t_info *info, int flag);
void	rrb(t_info *info, int flag);

/* operate3.c functions*/
void	rrr(t_info *info);
void	rotate_both(t_info *info, int *a, int *b);
void	rotate_a(t_info *info, int *a);
void	rotate_b(t_info *info, int *b);
void	rotate_last(t_info *info);

/* push_pop.c functions */
t_node	*newnode(int value);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

/* sort.c functions */
int		new_ab(int a, int b, int new_a, int new_b);
void	sort(t_info *info);

/* greedy_sort.c functions */
int		get_max(t_info *info);
int		get_cnt(t_info *info, int num);
void	find_best(t_info *info, int *a, int *b);

/* error_free.c functions */
void	exit_error(void);
void	free_stack(t_info *info);
void	free_split(char **arr, int idx);
int		check_arr(t_info *info, int *arr, int i, int flag);

/* utils1.c functions */
int		ft_abs(int num);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

/* utils2.c functions */
char	**ft_split(char const *s, int *i);

#endif