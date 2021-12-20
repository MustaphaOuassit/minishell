/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:48:08 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/20 11:00:05 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fetch_envp(char **argv, int argc, t_envp **env_list, char	**envp)
{
	int	i;

	i = 0;
	if (argc != 1)
	{
		ft_putstr_fd("-> minishell: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	while (envp[i])
	{
		add_to_env(env_list, fill_envp(envp[i]));
		i++;
	}
	return (0);
}
