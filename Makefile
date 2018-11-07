#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdagnaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 16:59:07 by rdagnaud          #+#    #+#              #
#    Updated: 2018/10/06 22:50:31 by rdagnaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -g
OPTIONS = -c
FLAGS = -Wall -Wextra -Werror
LIBSOBJS = libft/*.o
SRCS = $(SRCPATH)ft_printf.c
SRCPATH = srcs/
OBJS = $(SRCS:.c=.o)
RM = rm -rf

MAKEFLAGS = s

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : $(NAME)

%.o: %.c
	@echo ${Y}Compiling [$@]...${X}
	@$(CC) $(FLAGS) -c $< -o $@
	@printf ${UP}${CUT}

$(NAME) : $(OBJS)
	@make -C ./libft/
	@ar rc $(NAME) $(OBJS) $(LIBSOBJS) 
	@ranlib $(NAME)
	@echo "\033[01;32mCompilation de la libft OK.\033[0m"

clean :
	@$(RM) $(OBJS)
	@echo "\033[01;31mSuppression des objest OK.\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[01;31mSuppression de l'executable OK.\033[0m"

re : fclean all

.PHONY: all re fclean clean
