/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:29:40 by seocha            #+#    #+#             */
/*   Updated: 2023/01/06 10:40:40 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(int fd, char *buff, char **backup)
{
	int		flag;
	char	*temp;

	flag = 1;
	if (!*backup)
		return (-2);
	while (!ft_strchr(*backup, '\n') && flag)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag == -1)
			return (flag);
		buff[flag] = '\0';
		temp = *backup;
		*backup = ft_strjoin(temp, buff);
		if (!*backup)
			return (-2);
		free(temp);
	}
	return (flag);
}

static char	*ft_extract_line(char **backup)
{
	int		idx;
	char	*line;
	char	*temp;

	idx = 0;
	while ((*backup)[idx] != '\n')
		idx++;
	temp = *backup;
	line = ft_substr(temp, 0, idx + 1);
	*backup = ft_strdup(&(*backup)[idx + 1]);
	free(temp);
	return (line);
}

static char	*ft_get_line(int fd, char *buff, char **backup)
{
	int		flag;
	char	*line;

	flag = ft_read_line(fd, buff, backup);
	if (flag == -2)
		return (NULL);
	if (!**backup || flag == -1)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (ft_extract_line(backup));
	line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	line = ft_get_line(fd, buff, &backup[fd]);
	free(buff);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ex.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
*/
