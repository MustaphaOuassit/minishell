/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:51:06 by mouassit          #+#    #+#             */
/*   Updated: 2021/11/20 10:53:49 by ayafdel          ###   ########.fr       */
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

void	fill_string_double(int indice, int ele, char **dbcouts)
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
	char *couts;
	char *double_couts;

	double_couts = NULL;
	r = 0;
	t = 0;
	tmp = 0;
	a = g_start + 1;
	check = NULL;
	l = 1;
	i = 0;
	m = 0;
	couts = NULL;

	while (g_cmd[a])
	{
		t++;
		if(g_cmd[a] == '\"')
		{
			r = 1;
			t--;
		}
		if(g_cmd[a] == '\'')
			t--;
		a++;
	}
	t = t + 2;
	couts = (char *)malloc(sizeof(char) * (t + 1));
	a = g_start + 1;
	couts[t] = '\0';
	tmp = t;
	t = 0;
	r = 0;
	while (couts[t])
	{
		if(t == 0)
		{
			couts[t] = '\"';
			t++;
		}
		else
		{
			if(t == tmp - 1)
			{
				couts[t] = '\"';
				t++;
			}
			else
			{
				if(g_cmd[a] != '\"')
				{
					if(g_cmd[a] == '\'')
						a++;
					if(g_cmd[a] != '\"')
					{
						couts[t] = g_cmd[a];
						t++;
					}
				}
				a++;
			}
		}
	}
	tmp = 0;
	r = 0;
	m++;
	i++;
	while (couts[m])
	{
		if(couts[m] == ele)
			break ;
		if(couts[m] == '$')
		{
			l++;
			if((couts[m - 1] == ' ') || (couts[m - 1] == '\"'))
				l = l - 1;
		}
		if((couts[m] == ' ') && (couts[m + 1] != ele) && (couts[m + 1] != ' ') && (couts[m + 1] != '\0'))
			l++;
		m++;
	}
	l++;
	check = (char **)malloc(sizeof(char *) * (l + 1));
	check[l] = 0;
	l = 0;
	while (i < (int)ft_strlen(g_cmd))
	{
		if(couts[i] == '\"')
			break;
		r = 0;
		if(couts[i] != '$')
		{
			tmp = i;
			while ((couts[i] != '\"') && (couts[i] != '$') && (couts[i] != '\0') )
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
				while((check[l][t]) && (couts[tmp]))
				{
					check[l][t] = couts[tmp];
					tmp++;
					t++;
				}
				l++;
			}
		}
		else
		{
			a = couts[i];
			tmp = i;
			r++;
			i++;
			while ((couts[i] != ' ') && (couts[i] != '\"') && (couts[i] != '$') && (couts[i] != '\0') )
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
				i--;
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

	double_couts = (char *)malloc(sizeof(char) * (j + 1));
	double_couts[j] = '\0';
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
				double_couts[i] = check[l][r];
				i++;
				r++;
			}
			l++;
		}
		g_start++;
	}
	*dbcouts = ft_strdup(double_couts);
}

void	fill_string(int indice, int ele,char **couts)
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
	*couts = ft_strdup(g_str);
}


int	check_character(int i, int indice, char *ele, char **couts)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[1])
				fill_string(indice, ele[1],couts);
			g_start++;
		}
	}
	return (indice);
}

int	check_character_double(int i, int indice, char *ele,char **couts)
{
	if (i > 0)
	{
		g_str = (char *)malloc(((int)ft_strlen(g_cmd)) * sizeof(char *));
		while (g_start <= indice)
		{
			if (g_cmd[g_start] == ele[0])
			{
				fill_string_double(indice, ele[0],couts);
			}
			g_start++;
		}
	}
	return (indice);
}

int	add_to_string(int indice, char *ele, char **couts)
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
	indice = check_character(initial.i, indice, ele,couts);
	return (indice);
}

int	add_to_string_double(int indice, char *ele, char **couts)
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
	indice = check_character_double(initial.i, indice, ele,couts);
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