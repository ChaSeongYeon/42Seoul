/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:53:24 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:47:07 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_parent_free(t_pipex p)
{
	int	i;

	i = 0;
	close(p.infile);
	close(p.outfile);
	while (p.cmd_path[i])
	{
		free(p.cmd_path[i]);
		i++;
	}
	free(p.cmd_path);
}

void	ft_child_free(t_pipex p)
{
	int	i;

	i = 0;
	while (p.cmd_options[i])
	{
		free(p.cmd_options[i]);
		i++;
	}
	free(p.cmd_options);
	free(p.cmd);
}

char	*ft_get_path(char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;

	if (argc != 5)
		return (ft_put_error("Argument error"));
	if (pipe(p.fd) == -1)
		ft_std_error("Pipe error", 1);
	p.path = ft_get_path(envp);
	p.cmd_path = ft_split(p.path, ':');
	ft_process(argv, envp, p);
	ft_parent_free(p);
	return (0);
}
