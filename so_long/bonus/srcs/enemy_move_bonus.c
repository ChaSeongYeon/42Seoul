/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:19:36 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:48 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	e_move_up(t_game *game)
{
	int	p_w;
	int	p_h;

	if (game->map.arr[game->map.x_loc - game->map.width] != '1' && \
		game->map.arr[game->map.x_loc - game->map.width] == '0')
	{
		game->map.arr[game->map.x_loc] = '0';
		game->map.arr[game->map.x_loc - game->map.width] = 'X';
		game->map.x_loc -= game->map.width;
		game->img.enemy_ = mlx_xpm_file_to_image(game->mlx, \
		"./images/__enemy_u.xpm", &p_w, &p_h);
	}
}

void	e_move_left(t_game *game)
{
	int	p_w;
	int	p_h;

	if (game->map.arr[game->map.x_loc - 1] != '1' && \
		game->map.arr[game->map.x_loc - 1] == '0')
	{
		game->map.arr[game->map.x_loc] = '0';
		game->map.arr[game->map.x_loc - 1] = 'X';
		game->map.x_loc -= 1;
		game->img.enemy_ = mlx_xpm_file_to_image(game->mlx, \
		"./images/__enemy_l.xpm", &p_w, &p_h);
	}
}

void	e_move_down(t_game *game)
{
	int	p_w;
	int	p_h;

	if (game->map.arr[game->map.x_loc + game->map.width] != '1' && \
		game->map.arr[game->map.x_loc + game->map.width] == '0')
	{
		game->map.arr[game->map.x_loc] = '0';
		game->map.arr[game->map.x_loc + game->map.width] = 'X';
		game->map.x_loc += game->map.width;
		game->img.enemy_ = mlx_xpm_file_to_image(game->mlx, \
		"./images/__enemy_d.xpm", &p_w, &p_h);
	}
}

void	e_move_right(t_game *game)
{
	int	p_w;
	int	p_h;

	if (game->map.arr[game->map.x_loc + 1] != '1' && \
		game->map.arr[game->map.x_loc + 1] == '0')
	{
		game->map.arr[game->map.x_loc] = '0';
		game->map.arr[game->map.x_loc + 1] = 'X';
		game->map.x_loc += 1;
		game->img.enemy_ = mlx_xpm_file_to_image(game->mlx, \
		"./images/__enemy_r.xpm", &p_w, &p_h);
	}
}
