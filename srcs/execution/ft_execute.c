/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:26:02 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/15 18:14:02 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

size_t	env_list_len(t_envp **env_list)
{
	size_t i;
	t_envp *tmp;

	i = 0;
	tmp = *env_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		fetch_env_path(char **path, t_envp **env_list)
{
	t_envp *tmp;

	tmp = *env_list;

	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "PATH") == 0)
		{
			if (tmp->value == 0)
				return (1);
			*path = ft_strdup_null(tmp->value);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
int		fetch_pathname(char **pathname, char	*cmd, t_envp **env_list)
{
	char	*path;
	char **path_tab;
	int		i;

	i = 0;

	// if (!cmd)
	// 	error_command(NULL);
	// if (access(cmd, F_OK) == 0 && cmd[0] == '/')
	// 	return (ft_strdup(cmd));
	if (fetch_env_path(&path, env_list) == 1)
	{
		ft_putstr_fd("bash: ",2);
		ft_putstr_fd(cmd,2);
		ft_putstr_fd(" No such file or directory\n",2);
		return (127);
	}// no path
	path_tab = ft_split(path, ':');
	//path[0] = ft_free_first(path[0], ft_strdup(ft_strrchr(path[0], '=') + 1));
	while (path_tab[i])
	{
		*pathname = ft_strjoin_char(path_tab[i], cmd, '/');
		if (access(*pathname, F_OK) == 0)
			break ;
			//printf("%s\n", *pathname);
		i++;
		free(*pathname);
		if (path_tab[i] == 0)
			error_command(cmd);
	}
	ft_free_split(path_tab);
	return (0);
}

char ** convert_list_to_envp(t_envp **env_list)
{
	t_envp *tmp;
	int i;
	char **envp;

	tmp = *env_list;
	i = 0;
	envp = malloc(sizeof(t_envp*) * (env_list_len(env_list) + 1));
	while (tmp)
	{
		if (tmp->equal == 0)
			envp[i] = ft_strdup(tmp->key);
		else
		{
			envp[i] = ft_strjoin(tmp->key, "=");
			if (tmp->value)
			{
				envp[i] = ft_free_first(envp[i], ft_strjoin(envp[i], tmp->value));
			}
			//printf("%s\n", envp[i]);
		}
		i++;
		tmp = tmp->next;
	}
	envp[i] = 0;
	return (envp);
}

int		ft_execute(char **args, int *fd, t_envp **env_list)
{
	char *pathname;
	int ret;

	ret = 127;
	ft_dup(fd);

	if (ft_strchr(args[0], '/'))
		pathname = ft_strdup(args[0]);
	else
	{
		ret = fetch_pathname(&pathname, args[0], env_list);
		if (ret != 0)
			return (ret);
	}
	//printf("fd[1]=%d\n", fd[1]);
	//printf("%d", fd[0]);
	
	if (access(pathname, F_OK) == 0 && access(pathname, X_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);		
		return (126);
	}
	if (opendir(pathname))
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(" : is a directory\n", 2);
		return(126);
	}
	execve(pathname, args, convert_list_to_envp(env_list));
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd(" : No such file or directory\n", 2);
	// printf("TEST\n");
	return (127);
	//exit(123);
}
