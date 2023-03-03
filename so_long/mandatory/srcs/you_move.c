/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:55:23 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:42:58 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	change_map(t_game *game, int dir)
{
	if (dir == 1)
	{
		game->map.arr[game->player.loc] = '0';
		game->map.arr[game->player.loc - game->map.width] = 'P';
	}
	else if (dir == 2)
	{
		game->map.arr[game->player.loc] = '0';
		game->map.arr[game->player.loc - 1] = 'P';
	}
	else if (dir == 3)
	{
		game->map.arr[game->player.loc] = '0';
		game->map.arr[game->player.loc + game->map.width] = 'P';
	}
	else if (dir == 4)
	{
		game->map.arr[game->player.loc] = '0';
		game->map.arr[game->player.loc + 1] = 'P';
	}
	game->player.mv_cnt++;
}

void	y_move_up(t_game *game, int *dir)
{
	*dir = 1;
	if (game->map.arr[game->player.loc - game->map.width] != '1')
	{
		if (game->map.arr[game->player.loc - game->map.width] == 'C')
			game->player.get_cnt++;
		if (game->map.arr[game->player.loc - game->map.width] == 'E')
		{
			if (game->map.cnt_c == game->player.get_cnt)
			{
				ft_printf("%s\n", "Game Clear!!");
				exit_game(game);
			}
			change_map(game, *dir);
		}
		else if (game->map.arr[game->player.loc - game->map.width] != 'E')
		{
			change_map(game, *dir);
			game->map.arr[game->map.e_loc] = 'E';
		}
	}
}

void	y_move_left(t_game *game, int *dir)
{
	*dir = 2;
	if (game->map.arr[game->player.loc - 1] != '1')
	{
		if (game->map.arr[game->player.loc - 1] == 'C')
			game->player.get_cnt++;
		if (game->map.arr[game->player.loc - 1] == 'E')
		{
			if (game->map.cnt_c == game->player.get_cnt)
			{
				ft_printf("%s\n", "Game Clear!!");
				exit_game(game);
			}
			change_map(game, *dir);
		}
		else if (game->map.arr[game->player.loc - 1] != 'E')
		{
			change_map(game, *dir);
			game->map.arr[game->map.e_loc] = 'E';
		}
	}
}

void	y_move_down(t_game *game, int *dir)
{
	*dir = 3;
	if (game->map.arr[game->player.loc + game->map.width] != '1')
	{
		if (game->map.arr[game->player.loc + game->map.width] == 'C')
			game->player.get_cnt++;
		if (game->map.arr[game->player.loc + game->map.width] == 'E')
		{
			if (game->map.cnt_c == game->player.get_cnt)
			{
				ft_printf("%s\n", "Game Clear!!");
				exit_game(game);
			}
			change_map(game, *dir);
		}
		else if (game->map.arr[game->player.loc + game->map.width] != 'E')
		{
			change_map(game, *dir);
			game->map.arr[game->map.e_loc] = 'E';
		}
	}
}

void	y_move_right(t_game *game, int *dir)
{
	*dir = 4;
	if (game->map.arr[game->player.loc + 1] != '1')
	{
		if (game->map.arr[game->player.loc + 1] == 'C')
			game->player.get_cnt++;
		if (game->map.arr[game->player.loc + 1] == 'E')
		{
			if (game->map.cnt_c == game->player.get_cnt)
			{
				ft_printf("%s\n", "Game Clear!!");
				exit_game(game);
			}
			change_map(game, *dir);
		}
		else if (game->map.arr[game->player.loc + 1] != 'E')
		{
			change_map(game, *dir);
			game->map.arr[game->map.e_loc] = 'E';
		}
	}
}
