/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/19 16:09:16 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libraries/minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *str;
	int i;
	t_data_ex *data;
    t_envp *env_list;

	i = 0;
	data = malloc(sizeof(t_data_ex));

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
        printf("%s\n",str);
// exec
		// if (1 && is_builtin(data->arguments[0]))
		// 	ft_builtins(data, &env_list);
		// else
		// 	exec_cmd(data, envp);

		//ft_free_split(str);
	}
}