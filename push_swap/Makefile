# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 09:12:45 by seocha            #+#    #+#              #
#    Updated: 2023/02/23 16:21:17 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

FT_PRINTF_LIBDIR = ./ft_printf
LIBFLAG = -lftprintf -L$(FT_PRINTF_LIBDIR)

MANDATORY_DIR = ./mandatory/srcs/
BONUS_DIR = ./bonus/srcs/
GNL_DIR = ./get_next_line/

SRCS = push_swap.c push_pop.c sort.c greedy_sort.c operate1.c operate2.c \
		operate3.c error_free.c utils1.c utils2.c
BONUS_SRCS = checker_bonus.c push_pop_bonus.c operate1_bonus.c \
			operate2_bonus.c operate3_bonus.c error_free_bonus.c \
			utils1_bonus.c utils2_bonus.c
GNL_SRCS = get_next_line.c get_next_line_utils.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))
NEW_BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS)) $(NEW_GNL_SRCS)
NEW_GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_SRCS))

OBJS = $(NEW_SRCS:.c=.o)
BONUS_OBJS = $(NEW_BONUS_SRCS:.c=.o)

HEADER = ./mandatory/includes/push_swap.h
BONUS_HEADER = ./bonus/includes/checker_bonus.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(LIBFLAG) $(OBJS) -o $(NAME) -I $(HEADER)

clean:
	make -C ./ft_printf clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make -C ./ft_printf fclean

re: fclean all

bonus: $(BONUS_OBJS) $(BONUS_HEADER)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(LIBFLAG) $(BONUS_OBJS) -o $(BONUS_NAME) \
	-I $(BONUS_HEADER)

.PHONY: all clean fclean re bonus