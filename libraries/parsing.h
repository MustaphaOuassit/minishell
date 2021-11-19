/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:33:02 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 13:39:28 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

// 5 $

typedef struct s_initialisation
{
	int	i;
	int	t;
	int	len;
	int	sword;
}				t_initial;

char	*g_cmd;
char	*g_str;
int		g_start;
int		g_rmp;
int		g_toll;

typedef		struct s_tokens{
	char	*value;
	int		type;
	struct s_tokens *next;
}		t_tokens;

typedef		struct s_redirection{
	char	*file_name;
	int		type;
	struct s_redirection *next;
}			t_redirection;

typedef		struct s_data{
	t_tokens	**line_cmd;
	char	**arguments;
	t_redirection *redirection;
	struct s_data *next;
}		t_data;

int				skipe_space(void);
void			token_manipulation(int indice);
int				put_in_parcer(t_tokens **head, char *value, int type);
int				check_arrow(t_tokens **head, int indice);
int				add_to_string(int indice, char *ele);
int				add_to_string_double(int indice, char *ele);
void			fill_string_double(int indice, int ele);
int				check_couts(int indice);
void			check_alloc(int indice,char *str,int *l);
char			*continue_check(int len, int sword);
int				check_word(t_tokens **head, int indice);
void			fill_data(t_tokens *data);
char			*get_env(char *value);
int		   		fill_linkdlist(t_data **head, t_tokens **data);
#endif
