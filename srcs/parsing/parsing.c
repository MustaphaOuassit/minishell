/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:12 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 14:53:45 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	main(void)
{
	char	*line;
	int		indice_start;

	while (1)
	{
		write(1, "-> minishell ", ft_strlen("-> minishell "));
		get_next_line(0, &line);
		g_cmd = line;
		indice_start = skipe_space();
		token_manipulation(indice_start);
		free(line);
	}
	return (0);
}
