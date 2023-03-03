# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 07:59:20 by seocha            #+#    #+#              #
#    Updated: 2023/02/23 16:43:48 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework Appkit

NAME = so_long

GNL_LIBDIR = ./get_next_line
MLX_LIBDIR = ./minilibx_mms_20200219
FT_PRINTF_LIBDIR = ./ft_printf
LIBFLAG = -lmlx -lftprintf -lgnl -L$(MLX_LIBDIR) -L$(FT_PRINTF_LIBDIR) \
 -L$(GNL_LIBDIR)

MANDATORY_DIR = ./mandatory/srcs/
BONUS_DIR = ./bonus/srcs/

SRCS = so_long.c read_map.c draw_map.c you_move.c error_free.c utils.c bfs.c \
		move.c others.c
BONUS_SRCS = so_long_bonus.c read_map_bonus.c draw_map_bonus.c \
			you_move_bonus.c error_free_bonus.c utils_bonus.c bfs_bonus.c \
			enemy_move_bonus.c move_bonus.c others_bonus.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))
NEW_BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS))

OBJS = $(NEW_SRCS:.c=.o)
BONUS_OBJS = $(NEW_BONUS_SRCS:.c=.o)

HEADER = ./mandatory/includes/so_long.h
BONUS_HEADER = ./bonus/includes/so_long_bonus.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C ./ft_printf
	make -C ./get_next_line
	make -C ./minilibx_mms_20200219
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAG) $(OBJS) -o $(NAME) -I $(HEADER)
	touch make_mandatory

clean:
	make -C ./ft_printf clean
	make -C ./get_next_line clean
	make -C ./minilibx_mms_20200219 clean
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f make_bonus make_mandatory

fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf fclean
	make -C ./get_next_line fclean

re: fclean all

bonus: make_bonus

make_bonus: $(BONUS_OBJS) $(BONUS_HEADER)
	make -C ./ft_printf
	make -C ./get_next_line
	make -C ./minilibx_mms_20200219
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAG) $(BONUS_OBJS) -o $(NAME) -I $(BONUS_HEADER)
	touch $@

.PHONY: all clean fclean re bonus make_mandatory
