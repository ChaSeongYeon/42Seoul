# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 08:58:10 by seocha            #+#    #+#              #
#    Updated: 2022/12/07 15:24:39 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a

SRCS = ft_printf.c ft_mandatory1.c ft_mandatory2.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

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
