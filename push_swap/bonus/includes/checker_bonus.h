/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:50:45 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:15:34 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/* ft_printf */
# include "../../ft_printf/ft_printf.h"

/* get_next_line */
# include "../../get_next_line/get_next_line.h"

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

/* operate1_bonus.c functions */
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);

/* operate2_bonus.c functions */
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);

/* operate3_bonus.c functions*/
void	rrr(t_info *info);
void	check_inst(t_info *info);
int		is_sorted(t_info *info);

/* push_pop_bonus.c functions */
t_node	*newnode(int value);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

/* error_free_bonus.c functions */
void	exit_error(void);
void	free_stack(t_info *info);
void	free_split(char **arr, int idx);
void	check_arr(t_info *info, int *arr, int i, int flag);

/* utils1_bonus.c functions */
int		ft_abs(int num);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

/* utils2_bonus.c functions */
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, int *i);

#endif