# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 16:02:19 by seocha            #+#    #+#              #
#    Updated: 2023/02/23 17:03:23 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

MANDATORY_DIR = ./mandatory/srcs/
BONUS_DIR = ./bonus/srcs

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	   ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	   ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c  \
	   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c   
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
			ft_lstsize.c

NEW_SRCS = $(addprefix $(MANDATORY_DIR), $(SRCS))
NEW_BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS))

OBJS = $(NEW_SRCS:.c=.o)
BONUS_OBJS = $(NEW_BONUS_SRCS:.c=.o)

HEADER = ./includes/libft.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME): make_mandatory

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f make_bonus make_mandatory

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: make_bonus

make_mandatory: $(OBJS)
	ar rc $(NAME) $(OBJS)
	touch $@

make_bonus: $(BONUS_OBJS)
	ar rc $(NAME) $^
	touch $@

.PHONY: all clean fclean re bonus
