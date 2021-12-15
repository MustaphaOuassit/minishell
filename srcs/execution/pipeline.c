/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:14:29 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/14 18:09:34 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_dup(int *fd)
{
	if (fd[0] != 0)
	{
		//printf("TEST\n");
		dup2(fd[0], STDIN_FILENO);
		// printf("fd[0] =%d  \n", fd[0]);	
		close(fd[0]);
	}
	if (fd[1] != 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
}

int     child_status(int pid)
{
    int status;

	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	if (WIFSIGNALED(status)) 
	{
		if (WTERMSIG(status) == 2)
		{
			printf("\n");
			return(WTERMSIG(status) + 128);
    		//printf("signal CTRL+C \n");
		}
		if (WTERMSIG(status) == 3)
		{
			write(2, "Quit: 3", 7);
			return(WTERMSIG(status) + 128);
		}
  	}
  	while(wait(0) > 0);
	return (WEXITSTATUS(status));
}

int     child_execute(t_data *data, t_pipe p, int i_node, t_envp **env_list)
{
    int fd[2];
    
    fd[0] = 0;
    fd[1] = 1;
			//while(1);	//child_process function : declare fd inside it
    fd[0] = p.tmp;
    if (data->next != NULL)
        fd[1] = p.fd[1];
    if (fetch_fd(data->redirection, fd, i_node) == 1)
        return (1);
    if (is_builtin(data->arguments[0]))
    {
        ft_dup(fd);
        exit(ft_builtins(data, env_list));
    }
    close(p.fd[0]);
    exit(ft_execute(data->arguments, fd, env_list));
}

int		ft_pipeline(t_data *data, t_envp **env_list)
{
    t_pipe p;
	int pid;
	int i_node;

	i_node = 0;
	p.tmp = 0;
	while (data)
	{
		pipe(p.fd);
		pid = fork();
		if (pid == 0)
            child_execute(data, p, i_node, env_list);
		else
		{
			if (p.tmp != 0)
				close(p.tmp);
			close(p.fd[1]);
			p.tmp = p.fd[0];
		}
		i_node++;
		data = data->next;
	}
    return (child_status(pid));
}
