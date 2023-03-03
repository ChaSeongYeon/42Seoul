/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:45:33 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:45 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	img_16(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * 16, y * 16);
}

static void	get_img(t_game *game)
{
	int	p_w;
	int	p_h;

	game->img.space = mlx_xpm_file_to_image(game->mlx, "./images/__space.xpm", \
					&p_w, &p_h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./images/__wall.xpm", \
					&p_w, &p_h);
	game->img.col = mlx_xpm_file_to_image(game->mlx, "./images/__collect.xpm", \
					&p_w, &p_h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./images/__exit.xpm", \
					&p_w, &p_h);
	game->img.you = mlx_xpm_file_to_image(game->mlx, "./images/__you_d.xpm", \
					&p_w, &p_h);
	game->img.enemy_ = mlx_xpm_file_to_image(game->mlx, \
					"./images/__enemy_d.xpm", &p_w, &p_h);
}

static void	you_direct(t_game *game, int dir)
{
	int	p_w;
	int	p_h;

	if (dir == 1)
	{
		game->img.you = mlx_xpm_file_to_image(game->mlx, \
		"./images/__you_u.xpm", &p_w, &p_h);
	}
	else if (dir == 2)
	{
		game->img.you = mlx_xpm_file_to_image(game->mlx, \
		"./images/__you_l.xpm", &p_w, &p_h);
	}
	else if (dir == 3)
	{	
		game->img.you = mlx_xpm_file_to_image(game->mlx, \
		"./images/__you_d.xpm", &p_w, &p_h);
	}
	else if (dir == 4)
	{	
		game->img.you = mlx_xpm_file_to_image(game->mlx, \
		"./images/__you_r.xpm", &p_w, &p_h);
	}
}

void	put_img(t_game *game, int i, int j, int dir)
{
	while (++j < game->map.height)
	{
		i = -1;
		while (++i < game->map.width)
		{
			if (game->map.arr[j * game->map.width + i] == '0')
				img_16(game, game->img.space, i, j);
			else if (game->map.arr[j * game->map.width + i] == '1')
				img_16(game, game->img.wall, i, j);
			else if (game->map.arr[j * game->map.width + i] == 'C')
				img_16(game, game->img.col, i, j);
			else if (game->map.arr[j * game->map.width + i] == 'E')
				img_16(game, game->img.exit, i, j);
			else if (game->map.arr[j * game->map.width + i] == 'X')
				img_16(game, game->img.enemy_, i, j);
			else if (game->map.arr[j * game->map.width + i] == 'P')
			{
				you_direct(game, dir);
				player_loc(game, i, j);
				img_16(game, game->img.you, i, j);
			}
			else
				exit_error(game, "Invalid component");
		}	
	}
}

void	draw_map(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_error(game, "Failed to initialize connection");
	get_img(game);
	if (!(game->img.space) || !(game->img.wall) || \
		!(game->img.col) || !(game->img.exit) || !(game->img.you))
		exit_error(game, "Failed to get images");
	game->win = mlx_new_window(game->mlx, game->map.width * 16, \
		game->map.height * 16, "my new game");
	if (!(game->win))
		exit_error(game, "Failed to create a new window");
	put_img(game, -1, -1, 3);
	error_map_path(game);
}
