/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:50:49 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:46:15 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	init_info(t_info *info)
{
	info->t_a = (t_stack *)malloc(sizeof(t_stack));
	info->t_b = (t_stack *)malloc(sizeof(t_stack));
	if (!info->t_a || !info->t_b)
		exit_error();
	info->size = 0;
	info->arr = NULL;
	info->t_a->size = 0;
	info->t_b->size = 0;
	info->t_a->top = NULL;
	info->t_b->top = NULL;
	info->t_a->bottom = NULL;
	info->t_b->bottom = NULL;
}

static int	get_arr_size(int argc, char *argv[])
{
	int		i;
	int		num;
	int		sum;
	char	**tmp;

	i = 0;
	sum = 0;
	while (i < argc - 1)
	{
		num = 0;
		tmp = ft_split(argv[i + 1], &num);
		if (!tmp[0])
			exit_error();
		free_split(tmp, num);
		sum += num;
		i++;
	}
	return (sum);
}

static void	make_arr(char *argv[], t_info *info, int *arr, int sum)
{
	int		i;
	int		j;
	int		idx;
	int		num;
	char	**tmp;

	i = 0;
	idx = 0;
	while (idx < sum)
	{
		j = 0;
		num = 0;
		tmp = ft_split(argv[i + 1], &num);
		if (!tmp[0])
			exit_error();
		while (j < num)
		{
			arr[idx++] = ft_atoi(tmp[j++]);
			info->size++;
		}
		i++;
		free_split(tmp, num);
	}
}

static int	*make_stack(int argc, char *argv[], t_info *info, int i)
{
	int		sum;
	int		*arr;
	t_node	*new;

	i = 0;
	sum = get_arr_size(argc, argv);
	arr = (int *)malloc(sizeof(int) * sum);
	if (!arr)
		exit_error();
	make_arr(argv, info, arr, sum);
	while (i < sum)
	{
		new = newnode(arr[i++]);
		push_bottom(info->t_a, new);
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	t_info	info;

	if (argc < 2)
		return (-1);
	init_info(&info);
	arr = make_stack(argc, argv, &info, 0);
	check_arr(&info, arr, 0, 0);
	info.arr = arr;
	check_inst(&info);
	if (is_sorted(&info))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&info);
	return (0);
}
