/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/09 10:39:58 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
void	new_node_redirect(t_redirection **head, char *file, int type)
{
	t_redirection *new;
	t_redirection *tmp;

	tmp = *head;
	new = malloc(sizeof(t_redirection));
	new->file_name = ft_strdup(file);
	new->type = type;
	new->next = NULL;
	if (*head == NULL)
	{
		(*head) = new;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		//printf("TEST\n");
	}
	tmp->next = new;
}

t_redirection * fill_redirect()
{
	t_redirection *head;
	head = NULL;
	new_node_redirect(&head, "file1", 1);
	new_node_redirect(&head, "file2", 1);
	new_node_redirect(&head, "file3", 1);
	new_node_redirect(&head, "file4", 1);
	//new_node_redirect(&head, "file2", 1);
	//printf("%s\n", head->file_name);
	//printf("%s\n", head->filename);

	return (head);
}
void handler(int sig)
{
	//printf("Handler Parent\n");
	if (sig == SIGINT)
	{
		//rl_redisplay();
		// rl_replace_line();
		//rl_line_buffer = "ayoub";
		 //rl_redisplay();
		 //rl_replace_line("-> minishell",0);
		//ft_putstr_fd("\n-> minishell ", 1);		
	}
	
}

void	here_document(t_data *data)
{
	t_data *tmp;
	t_redirection *tmp1;
	int fd_heredoc;
	int i_node;
	char *str;

	i_node = 0;
	tmp = data;
	while (tmp)
	{
		tmp1 = tmp->redirection;
		while (tmp1)
		{
			if (tmp1->type == HEREDOC)
			{
				
				fd_heredoc = open(ft_strjoin("/tmp/heredoc",ft_itoa(i_node)), O_TRUNC | O_CREAT| O_WRONLY, 0777);
				while (1)
				{
					str = readline(">");
					if (ft_strcmp(tmp1->file_name, str) == 0)
						break;
					write(fd_heredoc,str,ft_strlen(str));
					write(fd_heredoc,"\n",1);
				}
			}
			tmp1 = tmp1->next;
		}
		i_node++;
		tmp = tmp->next;
	}
}
int main(int argc, char **argv, char **envp)
{
	char *str;
	t_data *data;
    t_envp *env_list;
	int ret;
	data = NULL;
	//signal(SIGINT, handler);
	//data = malloc(sizeof(t_data));
	//data->redirection = NULL;
	fetch_envp(&env_list, envp);
	if (argc != 1 && !argv[0]) 
        return(-1);
	
	while(1)
	{
		signal(SIGINT,handler);
		str = readline("-> minishell ");
		//printf("str = %s\n", str);
		// printf("%s\n", str);
		//rl_line_buffer = NULL;
		//printf("|%s|\n", rl_line_buffer);
		add_history(str);
		if (!str)
			exit(1);
		if(!*str)
			continue;
		parsing(str,&ret,env_list,&data);
		if (ret != 0)
			continue;
		// 		if(!error)
		// {
		// 	while (data != NULL)
		// 	{
		// 		j = 0;
		// 		printf("-------------------\n");
		// 		printf("\n");
		// 		printf("Arguments :\n");
		// 		while (data->arguments[j])
		// 		{
		// 		printf("%s\n",data->arguments[j]);
		// 		j++;
		// 	}
		// 		printf("\n");
		// 		printf("Redirections :\n");
		// 	while (data->redirection != NULL)
		// 	{
		// 		printf("%s %d\n",data->redirection->file_name,data->redirection->type);
		// 		data->redirection = data->redirection->next;
		// 	}
		// 		printf("\n");
		// 		printf("Heredoc :\n");
		// 		printf("%d\n",data->nb_heredoc);
		// 		data = data->next;
		// 	}
		// }
		here_document(data);
		//data->arguments = ft_split(str, ' ');
		//data->redirection = fill_redirect();
	//print node
	//int i,j=0;
	//t_data *tmp = data;	
	// while (tmp != NULL)
	// {
	// 	j = 0;
	// 	printf("Redirection :\n");
	// 	while (tmp->redirection != NULL)
	// 	{
	// 		//printf("%s\n",tmp->redirection->file_name);
	// 		//printf("%d\n",tmp->redirection->type);		
	// 		tmp->redirection = tmp->redirection->next;
	// 	}
	// 	printf("Arguments : ");
	// 	while (tmp->arguments[j])
	// 	{
	// 		printf("%s\n",tmp->arguments[j]);
	// 		j++;
	// 	}
	// 	tmp = tmp->next;
	// 	printf("----------------------------\n");
	// }
		if (data->next == NULL && is_builtin(data->arguments[0]))
		{
			//printf("%s\n", data->arguments[0]);
			ret = builtin_only(data, &env_list);
		}
		else
			ret = ft_pipeline(data, &env_list);
		data = NULL;
		//ft_free_split(data->arguments);
		free(str);
		//printf("$? = %d \n", ret);
	}
		return (0);
}