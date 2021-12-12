/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:59:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/12 12:12:37 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    fill_heredoc_file(int i_node, t_redirection *tmp1)
{
    int fd_heredoc;   
    char *str;
    char *buf = ft_calloc(1,1);

    fd_heredoc = open(ft_strjoin("/tmp/heredoc",ft_itoa(i_node)), O_TRUNC | O_CREAT| O_WRONLY, 0777);
    while (1)
    {
        str = readline(">");
        if (!str)
            exit(1);
        if (ft_strcmp(tmp1->file_name, str) == 0)
        {
            write(fd_heredoc,buf,ft_strlen(buf));
            write(fd_heredoc,"\n",1);
            break;
        }
        if (*buf)
            buf = ft_strjoin(buf,"\n");
        buf = ft_strjoin(buf,str);
        // write(fd_heredoc,str,ft_strlen(str));
            // write(fd_heredoc,"\n",1);  
    }
}

void    heredoc_child(t_data *data)
{
    t_data *tmp;
    t_redirection *tmp1;
	int i_node;
    i_node = 0;

    tmp = data;
    signal(SIGINT, SIG_DFL);
    while (tmp)
    {
        tmp1 = tmp->redirection;
        
        while (tmp1)
        {
            if (tmp1->type == HEREDOC)
            {
                fill_heredoc_file(i_node, tmp1);
            }
            tmp1 = tmp1->next;
        }
        i_node++;
        tmp = tmp->next;
    }
}

void	here_document(t_data *data)
{	
	if (fork() == 0)
	{
		heredoc_child(data);
		exit(0);
	}
	else
		wait(0);
}
