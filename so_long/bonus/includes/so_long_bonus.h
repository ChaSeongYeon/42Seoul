/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:59:23 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:37 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* open */
# include <fcntl.h>

/* open, close, read, write */
# include <unistd.h>

/* malloc, free, exit*/
# include <stdlib.h>

/* perror */
# include <stdio.h>
# include <errno.h>

/* strerror */
# include <string.h>

/* mlx functions*/
# include "../../minilibx_mms_20200219/mlx.h"

/* get_next_line functions */
# include "../../get_next_line/get_next_line.h"

/* ft_printf functions*/
# include "../../ft_printf/ft_printf.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_EXIT 17

typedef struct s_map
{
	char	*arr;
	int		width;
	int		height;
	int		cnt_e;
	int		cnt_p;
	int		cnt_c;
	int		cnt_x;
	int		e_loc;
	int		x_loc;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	loc;
	int	mv_cnt;
	int	get_cnt;
}	t_player;

typedef struct s_img
{
	void	*space;
	void	*wall;
	void	*col;
	void	*exit;
	void	*you;
	void	*enemy_;
}	t_img;

typedef struct s_check
{
	char	*visited;
	int		valid_path;
	int		item_cnt;
}	t_check;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		img;
	t_check		check;
}	t_game;

/* read_map.c functions */
void	read_map(char *filename, t_game *game);

/* draw_map.c functions */
void	put_img(t_game *game, int i, int j, int dir);
void	draw_map(t_game *game);

/* move.c functions */
int		key_hook(int keycode, t_game *game);

/* you_move.c functions */
void	y_move_up(t_game *game, int *dir);
void	y_move_down(t_game *game, int *dir);
void	y_move_left(t_game *game, int *dir);
void	y_move_right(t_game *game, int *dir);

/* enemy_move.c functions */
void	e_move_up(t_game *game);
void	e_move_down(t_game *game);
void	e_move_left(t_game *game);
void	e_move_right(t_game *game);

/* error_free.c functions */
int		put_error(char *str);
int		exit_game(t_game *game);
void	exit_error(t_game *game, char *str);

/* utils.c functions */
int		ft_strlen(const char *s);
char	*ft_strdup_xn(const char *s1);
char	*ft_strjoin_xn(char const *s1, char const *s2);

/* other.c functions */
void	player_loc(t_game *game, int i, int j);
int		line_check(char *line);

/* bfs functions */
void	init_bfs(t_game *game);
void	bfs(t_game *game, int x, int y);
void	error_map_path(t_game *game);
char	*ft_itoa(int n);

#endif