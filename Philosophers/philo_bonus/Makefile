# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 15:57:33 by seocha            #+#    #+#              #
#    Updated: 2023/03/01 19:19:25 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

FT_PRINTF_LIBDIR = ./ft_printf
LIBFLAG = -lftprintf -L$(FT_PRINTF_LIBDIR)

MANDATORY_DIR = ./mandatory/srcs/
GNL_DIR = ./get_next_line/

SRCS =
GNL_SRCS = get_next_line.c get_next_line_utils.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))
NEW_GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_SRCS))

OBJS = $(NEW_SRCS:.c=.o)

HEADER = ./includes/philo_bonus.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(LIBFLAG) $(OBJS) -o $(NAME) -I $(HEADER)

clean:
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re