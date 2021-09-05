/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 08:33:02 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/05 10:22:35 by mouassit         ###   ########.fr       */
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
	int end;
}				t_initial;

int				skipe_space(char *cmd);
void			token_manipulation(int indice, char *cmd);
void			put_in_parcer(char *value, int type);
int				check_arrow(int indice, char *cmd);
int				check_word(int indice, char *cmd);

#endif
