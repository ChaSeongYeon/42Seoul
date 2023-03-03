/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:45:35 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:42:57 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->map.arr = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.cnt_e = 0;
	game->map.cnt_p = 0;
	game->map.cnt_c = 0;
	game->map.e_loc = 0;
	game->img.space = 0;
	game->img.wall = 0;
	game->img.col = 0;
	game->img.exit = 0;
	game->img.you = 0;
	game->player.loc = 0;
	game->player.mv_cnt = 0;
	game->player.get_cnt = 0;
	game->check.visited = 0;
	game->check.valid_path = 0;
	game->check.item_cnt = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (put_error("Argument error"));
	init_game(&game);
	read_map(argv[1], &game);
	draw_map(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &key_hook, &game);
	mlx_hook(game.win, KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
