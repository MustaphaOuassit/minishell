/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/14 11:36:08 by ayafdel          ###   ########.fr       */
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
		ctrl_d_main(str);
		if (!*str)
			continue;
		parsing(str,&ret,env_list,&data);
		free(str);
		ft_signal(PRECHILD_SIG);
		if (ret != 0 || here_document(data))
			continue;
		if (data->next == NULL && is_builtin(data->arguments[0]))
			ret = builtin_only(data, &env_list);
		else
			ret = ft_pipeline(data, &env_list);
		data = NULL;
		//ft_free_split(data->arguments);
		printf("$? = %d \n", ret);
	}
		return (0);
}