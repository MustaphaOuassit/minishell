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

int	check_arrow(t_tokens **head ,int indice)
{
	if (indice + 1 < (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice + 1] == '>')
		{
			put_in_parcer(head,">>", 2);
			return (indice + 1);
		}
	}
	put_in_parcer(head, ">", 1);
	return (indice);
}

void	token_manipulation(int indice)
{
	t_tokens	*head;
	t_tokens	*size;

	head = NULL;
	size = NULL;
	while (indice <= (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice] == '|')
			put_in_parcer(&head,"|", 0);
		else if (g_cmd[indice] == '>')
			indice = check_arrow(&head,indice);
		else
			indice = check_word(&head,indice);
		indice++;
	}
	free(g_str);
	fill_data(head);
}
