/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:25:28 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/04 16:25:37 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	skipe_space(char *cmd)
{
	int	i;

	i = 0;
	while (i != (int)ft_strlen(cmd))
	{
		if ((cmd[i] != ' ') || (cmd[i] != '\t'))
			break ;
		i++;
	}
	return (i);
}

int	check_arrow(int indice, char *cmd)
{
	if (indice + 1 < (int)ft_strlen(cmd))
	{
		if (cmd[indice + 1] == '>')
		{
			put_in_parcer(">>", 2);
			return (indice + 1);
		}
	}
	put_in_parcer(">", 1);
	return (indice);
}

void	token_manipulation(int indice, char *cmd)
{
	while (indice <= (int)ft_strlen(cmd))
	{
		if (cmd[indice] == '|')
		{
			put_in_parcer("|", 0);
		}
		else if (cmd[indice] == '>')
			indice = check_arrow(indice, cmd);
		else
			indice = check_word(indice, cmd);
		indice++;
	}
}
