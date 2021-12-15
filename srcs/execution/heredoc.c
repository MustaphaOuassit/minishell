/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:59:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/15 15:46:43 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    fill_heredoc_file(int i_node, t_redirection *tmp1, t_envp *list)
{
    int fd_heredoc;   
    char *str;
    char *buf = ft_calloc(1,1);

    str = ft_strjoin("/tmp/heredoc",ft_itoa(i_node));
    fd_heredoc = open(str, O_TRUNC | O_CREAT| O_WRONLY, 0777);
    free(str);
    while (1)
    {
        str = readline(">");
        if (!str)
            exit(1);
        if (ft_strcmp(tmp1->file_name, str) == 0)
        {
            write(fd_heredoc,buf,ft_strlen(buf));
            write(fd_heredoc,"\n",1);
            free(buf);
            break;
        }
        if (tmp1->type == HEREDOC)
            str = expand_value(str, list);
        if (*buf)
            buf = ft_free_first(buf,ft_strjoin(buf,"\n"));
        buf = ft_free_first(buf, ft_strjoin(buf,str));
    }
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
                printf("HELLO\n");
                fill_heredoc_file(i_node, tmp1, list);
            }
            tmp1 = tmp1->next;
        }
        i_node++;
        tmp = tmp->next;
    }
}

int     here_document(t_data *data, t_envp *list)
{	
	if (fork() == 0)
	{
		heredoc_child(data, list);
		exit(0);
	}
	else
		wait(0);
    
    return (0);
}
