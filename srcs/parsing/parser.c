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

int		ft_strlen_two(char	**str)
{
	return(sizeof(str) / sizeof(str[0]));
	
}

void	free_two(char **table)
{
	int	i;

	i = 0;
	while (table[i] != '\0')
	{
		free(table[i]);
		i++;
	}
	free(table);
}

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

int		ft_check_red(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if(str[i] == '>')
		{
			if(str[i + 1])
				j = j - 2;
			else
				j--;
		}
		i++;
		j++;
	}
	return(j);
}


int		add_to_linkdlist(t_tokens **cmd, int start, int len, char **arguments)
{
	int	nb_allocation;
	t_data	*head;
	t_data  cmdata;
	int		i;
	int		tmp;
	int		j;
	int		r;

	head = NULL;
	tmp = start;
	i = 0;
	j = 0;
	r = 0;
	nb_allocation = 0;
	while (start != len)
	{
		if(cmd[start]->type == 0)
			break;
		start++;
		nb_allocation++;
	}
	cmdata.line_cmd = (t_tokens **)malloc(sizeof(t_tokens) * (nb_allocation + 1));
	while (i != nb_allocation)
	{
		cmdata.line_cmd[i] = (t_tokens *)malloc(sizeof(t_tokens));
		cmdata.line_cmd[i]->value = ft_strdup(cmd[tmp]->value);
		cmdata.line_cmd[i]->type = cmd[tmp]->type;
		i++;
		tmp++;
	}
	cmdata.line_cmd[i] = 0;
	fill_linkdlist(&head,cmdata.line_cmd);
	i = 0;
	while (head != NULL)
	{
		j = 0;
		while (head->line_cmd[j])
		{
			if(head->line_cmd[j]->type != 1)
			{
				arguments[i] = head->line_cmd[j]->value;
				j++;
			}
			else
			{
				cmdata.redirection.type = head->line_cmd[j]->type;
				if(j + 2 <= g_toll)
				{
					cmdata.redirection.file_name = head->line_cmd[j + 1]->value;
					j = j + 2;
				}
				else
					j = j + 1;
			}
			i++;
		}
		head = head->next;
	}
	return(start);
}
int		check_allocation(t_tokens **cmd)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (cmd[i])
	{
		count++;
		if(cmd[i]->type == 1)
		{
			count = count - 2;
		}
		i++;
	}
	
	return(count);
}
void    fill_data(t_tokens *data)
{
	t_tokens	**cmd;
	t_data		cmdata;
	int		nb_list;
	int		start;
	int		i;
	int		l;

	start = 0;
	nb_list = 0;
	i = 0;
	l = 0;
	cmd = (t_tokens **)malloc(sizeof(t_tokens) * (g_toll + 1));
	cmdata.arguments = (char **)malloc(sizeof(char *) * (g_toll + 1));
	while (data != NULL)
	{
		cmd[nb_list] = (t_tokens *)malloc(sizeof(t_tokens));
		cmd[nb_list]->value = ft_strdup(data->value);
		cmd[nb_list]->type = data->type;
		data = data->next;
		nb_list++;
	}
	cmd[nb_list] = 0;
	l = check_allocation(cmd);
	printf("%d\n",l);

	// while(start <= nb_list)
	// {
	// 	start = add_to_linkdlist(cmd,start,nb_list,cmdata.arguments);
	// 	start++;
	// }
	// while (cmdata.arguments[i])
	// {
	// 	printf("%s\n",cmdata.arguments[i]);
	// 	i++;
	// }
}