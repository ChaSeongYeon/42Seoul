# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:08:20 by seocha            #+#    #+#              #
#    Updated: 2023/01/06 11:09:12 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libgnl.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME): make_mandatory

clean:
	rm -f $(OBJS)
	rm -f make_mandatory

fclean: clean
	rm -f $(NAME)

re: fclean all

make_mandatory: $(OBJS)
	ar rc $(NAME) $(OBJS)
	touch $@

.PHONY: all clean fclean re