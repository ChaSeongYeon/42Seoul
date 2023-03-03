/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:28:49 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:51 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	game_free(t_game *game)
{
	if (game->img.space)
		mlx_destroy_image(game->mlx, game->img.space);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.col)
		mlx_destroy_image(game->mlx, game->img.col);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.you)
		mlx_destroy_image(game->mlx, game->img.you);
	if (game->img.enemy_)
		mlx_destroy_image(game->mlx, game->img.enemy_);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.arr)
		free(game->map.arr);
}

int	put_error(char *str)
{
	perror(str);
	return (1);
}

int	exit_game(t_game *game)
{
	game_free(game);
	exit(0);
	return (0);
}

void	exit_error(t_game *game, char *str)
{
	write(2, "Error\n", 6);
	game_free(game);
	perror(str);
	exit(1);
}
