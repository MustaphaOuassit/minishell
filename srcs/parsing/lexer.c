/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:25:28 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 13:26:50 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	skipe_space(void)
{
	int	i;

	i = 0;
	while (i != (int)ft_strlen(g_cmd))
	{
		if ((g_cmd[i] != ' ') || (g_cmd[i] != '\t'))
			break ;
		i++;
	}
	return (i);
}

int	check_arrow(int indice)
{
	if (indice + 1 < (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice + 1] == '>')
		{
			put_in_parcer(">>", 2);
			return (indice + 1);
		}
	}
	put_in_parcer(">", 1);
	return (indice);
}

void	token_manipulation(int indice)
{
	while (indice <= (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice] == '|')
			put_in_parcer("|", 0);
		else if (g_cmd[indice] == '>')
			indice = check_arrow(indice);
		else
			indice = check_word(indice);
		indice++;
	}
	free(g_str);
}
