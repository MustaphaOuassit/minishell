/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:46 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/23 13:25:57 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
void	ft_builtins(t_data *data, t_envp **env_list)
{

		if (ft_strcmp(data->arguments[0],"echo") == 0)
			ft_echo(data); 
		if (ft_strcmp(data->arguments[0], "pwd") == 0)
			ft_pwd();
		if (ft_strcmp(data->arguments[0], "env") == 0)
			ft_env(data, env_list);
		if (ft_strcmp(data->arguments[0], "export") == 0)
			ft_export(data, env_list);
		if (ft_strcmp(data->arguments[0], "unset") == 0)
			ft_unset(data->arguments, env_list);
		if (ft_strcmp(data->arguments[0], "exit") == 0)
			ft_exit();
		if (ft_strcmp(data->arguments[0], "cd") == 0)
			ft_cd(data);
}

int		is_builtin(char *cmd)
{
		if (ft_strcmp(cmd,"echo") == 0)
			return (1);
		if (ft_strcmp(cmd, "env") == 0)
			return (1);
		if (ft_strcmp(cmd, "export") == 0)
			return (1);
		if (ft_strcmp(cmd, "unset") == 0)
			return (1);
		if (ft_strcmp(cmd, "exit") == 0)
			return (1);
		if (ft_strcmp(cmd, "pwd") == 0)
			return (1);
		if (ft_strcmp(cmd, "cd") == 0)
			return (1);
		return (0);
}