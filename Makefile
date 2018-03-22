# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meyami <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 22:14:03 by meyami            #+#    #+#              #
#    Updated: 2018/01/05 22:14:06 by meyami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
DIR_LIB = libft
DIR_SRC = srcs
SRC = ft_printf.c helper.c itoa.c initializer.c buffer.c converter.c \
		format.c width.c precision.c length.c type.c type_dec.c type_chars.c\
		type_base.c type_others.c
HEADER = ft_printf.h
BINARIES =	$(SRC:.c=.o)
CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(BINARIES)
	$(MAKE) -C $(DIR_LIB)
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(BINARIES)

%.o: %.c
	$(CC) -c $<

clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES)
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re%
