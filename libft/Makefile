# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/06 02:00:45 by qhusler           #+#    #+#              #
#    Updated: 2016/11/19 15:47:46 by qhusler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Werror -Wextra
INCLUDES = libft.h 
SRCS = 	ft_putchar.c \
		ft_putchar_fd.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isspace.c \
		ft_isblank.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strnew.c \
		ft_strdup.c \
		ft_strdel.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strlcat.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstpushback.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_putstrc.c \
		ft_xrotn.c \
		ft_xntor.c
	
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
