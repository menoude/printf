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

all: $(NAME) test.o
	gcc test.o $(NAME) #a enlever
	@./a.out #a enlever

test.o: test.c
	gcc -Wall -Werror -Wextra -c $<

$(NAME): $(BINARIES)
	$(MAKE) -C $(DIR_LIB)
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(BINARIES)

%.o: %.c
	gcc -Wall -Werror -Wextra -c $<

clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES) test.o ##a enlever
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME) a.out #a enlever
re: fclean all

.PHONY: all clean fclean re%
