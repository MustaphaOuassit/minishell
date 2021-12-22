/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:13 by mouassit          #+#    #+#             */
/*   Updated: 2021/12/22 16:01:08 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("-> minishell exit\n", 2);
		exit(0);
	}
	if (!*str)
	{
		free(str);
		return (1);
	}
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	free(str);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_data	*data;
	t_envp	*env_list;

	fetch_envp(argv, argc, &env_list, envp);
	env_list->exit_status = 0;
	data = NULL;
	while (1)
	{
		g_signal_flag = 0;
		ft_signal(FIRST_SIG);
		str = readline("-> minishell ");
		add_history(str);
		if (empty_line(str) || parsing(str, env_list, &data))
			continue ;
		ft_signal(PRECHILD_SIG);
		if (here_document(&data, env_list))
			continue ;
		if (data->arguments && data->next == NULL && is_bt(data->arguments[0]))
			env_list->exit_status = builtin_only(data, &env_list);
		else
			env_list->exit_status = ft_pipeline(data, &env_list);
		free_data(&data);
	}
	return (0);
}
