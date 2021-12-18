/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:59:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/18 12:14:25 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    fill_heredoc_file(int i_node, t_redirection *tmp1, t_envp *list)
{
    int fd_heredoc;   
    char *str;
    char *name;

    name = ft_itoa(i_node);    
    str = ft_strjoin("/tmp/heredoc", name);
    fd_heredoc = open(str, O_TRUNC | O_CREAT| O_WRONLY, 0777);
    free(name);
    free(str);
    while (1)
    {
        str = readline(">");
        if (!str)
        {
            printf("STR\n");
            exit(1);
        }
        if (ft_strcmp(tmp1->file_name, str) == 0)
            break;
        if (tmp1->type == HEREDOC)
            str = ft_free_first(str,expand_value(str, list));
        ft_putstr_fd(str, fd_heredoc);
        ft_putchar_fd('\n', fd_heredoc);
        free(str);
    }
    // exit(0);
}

void    heredoc_child(t_data *data, t_envp *list)
{
    t_data *tmp;
    t_redirection *tmp1;
	int i_node;
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
    //printf("TEST\n");
}

int     here_document(t_data *data, t_envp *list)
{	
    int status;
    int pid;

    pid = fork();
	if (pid == 0)
	{
		heredoc_child(data, list);
        // close(0);
		exit(0);
	}
	else
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
    if (WEXITSTATUS(status) == 1)
    {
        // int fd = dup(0);
        //close(0);
        // dup2(fd, 0);
            //rl_replace_line("\n",0);

        // close(0);  
        	free_data(&data);

 			list->exit_status = 1;

        return (1);
    }
    if (WIFSIGNALED(status)) 
	{
		if (WTERMSIG(status) == 2)
        {
            // int fd = dup(0);
            //close(0);
            rl_redisplay();
            // dup2(fd, 0);
            // printf("HELLO\n");
            // printf(">\n");
            			free_data(&data);

            			list->exit_status = 1;
			return(1);
        }
    }
    return (0);
}
