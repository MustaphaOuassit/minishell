/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_only.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:05:12 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/23 17:04:28 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
int	builtin_only(t_data *data, t_envp **env_list)
{
	int *fd;
	int tmp_fd;

	tmp_fd = 1;
	//if (data->redirection)
	fetch_fd(data->redirection, &fd);
	//exit(0);
	if (fd[1] != 1)
	{
		tmp_fd = dup(1);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	
	ft_builtins(data, env_list);
	dup2(tmp_fd, 1);
	return (0);
}