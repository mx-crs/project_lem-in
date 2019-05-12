#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/23 17:44:08 by myarovoy          #+#    #+#              #
#    Updated: 2018/09/23 17:44:10 by myarovoy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror
CFLAGS_INC = -I includes/
LIB = libft.a 

FILES = main.c \
		get_data.c \
		get_data1.c \
		add_links.c \
		add_links1.c \
		get_route.c \
		move_lem.c \
		move_lem1.c \
		validation.c \
		validation1.c \
		validation2.c \
		validation3.c

.PHONY = all clean fclean clean re

FILLERSRCS	= $(addprefix src/, $(FILES))

OBJ = $(FILLERSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(CFLAGS_INC) $< -o $@

$(NAME): $(OBJ)
	@make -f makefile.libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32mCreated lem-in, object files and library\033[0m"

clean:
	@rm -rf $(OBJ) $(LIBOBJ)
	@make -f makefile.libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -f makefile.libft fclean
	@echo "\033[32mRemoved lem-in, object Files and library\033[0m"

re: fclean all
