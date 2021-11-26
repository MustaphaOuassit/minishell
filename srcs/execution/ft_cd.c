/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:15:21 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/26 15:28:46 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

char	*fetch_pwd(t_envp **env_list)
{
	t_envp *tmp;

	tmp = *env_list;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);	
}

int		change_old_pwd(t_envp **env_list)
{
	t_envp *tmp;

	tmp = *env_list;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, "OLDPWD"))
		{
			tmp->equal = 1;
			tmp->value = ft_free_first(tmp->value, ft_strdup_null(fetch_pwd(env_list)));
		}
		tmp = tmp->next;
	}	
	return (0);
}
int		change_pwd(t_envp **env_list)
{
	t_envp *tmp;
	char cwd[PATH_MAX];

	tmp = *env_list;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			tmp->equal = 1;
			tmp->value = ft_free_first(tmp->value, ft_strdup_null(getcwd(cwd, sizeof(cwd))));
			return (0);
		}
		tmp = tmp->next;
	}	
	return (0);
}

int		fetch_home(t_envp **env_list, char **home)
{
	t_envp *tmp;

	tmp = *env_list;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, "HOME"))
		{
			if (tmp->equal == 0)
				return (1);
			*home = ft_strdup_null(tmp->value);
			return (0);			
		}
		tmp = tmp->next;
	}		
	return (1);	
}
int		change_directory(char *str)
{
	if (chdir(str) == -1)
	{
		ft_putstr_fd("bash: cd: ", 1);
		ft_putstr_fd(str, 1);
		perror(" ");
		return (1);
	}
	return (0);
}

int		ft_cd(t_data *data, t_envp **env_list)
{
	char *home;

	if (data->arguments[1] == NULL)
	{
		if (fetch_home(env_list, &home) == 1)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return (1);
		}
		if (home == NULL)
			return (0);
		change_directory(home);
		free(home);
	}
	else
		change_directory(data->arguments[1]);
	change_old_pwd(env_list);
	change_pwd(env_list);
	return (0);
}