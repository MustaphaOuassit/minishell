/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:15:21 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/26 10:51:22 by ayafdel          ###   ########.fr       */
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
int		ft_cd(t_data *data, t_envp **env_list)
{
	//char buf[100];
	
	if (data->arguments[1] == NULL)
		chdir("/Users/ayafdel");
	else
	{
		if (chdir(data->arguments[1]) == -1)
		{
			ft_putstr_fd("bash: cd: ", 1);
			ft_putstr_fd(data->arguments[1], 1);
			//ft_putstr_fd(" ", 1);
			perror(" ");
			return (1);
		}
		//printf("%s\n",getcwd(buf, sizeof(buf)));
	}
	change_old_pwd(env_list);
	change_pwd(env_list);
	return (0);
}