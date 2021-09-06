/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:33:02 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/06 14:52:44 by mouassit         ###   ########.fr       */
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

typedef struct s_initialisation
{
	int	i;
	int	j;
	int t;
	int	len;
    int	sword;
	int	start;
	int r;
	char **str;
}				t_initial;

char	*g_cmd;
char	*g_str;
int		g_start;

int				skipe_space();
void			token_manipulation(int indice);
void			put_in_parcer(char *value, int type);
int				check_arrow(int indice);
int				check_word(int indice);

#endif
