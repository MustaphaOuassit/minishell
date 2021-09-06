/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:51:06 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/06 14:54:43 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	fill_string(int start, int indice, int ele, int j)
{
	start++;
	while (start <= indice)
	{
		if(g_cmd[start] == ele)
			break;
		else
		{
			g_str[j] = g_cmd[start];
			j++;
		}
		start++;	
	}
	return(start);
}

int	add_to_string(int indice,char *ele)
{
	t_initial	initial;
	int m;
	
	initial.start = indice - 1;
	initial.i = 0;
	initial.j = 0;
	initial.t = 0;
	initial.r = 0;
	m = 0;
	while (indice != (int)ft_strlen(g_cmd))
	{
		if((initial.t == 1) && ((g_cmd[indice] == ' ') || (g_cmd[indice] == '|')))
			break;
		if (g_cmd[indice] == ele[0])
			initial.t = 1;
		indice++;
		initial.i++;
	}

	if(initial.i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char));
		while (initial.start <= indice)
		{
			if(g_cmd[initial.start] == ele[0])
			{
				//initial.start = fill_string(initial.start, indice,ele[0], initial.j);
				
				initial.start++;
				while (initial.start <= indice)
				{
					if(g_cmd[initial.start] == ele[0])
						break;
					else
					{
						g_str[initial.j] = g_cmd[initial.start];
						initial.j++;
					}
					initial.start++;	
				}
			}
			if(g_cmd[initial.start] == ele[1])
			{
				initial.start++;
				while (initial.start <= indice)
				{
					if(g_cmd[initial.start] == ele[1])
						break;
					else
					{
						g_str[initial.j] = g_cmd[initial.start];
						initial.j++;
					}
					initial.start++;	
				}
			}
			initial.start++;
			
		}
		g_str[initial.j] = '\0';
	}
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
	return (indice);
}

char	*continue_check(int len, int sword)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = NULL;
	if (len > 0)
	{
		j = 0;
		ptr = (char *)malloc((len + 1) * sizeof(char));
		while (sword != len)
		{
			ptr[j] = g_cmd[sword];
			sword++;
			j++;
		}
		ptr[j] = '\0';
	}
	return (ptr);
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
			if (g_cmd[indice] == '"')
				indice = add_to_string(indice + 1,"\"'");
			else if (g_cmd[indice] == '\'')
				indice = add_to_string(indice + 1,"\"'");
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
