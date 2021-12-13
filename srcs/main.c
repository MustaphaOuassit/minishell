/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/13 18:18:46 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"





int main(int argc, char **argv, char **envp)
{
	char *str;
	t_data *data;
    t_envp *env_list;
	int ret;
	data = NULL;

	fetch_envp(&env_list, envp);
	if (argc != 1 && !argv[0]) 
        return(-1);
	
	while(1)
	{
		ft_signal(FIRST_SIG);		
		str = readline("-> minishell ");
		add_history(str);
		if (!str)
		{
			ft_putstr_fd("bash-3.2$ exit", 2);
			exit(1);
		}
		if(!*str)
			continue;
		parsing(str,&ret,env_list,&data);
		if (ret != 0)
			continue;
		ft_signal(PRECHILD_SIG);
		here_document(data);
		if (data->next == NULL && is_builtin(data->arguments[0]))
		{
			ret = builtin_only(data, &env_list);
		}
		else
			ret = ft_pipeline(data, &env_list);
		data = NULL;
		//ft_free_split(data->arguments);
		free(str);
		printf("$? = %d \n", ret);
	}
		return (0);
}