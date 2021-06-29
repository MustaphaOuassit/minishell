# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 13:06:02 by mouassit          #+#    #+#              #
#    Updated: 2021/06/29 18:26:34 by mouassit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = ./libraries/get_next_line/get_next_line.c \
	  ./libraries/get_next_line/get_next_line_utils.c \
      ./srcs/parcing/parcing.c


LIBFT = ./libraries/libft/libft.a

all : $(NAME)

$(NAME):
	@make -C ./libraries/libft
	@gcc -Wall -Wextra -Werror -I . $(SRC) $(LIBFT) -D BUFFER_SIZE=1 -o $(NAME)


clean:
	@make -C ./libraries/libft clean

fclean: clean
	@make -C ./libraries/libft fclean
	@rm -rf $(NAME)

re: fclean all