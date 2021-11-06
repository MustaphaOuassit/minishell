/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:41:44 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/05 13:41:47 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int    fill_linkdlist(t_data **head, char **data)
{
    t_data *new_node = malloc(sizeof(t_data));
	t_data *line;

	line = *head;
	new_node->line_cmd = data;
	new_node->next = NULL;
	if(*head == NULL)
	{
		*head = new_node;
		return(0);
	}

	while (line->next != NULL)
		line = line->next;
	line->next = new_node;
return(0);   
}