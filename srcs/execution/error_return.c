/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:26:33 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/20 16:02:50 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error_file(char	*pathname)
{
	if (access(pathname, F_OK) == 0 && access(pathname, X_OK) == -1)
	{
		ft_putstr_fd("-> minishell: ", 2);
		ft_putstr_fd(pathname, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	else if (opendir(pathname))
	{
		ft_putstr_fd("-> minishell: ", 2);
		ft_putstr_fd(pathname, 2);
		ft_putstr_fd(" : is a directory\n", 2);
		return (1);
	}
	return (0);
}

void	error_command(char	*str)
{
	ft_putstr_fd("-> minishell ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

int	error_return(char *str1, char *str2, char *str3, int ret)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	return (ret);
}

void	free_envp(t_envp **env)
{
	free((*env)->key);
	free((*env)->value);
	free((*env));
	*env = NULL;
}
