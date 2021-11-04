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
/*
int	ft_fill(t_tokens **head, t_tokens data)
{
	t_tokens *new_node = malloc(sizeof(t_tokens));
	t_tokens *line;

	 line = *head;
	new_node->value = data.value;
	new_node->type = data.type;
	new_node->next = NULL;
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
}*/

int	put_in_parcer(t_tokens **head, char *value, int type)
{
	//printf("%s\n",value);
	t_tokens *new_node = malloc(sizeof(t_tokens));
	t_tokens *line;

	 line = *head;
	new_node->value = value;
	new_node->type = type;
	new_node->next = NULL;
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
