/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:50:27 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:46:14 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_info *info)
{
	t_node	*tmp;
	t_node	*next;

	tmp = info->t_a->bottom;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = info->t_b->bottom;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(info->t_a);
	free(info->t_b);
	free(info->arr);
}

void	free_split(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	check_dup(t_info *info, int *arr)
{
	int	i;

	i = 0;
	while (i < info->t_a->size - 1)
	{
		if (arr[i] == arr[i + 1])
			exit_error();
		i++;
	}
}

void	check_arr(t_info *info, int *arr, int i, int flag)
{
	int	j;
	int	tmp;

	while (i < info->t_a->size - 1)
	{
		j = i + 1;
		while (j < info->t_a->size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				flag++;
			}
			j++;
		}
		i++;
	}
	check_dup(info, arr);
}
