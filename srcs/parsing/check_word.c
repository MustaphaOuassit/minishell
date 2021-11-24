/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:51:06 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/23 11:14:48 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int 	check_nb(char *str, int start)
{
	int i;

	i = 0;
	while (str[start])
	{
		if((str[start] == '\"') || (str[start] == '$'))
			break;
		start++;
		i++;
	}
	return(i);
}

void	fill_string_double(int indice, int ele)
{
	int l;
	int i;
	char **check;
	int r;
	int t;
	int a;
	int j;
	int tmp;
	int m;
	r = 0;
	t = 0;
	tmp = 0;
	a = 0;
	check = NULL;
	l = 1;
	i = g_start + 1;
	m = g_start + 1;

	while (g_cmd[m])
	{
		if(g_cmd[m] == ele)
			break ;
		if(g_cmd[m] == '$')
		{
			l++;
			if((g_cmd[m - 1] == ' ') || (g_cmd[m - 1] == '\"'))
				l = l - 1;
		}
		if((g_cmd[m] == ' ') && (g_cmd[m + 1] != ele) && (g_cmd[m + 1] != ' ') && (g_cmd[m + 1] != '\0'))
			l++;
		m++;
	}
	l++;
	check = (char **)malloc(sizeof(char *) * (l + 1));
	check[l] = 0;
	l = 0;
	while (i < (int)ft_strlen(g_cmd))
	{
		if(g_cmd[i] == '\"')
			break;
		r = 0;
		if(g_cmd[i] != '$')
		{
			tmp = i;
			while ((g_cmd[i] != '\"') && (g_cmd[i] != '$') && (g_cmd[i] != '\0') )
			{
				i++;
				r++;
			}
			i--;
			if(check[l])
			{
				check[l] = (char *)malloc(sizeof(char) * (r + 1));
				check[l][r] = '\0';
				t = 0;
				while((check[l][t]) && (g_cmd[tmp]))
				{
					check[l][t] = g_cmd[tmp];
					tmp++;
					t++;
				}
				l++;
			}
		}
		else
		{
			a = g_cmd[i];
			tmp = i;
			r++;
			i++;
			while ((g_cmd[i] != ' ') && (g_cmd[i] != '\"') && (g_cmd[i] != '$') && (g_cmd[i] != '\0') )
			{
				i++;
				r++;
			}
			i--;
			if(check[l])
			{
				check[l] = (char *)malloc(sizeof(char) * (r + 1));
				check[l][r] = '\0';
				t = 0;
				while((check[l][t]) && (g_cmd[tmp]))
				{
					if(t == 0)
						check[l][t] = a;
					else
						check[l][t] = g_cmd[tmp];
					tmp++;
					t++;
				}
				l++;
			}
		}
		i++;
	}
	check[l] = 0;
	l = 0;
	j = 0;
	i = 0;
	while (check[l])
	{
		if (check[l][0] == '$')
			check[l] = ft_strdup("ls - la");
		i = 0;
		while (check[l][i])
		{
			j++;
			i++;
		}
		l++;
	}

	g_str = (char *)malloc(sizeof(char) * (j + 1));
	g_str[j] = '\0';
	g_start++;
	i = 0;
	l = 0;
	while (g_start <= indice)
	{
		while (check[l])
		{
			r = 0;
			while (check[l][r])
			{
				g_str[i] = check[l][r];
				i++;
				r++;
			}
			l++;
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
	g_str[g_rmp] = '\0';
}


int	check_character(int i, int indice, char *ele)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[1])
				fill_string(indice, ele[1]);
			g_start++;
		}
	}
	return (indice);
}

int	check_character_double(int i, int indice, char *ele)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[0])
			{
				fill_string_double(indice, ele[0]);
			}
			g_start++;
		}
	}
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

int	add_to_string_double(int indice, char *ele)
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
	indice = check_character_double(initial.i, indice, ele);
	return (indice);
}

int	check_double(t_tokens **head ,int indice)
{
	if (indice + 1 < (int)ft_strlen(g_cmd))
	{
		if (g_cmd[indice + 1] == '<')
		{
			put_in_parcer(head,"<<", 22);
			return (indice + 1);
		}
	}
	put_in_parcer(head, "<", 15);
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
		else if (g_cmd[indice] == '<')
			indice = check_double(head, indice);
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
			indice = check_couts(indice);
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