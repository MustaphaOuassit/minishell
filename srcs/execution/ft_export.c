/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:26:03 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/20 16:03:19 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_envp	*fill_envp(char *str)
{
	t_envp	*node;

	init_envp_node(&node);
	if (ft_strchr(str, '='))
	{
		node->equal = 1;
		if (ft_strchr(str, '=') != str && *(ft_strchr(str, '=') - 1) == '+')
		{
			node->key = ft_substr(str, 0, ft_indexof(str, '+'));
			node->plus = 1;
		}
		else
			node->key = ft_substr(str, 0, ft_indexof(str, '='));
		if (*(ft_strchr(str, '=') + 1))
			node->value = ft_strdup(ft_strchr(str, '=') + 1);
		else
			node->value = 0;
	}
	else
		node->key = ft_strdup(str);
	node->next = NULL;
	return (node);
}

void	env_replace(t_envp **tmp1, t_envp **node1)
{
	t_envp	*tmp;
	t_envp	*node;

	tmp = *tmp1;
	node = *node1;
	if (node->equal && node->plus)
	{
		tmp->equal = 1;
		if (node->value)
			tmp->value = ft_free_first(tmp->value, \
			ft_strjoin(tmp->value, node->value));
	}
	else if (node->equal)
	{
		tmp->equal = 1;
		tmp->value = ft_free_first(tmp->value, ft_strdup_null(node->value));
	}
	free_envp(&node);
}

void	add_to_env(t_envp **head, t_envp *node)
{
	t_envp	*tmp;

	tmp = (*head);
	if (tmp == NULL)
	{
		*head = node;
		return ;
	}
	while (tmp != NULL)
	{
		if (!ft_strcmp(node->key, tmp->key))
		{
			env_replace(&tmp, &node);
			return ;
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp->next = node;
}

void	env_key_error(int *ret, t_envp *node, char *arg)
{
	free_envp(&node);
	printf("-> minishell: export: `%s`: not a valid identifier\n", arg);
	*ret = 1;
}

int	ft_export(t_data	*data, t_envp	**env_list)
{
	int		i;
	t_envp	*node;
	int		ret;

	ret = 0;
	i = 1;
	if (data->arguments[1] == NULL)
		print_exp(*env_list);
	else
	{
		while (data->arguments[i])
		{
			node = fill_envp(data->arguments[i]);
			if (check_env_key_error(node->key) \
			|| (node->equal == 0 && node->plus == 1))
				env_key_error(&ret, node, data->arguments[i]);
			else
				add_to_env(env_list, node);
			i++;
		}
	}
	return (ret);
}
