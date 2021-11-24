/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:48:08 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/24 10:23:05 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int     fetch_envp(t_envp **env_list, char **envp)
{
    int i;

    i = 0;
    while(envp[i])
	{
		add_to_env(env_list, fill_envp(envp[i])); 
		i++;
	}
	return (0);
}