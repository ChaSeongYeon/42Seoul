/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:21:34 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:47:09 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_put_error(char *str)
{
	perror(str);
	return (1);
}

void	ft_cmd_error(char *str)
{
	write(2, "pipex: ", 7);
	write(2, "command not found : ", 20);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(127);
}

void	ft_std_error(char *str, int i)
{
	write(2, "pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, " : ", 3);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(i);
}
