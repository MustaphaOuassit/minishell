/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/20 11:01:15 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *str;
	int i;
	int		indice_start;
	t_data *data;
    t_envp *env_list;
	int j;

	i = 0;
	j = 0;
	data = NULL;

	while(envp[i])
	{
		add_to_env(&env_list, fill_envp(envp[i])); 
		i++;
	} 
	if (argc != 1 && !argv[0]) 
        return(-1);
	while(1)
	{
		str = readline("-> minishell ");
		add_history(str);
		g_cmd = str;
		indice_start = skipe_space();
		token_manipulation(&data,indice_start);
	
	while (data != NULL)
	{
		j = 0;
		printf("----------------------------\n");
		printf("Redirection :\n");
		while (data->redirection != NULL)
		{
			printf("%s\n",data->redirection->file_name);
			printf("%d\n",data->redirection->type);
			
			data->redirection = data->redirection->next;
		}
		printf("Arguments :\n");
		while (data->arguments[j])
		{
			printf("%s\n",data->arguments[j]);
			j++;
		}
		data = data->next;
	}
		
// exec
	// if (1 && is_builtin(data->arguments[0]))
	// {
	// 	printf("%s\n", data->arguments[0]);
	// 	ft_builtins(data, &env_list);
	// }
	// else
	// 	exec_cmd(data, envp);

		//ft_free_split(str);
	}
}