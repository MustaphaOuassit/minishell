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

int	check_character(int i, int indice, char *ele)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[0])
				fill_string(indice, ele[0]);
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
	free(g_str);
	return (indice);
}

int	add_to_string(int indice, char *ele)
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
	indice = check_character(initial.i, indice, ele);
	return (indice);
}

int	check_type_word(char *ptr, int indice)
{
	if (ptr && g_str)
		put_in_parcer(ft_strjoin(ptr, g_str), 3);
	else if (ptr)
		put_in_parcer(ptr, 3);
	else if (g_str)
		put_in_parcer(g_str, 3);
	if (g_cmd[indice] && g_cmd[indice] != ' ' && g_cmd[indice] != '\t')
	{
		if (g_cmd[indice] == '|')
		{
			put_in_parcer("|", 0);
		}
		else if (g_cmd[indice] == '>')
			indice = check_arrow(indice);
	}
	free(ptr);
	return (indice);
}

int	check_word(int indice)
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
			indice = check_couts(indice);
			break ;
		}
		else
		{
			indice++;
			initial.len = indice;
		}
	}
	indice = check_type_word(continue_check(initial.len,
				initial.sword), indice);
	return (indice);
}
