# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 14:53:07 by seocha            #+#    #+#              #
#    Updated: 2023/02/23 16:53:14 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

MANDATORY_DIR = ./mandatory/srcs/

SRCS = pipex.c process.c error.c ft_split.c utils.c ft_strlcpy.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))

OBJS = $(NEW_SRCS:.c=.o)
HEADER = ./mandatory/includes/pipex.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
