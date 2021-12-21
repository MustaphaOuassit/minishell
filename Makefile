# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 13:06:02 by mouassit          #+#    #+#              #
#    Updated: 2021/12/21 12:26:54 by ayafdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC =./srcs/main.c \
	  ./srcs/parsing/parsing.c \
	  ./srcs/parsing/linkedlist.c \
	  ./srcs/parsing/fill_data.c \
	  ./srcs/parsing/add_dollar.c \
	  ./srcs/parsing/check_dlm.c \
	  ./srcs/parsing/check_indice.c\
	  ./srcs/parsing/check_position.c \
	  ./srcs/parsing/check_status.c \
	  ./srcs/parsing/continue_dollar.c \
	  ./srcs/parsing/dollar_handler.c \
	  ./srcs/parsing/error_redirection.c \
	  ./srcs/parsing/error_value.c \
	  ./srcs/parsing/file_args.c \
	  ./srcs/parsing/fill_convert.c \
	  ./srcs/parsing/fill_data_ambiguous.c \
	  ./srcs/parsing/fill_file.c \
	  ./srcs/parsing/filter_value.c\
	  ./srcs/parsing/get_allocation.c\
	  ./srcs/parsing/get_dollar_value.c \
	  ./srcs/parsing/get_env.c \
	  ./srcs/parsing/get_token.c \
	  ./srcs/parsing/initialisation.c \
	  ./srcs/parsing/is_couts.c \
	  ./srcs/parsing/list_tokens.c \
	  ./srcs/parsing/redirection_token.c \
	  ./srcs/parsing/skip_spaces.c \
	  ./srcs/parsing/skip_string.c \
	  ./srcs/parsing/skip_value.c\
	  ./srcs/parsing/parsing_errors.c \
	  ./srcs/execution/ft_exit.c \
	  ./srcs/execution/ft_unset.c \
	  ./srcs/execution/ft_echo.c \
	  ./srcs/execution/ft_pwd.c \
	  ./srcs/execution/ft_cd.c \
	  ./srcs/execution/ft_export.c \
	  ./srcs/execution/ft_env.c \
	   ./srcs/execution/ft_builtins.c \
	   ./srcs/execution/builtin_only.c \
	   ./srcs/execution/fetch_envp.c \
	   ./srcs/execution/heredoc.c \
	   ./srcs/execution/pipeline.c \
	   ./srcs/execution/ft_execute.c \
	   ./srcs/execution/signals.c \
	   ./srcs/execution/fetch_pwd.c \
	   ./srcs/execution/error_return.c \

LIBFT = ./libft/libft.a

READLINE = -lreadline  -L /goinfre/$(USER)/$(USER)/.brew/opt/readline/lib \
	-I /goinfre/$(USER)/$(USER)/.brew/opt/readline/include

all : $(NAME)

$(NAME): $(SRC)
	@make -s -C ./libft
	@gcc -Wall -Wextra -Werror -g $(READLINE) $(SRC) $(LIBFT) -o $(NAME)


clean:
	@make -s -C ./libft clean

fclean: clean
	@make -s -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all