# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 15:57:33 by seocha            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/04/01 22:06:32 by seocha           ###   ########.fr        #
=======
#    Updated: 2023/04/07 14:35:04 by seocha           ###   ########.fr        #
>>>>>>> bc56cb4d15d3a7bd7b8ab361120bcd3a6d34e47f
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

NAME = philo

MANDATORY_DIR = ./srcs/

SRCS = philo.c simul.c utils.c error_free.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))

OBJS = $(NEW_SRCS:.c=.o)

HEADER = ./includes/philo.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re