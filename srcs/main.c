/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/17 18:47:13 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"




void	ctrl_d_main(char *str)
{
	if (!str)
	{
		ft_putstr_fd("bash-3.2$ exit", 2);
		exit(1);
	}
}
int		empty_line(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
int main(int argc, char **argv, char **envp)
{
	char *str;
	t_data *data;
    t_envp *env_list;
	int ret;
	data = NULL;

	if (argc != 1 && !argv[0]) 
        return(-1);
	fetch_envp(&env_list, envp);
	ret = 0;
	env_list->exit_status = 0;
	while(1)
	{
		g_signal_flag = 0;
		ft_signal(FIRST_SIG);		
		str = readline("-> minishell ");
		add_history(str);
		ctrl_d_main(str);
		if (!*str || empty_line(str))
		{
			free(str);
				continue;
		}

		data = NULL;
		
		parsing(str,&ret,env_list,&data);
		//printf("%s\n", data->redirection->file_name);
		//printf("address = %p\n", data->arguments);
		if (ret != 0)
		{
			free(str);
			continue;
		}
		free(str);
		ft_signal(PRECHILD_SIG);
		// if (here_document(data, env_list))
		// {
		// 	env_list->exit_status = ret;
		// 	free_data(data);
		// 	continue;
		// }
	
		if (data->arguments && data->next == NULL && is_builtin(data->arguments[0]))
		{
			ret = builtin_only(data, &env_list);
		}
		else
			ret = ft_pipeline(data, &env_list);
		free_data(data);
		// exit(0);
		//ft_free_split(data->arguments);
		env_list->exit_status = ret;
		//printf("$? = %d \n", ret);
	}
		return (0);
}