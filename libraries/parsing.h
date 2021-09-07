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

int				skipe_space(void);
void			token_manipulation(int indice);
void			put_in_parcer(char *value, int type);
int				check_arrow(int indice);
int				add_to_string(int indice, char *ele);
int				check_couts(int indice);
char			*continue_check(int len, int sword);
int				check_word(int indice);

#endif
