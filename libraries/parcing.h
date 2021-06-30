/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:44:09 by mouassit          #+#    #+#             */
/*   Updated: 2021/06/30 10:13:00 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int    skipe_space(char *cmd);
void    token_manipulation(int indice, char *cmd);
void    put_in_parcer(char *value, int type);
int    check_arrow(int indice, char *cmd);
int     check_word(int indice , char *cmd);

#endif