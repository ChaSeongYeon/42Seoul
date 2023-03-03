/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:12:02 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:47:06 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_get_cmd(char **path, char *cmd_name)
{
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (access(cmd, X_OK) != -1)
			return (cmd);
		free(cmd);
		path++;
	}
	return (NULL);
}

void	ft_child(char *argv[], char *envp[], t_pipex p)
{
	p.infile = open(argv[1], O_RDONLY);
	if (p.infile == -1)
		ft_std_error(argv[1], 0);
	dup2(p.fd[1], 1);
	close(p.fd[0]);
	dup2(p.infile, 0);
	p.cmd_options = ft_split(argv[2], ' ');
	if (!p.cmd_options)
		ft_cmd_error(argv[2]);
	p.cmd = ft_get_cmd(p.cmd_path, p.cmd_options[0]);
	if (!p.cmd)
	{
		ft_child_free(p);
		ft_cmd_error(argv[2]);
	}
	if (execve(p.cmd, p.cmd_options, envp) == -1)
		ft_std_error("execve failed", 1);
}

void	ft_parent(char *argv[], char *envp[], t_pipex p)
{
	p.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (p.outfile == -1)
		ft_std_error(argv[4], 0);
	dup2(p.fd[0], 0);
	close(p.fd[1]);
	dup2(p.outfile, 1);
	p.cmd_options = ft_split(argv[3], ' ');
	if (!p.cmd_options)
		ft_cmd_error(argv[3]);
	p.cmd = ft_get_cmd(p.cmd_path, p.cmd_options[0]);
	if (!p.cmd)
	{
		ft_child_free(p);
		ft_cmd_error(argv[3]);
	}
	waitpid(p.pid, NULL, WNOHANG);
	if (execve(p.cmd, p.cmd_options, envp) == -1)
		ft_std_error("execve failed", 1);
}

void	ft_process(char *argv[], char *envp[], t_pipex p)
{
	p.pid = fork();
	if (p.pid == -1)
		ft_std_error("Fork error", 1);
	else if (p.pid == 0)
		ft_child(argv, envp, p);
	else
		ft_parent(argv, envp, p);
}
