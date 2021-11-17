/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:51:06 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 14:10:52 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

void	fill_string_double(t_tokens **head, int indice, int ele)
{
	int l;
	char *dollar;

	l = 0;
	g_start++;
	while (g_start <= indice)
	{
		if (g_cmd[g_start] == ele)
			break ;
		else
		{
			if(g_cmd[g_start] == '$')
			{
				check_alloc(g_start,g_cmd,&l);
				dollar = (char *)malloc(sizeof(char) * (l + 1));
				dollar[l] = 0;
				l = 0;
				while (dollar[l])
				{
				dollar[l] = g_cmd[g_start];
				g_start++;
				l++;
				}
				put_in_parcer(head,dollar,5);

				// while (g_cmd[g_start])
				// {
				// 	if((g_cmd[g_start] == ' ') || g_cmd[g_start] == ele)
				// 		break;
				// 	g_start++;
				// }
			}
			g_str[g_rmp] = g_cmd[g_start];
			g_rmp++;
		}
		g_start++;
	}
}

void	fill_string(int indice, int ele)
{
	g_start++;
	while (g_start <= indice)
	{
		if (g_cmd[g_start] == ele)
			break ;
		else
		{
			g_str[g_rmp] = g_cmd[g_start];
			g_rmp++;
		}
		g_start++;
	}
}


int	check_character(t_tokens **head, int i, int indice, char *ele)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[0])
				fill_string_double(head,indice, ele[0]);
			else if (g_cmd[g_start] == ele[1])
				fill_string(indice, ele[1]);
			else
			{
				g_str[g_rmp] = g_cmd[g_start];
				g_rmp++;
			}
			g_start++;
		}
		g_str[g_rmp] = '\0';
	}
	return (indice);
}

int	check_character_double(t_tokens **head,int i, int indice, char *ele)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[0])
				fill_string_double(head,indice, ele[0]);
			else if (g_cmd[g_start] == ele[1])
				fill_string(indice, ele[1]);
			else
			{
				g_str[g_rmp] = g_cmd[g_start];
				g_rmp++;
			}
			g_start++;
		}
		g_str[g_rmp] = '\0';
	}
	return (indice);
}

int	add_to_string(t_tokens **head, int indice, char *ele)
{
	t_initial	initial;

	g_start = indice - 1;
	initial.i = 0;
	g_rmp = 0;
	initial.t = 0;
	while (indice != (int)ft_strlen(g_cmd))
	{
		if ((initial.t == 1) && ((g_cmd[indice] == ' ')
				|| (g_cmd[indice] == '|')))
			break ;
		if (g_cmd[indice] == ele[0])
			initial.t = 1;
		indice++;
		initial.i++;
	}
	indice = check_character(head,initial.i, indice, ele);
	return (indice);
}

int	add_to_string_double(t_tokens **head,int indice, char *ele)
{
	t_initial	initial;

	g_start = indice - 1;
	initial.i = 0;
	g_rmp = 0;
	initial.t = 0;
	while (indice != (int)ft_strlen(g_cmd))
	{
		if ((initial.t == 1) && ((g_cmd[indice] == ' ')
				|| (g_cmd[indice] == '|')))
			break ;
		if (g_cmd[indice] == ele[0])
			initial.t = 1;
		indice++;
		initial.i++;
	}
	indice = check_character_double(head, initial.i, indice, ele);
	return (indice);
}

int	check_type_word(t_tokens **head, char *ptr, int indice)
{
	if (ptr && g_str)
		put_in_parcer(head, ft_strjoin(ptr, g_str), 3);
	else if (ptr)
		put_in_parcer(head, ptr, 3);
	else if (g_str)
		put_in_parcer(head, g_str, 3);
	if (g_cmd[indice] && g_cmd[indice] != ' ' && g_cmd[indice] != '\t')
	{
		if (g_cmd[indice] == '|')
			put_in_parcer(head, "|", 0);
		else if (g_cmd[indice] == '>')
			indice = check_arrow(head, indice);
	}
	free(ptr);
	return (indice);
}

int	check_word(t_tokens **head, int indice)
{
	t_initial	initial;

	initial.len = 0;
	initial.sword = indice;
	g_str = NULL;
	if (g_cmd[indice] == ' ')
		return (indice++);
	while ((indice != (int)ft_strlen(g_cmd)) && (g_cmd[indice] != ' ')
		&& (g_cmd[indice] != '\t') && (g_cmd[indice] != '|')
		&& (g_cmd[indice] != '>'))
	{
		if ((g_cmd[indice] == '"') || (g_cmd[indice] == '\''))
		{
			indice = check_couts(head,indice);
			break ;
		}
		else
		{
			indice++;
			initial.len = indice;
		}
	}
	indice = check_type_word(head,continue_check(initial.len,
				initial.sword), indice);
	return (indice);
}