/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:55:33 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/21 10:27:06 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_from_env(t_envp **head, char *key)
{
	t_envp	*tmp;
	t_envp	*prev;

	tmp = (*head);
	if (tmp == NULL)
		return ;
	if (!ft_strcmp(key, tmp->key))
	{
		(*head) = tmp->next;
		free_envp(&tmp);
		return ;
	}
	while (tmp != NULL && ft_strcmp(key, tmp->key))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free_envp(&tmp);
}

int	check_env_key_error(char *var)
{
	int	i;

	i = 1;
	if (!ft_isalpha(var[0]) && var[0] != '_')
		return (1);
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(char **args, t_envp **env_list)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (args[i])
	{
		if (check_env_key_error(args[i]))
		{
			printf("-> minishell: unset: `%s`: not a valid identifier\n", \
			args[i]);
			ret = 1;
		}
		else
			remove_from_env(env_list, args[i]);
		i++;
	}
	return (ret);
}
