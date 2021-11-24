/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:55:14 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/24 10:22:26 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../libraries/libft/libft.h"
# include <fcntl.h>


typedef struct s_envp{
	char    *key;
	char    *value;
	int     equal;
	struct s_envp *next;
}   t_envp;



typedef struct s_initialisation
{
	int	i;
	int	t;
	int	len;
	int	sword;
}				t_initial;
char	*g_cmd;
char	*g_str;
int		g_start;
int		g_rmp;
int		g_toll;

typedef		struct s_tokens{
	char	*value;
	int		type;
	struct s_tokens *next;
}		t_tokens;

typedef		struct s_redirection{
	char	*file_name;
	int		type;
	struct s_redirection *next;
}			t_redirection;

typedef		struct s_data{
	t_tokens	**line_cmd;
	char	**arguments;
	t_redirection *redirection;
	struct s_data *next;
}		t_data;

//exec
void	ft_builtins(t_data *data, t_envp **env_list);
int		is_builtin(char *cmd);
int		exec_cmd(t_data *data, char **envp);
void	ft_cd(t_data *data);
void	ft_pwd();
void    ft_env(t_data *data, t_envp **var);
int		ft_echo(t_data *data);
void	ft_export(t_data *data, t_envp **env_list);
void	add_str_to_node(t_envp **head, char *str);
void	add_to_env(t_envp **head, t_envp *node);
t_envp* fill_envp(char *str);
int     env_key_error(char *var);
void ft_unset(char **args, t_envp **env_list);
void    free_envp(t_envp *env);
int		fetch_fd(t_redirection *red, int **fd);
void	ft_exit();
int		builtin_only(t_data *data, t_envp **env_list);
int     fetch_envp(t_envp **env_list, char **envp);



//parsing
int				skipe_space(void);
void			token_manipulation(t_data **data, int indice);
int				put_in_parcer(t_tokens **head, char *value, int type);
int				check_arrow(t_tokens **head, int indice);
int				add_to_string(int indice, char *ele, char **couts);
int				add_to_string_double(int indice, char *ele, char **couts);
void			fill_string_double(int indice, int ele, char **dbcouts);
int				check_couts(int indice);
void			check_alloc(int indice,char *str,int *l);
char			*continue_check(int len, int sword);
int				check_word(t_tokens **head, int indice);
void			fill_data(t_data **dt ,t_tokens *data);
char			*get_env(char *value);
int		   		fill_linkdlist(t_data **head, t_tokens **data);


#endif