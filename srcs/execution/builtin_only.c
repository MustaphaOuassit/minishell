/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_only.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:05:12 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/26 20:42:31 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
int		redirect(int *fd, int *tmp_fd)
{
	if (fd[1] != 1)
	{
		tmp_fd[1] = dup(1);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	if (fd[0] != 0)
	{
		tmp_fd[0] = dup(0);
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
	}	
	return (0);
}

int	builtin_only(t_data *data, t_envp **env_list)
{
	int fd[2];
	int tmp_fd[2];
	int ret;

	tmp_fd[0] = 0;
	tmp_fd[1] = 1;
	//if (data->redirection)
	//return (0);
	if (fetch_fd(data->redirection, fd) == 1)
		return (1);
	//exit(0);
	redirect(fd, tmp_fd);
	ret = ft_builtins(data, env_list);
	dup2(tmp_fd[1], 1);
	dup2(tmp_fd[0], 0);
	
	return (ret);
}