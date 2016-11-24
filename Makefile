# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhusler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 11:20:11 by qhusler           #+#    #+#              #
#    Updated: 2016/11/24 10:47:45 by qhusler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
CFLAGS = -Wall -Wextra -Werror -I./fillit.h
INCLUDES = fillit.h
SRCS = main.c \
	   error.c \
	   parse.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
#	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

clean:
#	make clean -C libft
	rm -f $(OBJS)

fclean: clean
#	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
