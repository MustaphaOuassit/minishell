/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/01 10:45:32 by ayafdel          ###   ########.fr       */
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

int main(int argc, char **argv, char **envp)
{
	char *str;
	t_data *data;
    t_envp *env_list;
	int ret;
	data = NULL;
	//data = malloc(sizeof(t_data));
	//data->redirection = NULL;
	fetch_envp(&env_list, envp);
	if (argc != 1 && !argv[0]) 
        return(-1);
	while(1)
	{
		str = readline("-> minishell ");
		add_history(str);
		parsing(str,&ret,env_list,&data);
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
		if (1 && is_builtin(data->arguments[0]))
		{
			//printf("%s\n", data->arguments[0]);
			ret = builtin_only(data, &env_list);
		}
		else
			ret = exec_cmd(data, &env_list, envp);
		data = NULL;
		//ft_free_split(data->arguments);
		free(str);
		printf("$? = %d \n", ret);
	}
		return (0);
}