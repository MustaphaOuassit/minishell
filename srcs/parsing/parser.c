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
			if(cmd[i + 1])
				count = count - 2;
			else
				count--;
		}
		i++;
	}
	
	
	return(count);
}

int	lkd_redirection(t_redirection	**head,int type, char *file_name)
{
	t_redirection *new_node = malloc(sizeof(t_redirection));
	t_redirection *line;

	line = *head;
	new_node->file_name = file_name;
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

int		add_to_linkdlist(t_tokens **cmd, int start, int len)
{
	int	nb_allocation;
	t_data	*head;
	t_data	*headtmp;
	t_data  cmdata;
	int		i;
	int		tmp;
	int		j;
	int		l;
	char	*file_name;
	int		type;

	head = NULL;
	file_name = NULL;
	type = 0;
	tmp = start;
	i = 0;
	j = 0;
	l = 0;
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
	headtmp = head;
	while (headtmp != NULL)
	{
		j = 0;
		i = 0;
		l = check_allocation(headtmp->line_cmd);
		headtmp->arguments = (char **)malloc(sizeof(char *) * (l + 1));
		headtmp->arguments[l] = 0;
		headtmp->redirection = NULL;
		while (headtmp->line_cmd[j])
		{
			if(headtmp->line_cmd[j]->type != 1)
			{
				headtmp->arguments[i] = headtmp->line_cmd[j]->value;
				i++;
				j++;
			}
			else
			{
				type = headtmp->line_cmd[j]->type;
				if(headtmp->line_cmd[j + 1])
				{
					file_name = headtmp->line_cmd[j + 1]->value;
					j = j + 2;
				}
				else
					j = j + 1;
				lkd_redirection(&headtmp->redirection,type,file_name);
			}
		}
		headtmp = headtmp->next;
	}
	while (head != NULL)
	{
		j = 0;
		printf("----------------------------\n");
		while (head->redirection != NULL)
		{
			printf("%s\n",head->redirection->file_name);
			printf("%d\n",head->redirection->type);
			
			head->redirection = head->redirection->next;
		}
		head = head->next;
	}

	return(start);
}
void    fill_data(t_tokens *data)
{
	t_tokens	**cmd;
	int		nb_list;
	int		start;
	int		i;

	start = 0;
	nb_list = 0;
	i = 0;
	cmd = (t_tokens **)malloc(sizeof(t_tokens) * (g_toll + 1));
	while (data != NULL)
	{
		cmd[nb_list] = (t_tokens *)malloc(sizeof(t_tokens));
		cmd[nb_list]->value = ft_strdup(data->value);
		cmd[nb_list]->type = data->type;
		data = data->next;
		nb_list++;
	}
	cmd[nb_list] = 0;

	while(start <= nb_list)
	{
		start = add_to_linkdlist(cmd,start,nb_list);
		start++;
	}
}