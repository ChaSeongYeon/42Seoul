/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:05:29 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:42:45 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_map_path(t_game *game)
{
	init_bfs(game);
	bfs(game, game->player.x, game->player.y);
	free(game->check.visited);
	if (game->check.valid_path != 1 || game->check.item_cnt != 0)
		exit_error(game, "There is no valid path on the map");
}

void	init_bfs(t_game *game)
{
	int	i;

	i = 0;
	game->check.visited = (char *)malloc(sizeof(char) * \
	ft_strlen(game->map.arr));
	if (!game->check.visited)
		exit_error(game, "Allocation failed");
	while (i < ft_strlen(game->map.arr))
		game->check.visited[i++] = '0';
}

void	bfs(t_game *game, int x, int y)
{
	const int	dx[4] = {1, 0, 0, -1};
	const int	dy[4] = {0, 1, -1, 0};
	int			nx;
	int			ny;
	int			i;

	game->check.visited[y * game->map.width + x] = '1';
	i = -1;
	if (game->map.arr[y * game->map.width + x] == 'C')
		game->check.item_cnt -= 1;
	if (game->map.arr[y * game->map.width + x] == 'E')
	{
		game->check.valid_path = 1;
		return ;
	}
	while (++i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (game->map.arr[ny * game->map.width + nx] != '1' && \
		game->check.visited[ny * game->map.width + nx] != '1' && \
		(nx >= 0 && nx < game->map.width) && (ny >= 0 && ny < game->map.height))
			bfs(game, nx, ny);
	}
}
