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
SRC = ft_printf.c
HEADER = ft_printf.h
BINARIES =	$(SRC:.c=.o)

all: $(NAME)
	./a.out
$(NAME): $(BINARIES) test.o
	$(MAKE) -C $(DIR_LIB)
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(BINARIES)
	gcc test.o $(NAME)

test.o: test.c
	gcc -Wall -Werror -Wextra -c $<

%.o: %.c
	gcc -Wall -Werror -Wextra -c $<
clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES)
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re%
