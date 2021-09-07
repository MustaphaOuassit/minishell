# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 13:06:02 by mouassit          #+#    #+#              #
#    Updated: 2021/09/07 13:50:16 by mouassit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = ./libraries/get_next_line/get_next_line.c \
	  ./libraries/get_next_line/get_next_line_utils.c \
	  ./srcs/parsing/check_couts.c \
	  ./srcs/parsing/check_word.c \
      ./srcs/parsing/parsing.c \
	  ./srcs/parsing/lexer.c \
	  ./srcs/parsing/parser.c


LIBFT = ./libraries/libft/libft.a

all : $(NAME)

$(NAME):
	@make -s -C ./libraries/libft
	@gcc -Wall -Wextra -Werror -I .  $(SRC) $(LIBFT) -D BUFFER_SIZE=1 -o $(NAME)


clean:
	@make -s -C ./libraries/libft clean

fclean: clean
	@make -s -C ./libraries/libft fclean
	@rm -rf $(NAME)

re: fclean all