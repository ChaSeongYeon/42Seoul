/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:54:46 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:42:52 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	dir;

	dir = 1;
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		y_move_up(game, &dir);
	if (keycode == KEY_A)
		y_move_left(game, &dir);
	if (keycode == KEY_S)
		y_move_down(game, &dir);
	if (keycode == KEY_D)
		y_move_right(game, &dir);
	put_img(game, -1, -1, dir);
	ft_printf("move count : %d\n", game->player.mv_cnt);
	return (0);
}
