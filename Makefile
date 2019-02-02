# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 11:57:34 by jcorwin           #+#    #+#              #
#    Updated: 2019/02/02 18:16:32 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
SOURCE_PATH = ./srcs/
SOURCE = args.c debug.c get_next_line.c list.c oper.c psw.c simple.c step.c
SRC = $(addprefix $(SOURCE_PATH), $(SOURCE))
OBJ = $(SOURCE:.c=.o)
INCLUDE_PATH = ./includes/
INCLUDE = ft_printf.h get_next_line.h libft.h push_swap.h
INC = $(addprefix $(INCLUDE_PATH), $(INCLUDE))
FLAGS = -Wall -Werror -Wextra

all: libs $(NAME1) $(NAME2)

$(NAME1): $(SRC) $(INC)
	gcc -o $(NAME1) srcs/push_swap.c $(SRC) -L ./libft/ -lft -L ./ft_printf/ -lftprintf

$(NAME2): $(SRC) $(INC)
	gcc -o $(NAME2) srcs/checker.c $(SRC) -L ./libft/ -lft -L ./ft_printf/ -lftprintf

libs:
	cd libft/ && make
	cd ft_printf/ && make

clean:
	cd libft/ && make clean
	cd ft_printf/ && make clean

fclean:
	cd libft/ && make fclean
	cd ft_printf/ && make fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all
