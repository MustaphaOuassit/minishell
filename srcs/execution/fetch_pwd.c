/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:19 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/20 13:26:49 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_exp(t_envp *head)
{
	t_envp	*current_node;

	current_node = head;
	while (current_node != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(current_node->key, 1);
		if (current_node->equal)
		{
			ft_putstr_fd("=\"", 1);
			if (current_node->value)
				ft_putstr_fd(current_node->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		current_node = current_node->next;
	}
}

int	init_envp_node(t_envp **node)
{
	*node = malloc(sizeof(t_envp));
	(*node)->value = 0;
	(*node)->key = 0;
	(*node)->plus = 0;
	(*node)->equal = 0;
	return (0);
}

char	*fetch_pwd(t_envp **env_list)
{
	t_envp	*tmp;

	tmp = *env_list;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
