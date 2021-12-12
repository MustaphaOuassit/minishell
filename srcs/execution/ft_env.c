/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:26:11 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/12 18:28:32 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void print_env(t_envp **head)
{
    t_envp *current_node = (*head);
   	while ( current_node != NULL)
    {
        if (current_node->equal)
        {

            ft_putstr_fd(current_node->key, 1);
            ft_putstr_fd("=", 1);
        }
        if (current_node->value)
            ft_putstr_fd(current_node->value, 1);
        ft_putstr_fd("\n", 1);
        current_node = current_node->next;
    }
}

int		ft_env(t_data *data, t_envp **env_list)
{
    (void) data;
    print_env(env_list);
	return (0);
}

int		fetch_fd(t_redirection *red, int *fd, int i_node)
{
	t_redirection *tmp;

	tmp = red;
	while (tmp != NULL)
	{
		//printf("TEST\n");
		if (tmp->type == REDIRECT_IN)
		{
			//if (tmp->file_name)
			fd[0] = open(tmp->file_name, O_RDONLY);
			if (fd[0] == -1)
				return (1);
		}
		if (tmp->type == HEREDOC)
		{
			//if (tmp->file_name)
			fd[0] = open(ft_strjoin("/tmp/heredoc",ft_itoa(i_node)), O_RDONLY);
			if (fd[0] == -1)
				return (1);
		}
		if (tmp->type == REDIRECT_OUT)
		{
			//if (tmp->file_name)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
			if (fd[1] == -1)
				return (1);
		}
		if (tmp->type == APPEND_OUT)
		{
			//if (tmp->file_name)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
			if (fd[1] == -1)
				return (1);
		}

		// printf("filename = %s\n", tmp->file_name);
		// printf("type = %d\n", tmp->type);
		tmp = tmp->next;
	}
	return (0);
}




void	error_command(char	*str)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(" : command not found\n", 2);
	exit(127);
}







void handler_child(int sig)
{
	if (sig == SIGINT)
	{
		//rl_redisplay();
		// rl_replace_line();
		//rl_line_buffer = "ayoub";
		 //rl_redisplay();
		 //rl_replace_line("-> minishell",0);
		//ft_putstr_fd("\n-> minishell ", 1);		
		// printf("Handler child\n");
		//printf("\n");
	}
}
void handler2(int sig)
{
	if (sig)
	{
		printf("parent with child\n");
	}
}
