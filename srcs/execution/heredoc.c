/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:59:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/20 11:55:07 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_heredoc(char *str, int fd_heredoc, t_envp *list)
{
	ft_putstr_fd(str, fd_heredoc);
	ft_putchar_fd('\n', fd_heredoc);
	free(str);
	free_itmes(&list->allocation);
}

void	fill_heredoc_file(int i_node, t_redirection *tmp1, t_envp *list)
{
	int		fd_heredoc;
	char	*str;
	char	*name;

	name = ft_itoa(i_node);
	str = ft_strjoin("/tmp/heredoc", name);
	fd_heredoc = open(str, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	free(name);
	free(str);
	while (1)
	{
		str = readline(">");
		if (!str)
			exit(1);
		if (ft_strcmp(tmp1->file_name, str) == 0)
		{
			free(str);
			break ;
		}
		if (tmp1->type == HEREDOC)
			str = ft_free_first(str, expand_value(str, list));
		print_heredoc(str, fd_heredoc, list);
	}
}

void	heredoc_child(t_data *data, t_envp *list)
{
	t_data			*tmp;
	t_redirection	*tmp1;
	int				i_node;

	i_node = 0;
	tmp = data;
	ft_signal(HEREDOC_SIG);
	while (tmp)
	{
		tmp1 = tmp->redirection;
		while (tmp1)
		{
			if (tmp1->type == HEREDOC || tmp1->type == HEREDOC_WO_EXPANSION)
			{
				fill_heredoc_file(i_node, tmp1, list);
			}
			tmp1 = tmp1->next;
		}
		i_node++;
		tmp = tmp->next;
	}
}

int	heredoc_status(int status, t_data **data, t_envp *list)
{
	if (WEXITSTATUS(status) == 1)
	{
		free_data(data);
		list->exit_status = 1;
		return (1);
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
		{
			rl_redisplay();
			free_data(data);
			list->exit_status = 1;
			return (1);
		}
	}
	return (0);
}

int	here_document(t_data	**data, t_envp	*list)
{	
	int	status;
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		heredoc_child(*data, list);
		exit(0);
	}
	else
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
	return (heredoc_status(status, data, list));
}
