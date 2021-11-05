/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:39:35 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 13:28:58 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	put_in_parcer(t_tokens **head, char *value, int type)
{
	char *tmp;

	tmp = ft_strdup(value);
	t_tokens *new_node = malloc(sizeof(t_tokens));
	t_tokens *line;
	 line = *head;
	new_node->value = tmp;
	new_node->type = type;
	new_node->next = NULL;
	g_toll++;
	if(*head == NULL)
	{
		*head = new_node;
		return(0);
	}

	while (line->next != NULL)
	{	
		line = line->next;
	}
	line->next = new_node;
return(0);
}

int		nbr_allocation(char **tmp, int start, int len)
{
	int	i;

	i = 0;
	while (start != len)
	{
		if(tmp[start][0] == '|')
			break;
		start++;
		i++;
	}
	printf("%d\n",i);
	return(start);
}

void    fill_data(t_tokens *data)
{
	char	**cmd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	cmd = (char **)malloc(sizeof(char *) * g_toll + 1);
	while (data != NULL)
	{
		cmd[i] = data->value;
		data = data->next;
		i++;
	}
	while(j <= i)
	{
		j = nbr_allocation(cmd,j,i);
		j++;
	}
	
}