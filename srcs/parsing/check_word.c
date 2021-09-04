/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:51:06 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/04 18:04:13 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	add_to_string(char **str, int indice, char *cmd, int ele)
{
	t_initial	initial;

	initial.start = indice - 1;
	initial.i = 0;
	initial.j = 0;
	while (indice != (int)ft_strlen(cmd))
	{
		/*
		if (cmd[indice] == ele)
		{
			break ;
		}*/
		indice++;
		initial.i++;
	}
	if (initial.i > 0)
	{
		*str = (char *)malloc((initial.i + 1) * sizeof(char));
		initial.start++;
		while (initial.start != indice)
		{
			if((initial.start < indice) && (cmd[initial.start] == ele))
				initial.start++;
			(*str)[initial.j] = cmd[initial.start];
			initial.start++;
			initial.j++;
		}
		(*str)[initial.j] = '\0';
	}
	return (indice);
}

int	check_type_word(char *ptr, char *str, char *cmd, int indice)
{
	if (ptr && str)
		put_in_parcer(ft_strjoin(ptr, str), 3);
	else if (ptr)
		put_in_parcer(ptr, 3);
	else if (str)
		put_in_parcer(str, 3);
	if (cmd[indice] && cmd[indice] != ' ' && cmd[indice] != '\t')
	{
		if (cmd[indice] == '|')
		{
			put_in_parcer("|", 0);
		}
		else if (cmd[indice] == '>')
			indice = check_arrow(indice, cmd);
	}
	return (indice);
}

char	*continue_check(int len, int sword, char *cmd)
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
			ptr[j] = cmd[sword];
			sword++;
			j++;
		}
		ptr[j] = '\0';
	}
	return (ptr);
}

int	check_word(int indice, char *cmd)
{
	char		*str;
	t_initial	initial;

	initial.len = 0;
	initial.sword = indice;
	str = NULL;
	if (cmd[indice] == ' ')
		return (indice++);
	while ((indice != (int)ft_strlen(cmd)) && (cmd[indice] != ' ')
		&& (cmd[indice] != '\t') && (cmd[indice] != '|')
		&& (cmd[indice] != '>'))
	{
		if ((cmd[indice] == '"') || (cmd[indice] == '\''))
		{
			if (cmd[indice] == '"')
				indice = add_to_string(&str, indice + 1, cmd, '"');
			else if (cmd[indice] == '\'')
				indice = add_to_string(&str, indice + 1, cmd, '\'');
			break ;
		}
		else
		{
			indice++;
			initial.len = indice;
		}
	}
	indice = check_type_word(continue_check(initial.len,
				initial.sword, cmd), str, cmd, indice);
	return (indice);
}
