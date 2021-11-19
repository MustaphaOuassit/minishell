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

#include "parsing.h"

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

void		check_alloc(int indice,char *str,int *l)
{
	*l = 0;
	while (str[indice])
	{
		if((str[indice] == ' ') || (str[indice] == '\"'))
			break;
		*l = *l + 1;
		indice++;
	}
}

void	token_manipulation(int indice)
{
	t_tokens	*head;
	t_tokens	*size;
	char		*dollar;
	int			l;

	head = NULL;
	size = NULL;
	l = 0;
	while (indice <= (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice] == '|')
			put_in_parcer(&head,"|", 0);
		else if (g_cmd[indice] == '>')
			indice = check_arrow(&head,indice);
		else if(g_cmd[indice] == '$')
		{
			check_alloc(indice,g_cmd,&l);
			dollar = (char *)malloc(sizeof(char) * (l + 1));
			dollar[l] = 0;
			l = 0;
			while (dollar[l])
			{
				dollar[l] = g_cmd[indice];
				indice++;
				l++;
			}
			put_in_parcer(&head,dollar,5);
		}
		else
			indice = check_word(&head,indice);
		indice++;
	}
	//free(g_str);
	fill_data(head);
}
