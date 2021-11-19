/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:03:18 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/19 16:03:21 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libraries/libft/libft.h"
# include <fcntl.h>


typedef struct s_envp{
	char    *key;
	char    *value;
	int     equal;
	struct s_envp *next;
}   t_envp;
	typedef struct s_redirection_x{
		char *filename;
		int    type;
		struct s_redirection_x *next;
	} t_redirection_x;

typedef        struct s_data_x{
	char    **line_cmd;
	char    **arguments;
	t_redirection_x *red;
	struct s_data_x *next;
}        t_data_ex;
void	ft_cd(t_data_ex *data);
void	ft_pwd();
void    ft_env(t_data_ex *data, t_envp **var);
int		ft_echo(t_data_ex *data);
void	ft_export(t_data_ex *data, t_envp **env_list);
void	add_str_to_node(t_envp **head, char *str);
void	add_to_env(t_envp **head, t_envp *node);
t_envp* fill_envp(char *str);
int     env_key_error(char *var);
void ft_unset(char **args, t_envp **env_list);
void    free_envp(t_envp *env);
int		fetch_fd(t_redirection_x *red, int **fd);
void	ft_exit();
#endif