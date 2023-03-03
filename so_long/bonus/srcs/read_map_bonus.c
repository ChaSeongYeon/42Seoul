/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:40:17 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:59 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	error_map_wall(t_game *game, int i)
{
	i = 0;
	while (i < ft_strlen(game->map.arr))
	{
		if (i < game->map.width)
		{
			if (game->map.arr[i] != '1')
				exit_error(game, "The map is not closed/surrounded by walls");
		}
		else if (i % game->map.width == 0 || \
				i % game->map.width == game->map.width - 1)
		{
			if (game->map.arr[i] != '1')
				exit_error(game, "The map is not closed/surrounded by walls");
		}
		else if (i > ft_strlen(game->map.arr) - game->map.width)
		{
			if (game->map.arr[i] != '1')
				exit_error(game, "The map is not closed/surrounded by walls");
		}
		i++;
	}
}

static void	error_map_cnt(t_game *game, int i)
{
	i = 0;
	while (i++ < ft_strlen(game->map.arr))
	{
		if (game->map.arr[i] == 'C')
		{
			game->map.cnt_c++;
			game->check.item_cnt++;
		}
		else if (game->map.arr[i] == 'E')
		{
			game->map.e_loc = i;
			game->map.cnt_e++;
		}
		else if (game->map.arr[i] == 'P')
			game->map.cnt_p++;
		else if (game->map.arr[i] == 'X')
		{
			game->map.x_loc = i;
			game->map.cnt_x++;
		}
	}
	if (game->map.cnt_c == 0 || game->map.cnt_e != 1 || \
		game->map.cnt_p != 1 || game->map.cnt_x != 1)
		exit_error(game, "Invalid number of components on map");
}

static void	error_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.height * game->map.width != ft_strlen(game->map.arr))
		exit_error(game, "Map is not rectangular");
	error_map_wall(game, i);
	error_map_cnt(game, i);
}

static int	open_file(char *filename, t_game *game)
{
	int	fd;
	int	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(game, "Failed to open file.");
	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' \
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
	{
		exit_error(game, "Invalid file extension");
	}
	return (fd);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open_file(filename, game);
	line = get_next_line(fd);
	if (!line)
		exit_error(game, "Empty file");
	game->map.width = ft_strlen(line) - 1;
	game->map.arr = ft_strdup_xn(line);
	while (line)
	{
		free(line);
		game->map.height++;
		line = get_next_line(fd);
		if (game->map.width != line_check(line) && line_check(line) != -1)
			exit_error(game, "Map is not rectangular");
		if (line)
			game->map.arr = ft_strjoin_xn(game->map.arr, line);
	}
	error_map(game);
	close(fd);
}
