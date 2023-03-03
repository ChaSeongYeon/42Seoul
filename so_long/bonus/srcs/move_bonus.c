/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:19:29 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:54 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	void	move_up(t_game *game, int *dir)
{
	y_move_up(game, dir);
	e_move_down(game);
}

static	void	move_left(t_game *game, int *dir)
{
	y_move_left(game, dir);
	e_move_right(game);
}

static	void	move_down(t_game *game, int *dir)
{
	y_move_down(game, dir);
	e_move_up(game);
}

static	void	move_right(t_game *game, int *dir)
{
	y_move_right(game, dir);
	e_move_left(game);
}

int	key_hook(int keycode, t_game *game)
{
	int	dir;

	dir = 1;
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		move_up(game, &dir);
	if (keycode == KEY_A)
		move_left(game, &dir);
	if (keycode == KEY_S)
		move_down(game, &dir);
	if (keycode == KEY_D)
		move_right(game, &dir);
	put_img(game, -1, -1, dir);
	mlx_string_put(game->mlx, game->win, 16, 16, 0x000000, \
			ft_itoa(game->player.mv_cnt));
	return (0);
}
