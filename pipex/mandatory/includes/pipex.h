/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:19:54 by seocha            #+#    #+#             */
/*   Updated: 2022/12/29 11:14:29 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* open */
# include <fcntl.h>

/* close, read, write, access, dup, dup2, execve, fork, pipe, unlink */
# include <unistd.h>

/* malloc, free, exit */
# include <stdlib.h>

/* perror */
# include <stdio.h>

/* strerror */
# include <string.h>

/* wait, waitpid*/
# include <sys/wait.h>

/* errno */
# include <errno.h>
# include <sys/errno.h>

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid;
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd_path;
	char	**cmd_options;
	char	*cmd;
}	t_pipex;

/* pipex.c functions */
void	ft_parent_free(t_pipex p);
void	ft_child_free(t_pipex p);
char	*ft_get_path(char *envp[]);

/* error.c functions */
int		ft_put_error(char *str);
void	ft_cmd_error(char *str);
void	ft_std_error(char *str, int i);

/* process.c functions */
char	*ft_get_cmd(char **path, char *cmd_name);
void	ft_child(char *argv[], char *envp[], t_pipex p);
void	ft_parent(char *argv[], char *envp[], t_pipex p);
void	ft_process(char *argv[], char *envp[], t_pipex p);

/* ft_split.c, ft_strlcpy.c, utils.c functions */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
