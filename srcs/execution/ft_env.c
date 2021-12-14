/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:26:11 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/14 10:40:55 by ayafdel          ###   ########.fr       */
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

int fetch_heredoc(t_redirection *tmp, int *fd, int i_node)
{
	char *heredoc_file;

	if (tmp->type == HEREDOC)
	{
		//if (tmp->file_name)
		heredoc_file = ft_strjoin("/tmp/heredoc", ft_itoa(i_node));
		fd[0] = open(heredoc_file, O_RDONLY);
		free(heredoc_file);
		if (fd[0] == -1)
			return (1);
	}
	return (0);
}

int		fetch_fd(t_redirection *red, int *fd, int i_node)
{
	t_redirection *tmp;

	tmp = red;
	while (tmp != NULL)
	{
		if (tmp->type == REDIRECT_IN)
			fd[0] = open(tmp->file_name, O_RDONLY);
			if (fd[0] == -1)
				return (1);
		if (fetch_heredoc(tmp, fd, i_node) == 1)
			return (1);
		if (tmp->type == REDIRECT_OUT)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd[1] == -1)
			return (1);
		if (tmp->type == APPEND_OUT)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
		if (fd[1] == -1)
			return (1);
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








