/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:12 by mouassit          #+#    #+#             */
/*   Updated: 2021/06/30 09:27:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parcing.h"

int main()
{
    char *line;
    int indice_start;
    while(1)
    {
        write(1,"-> minishell ",ft_strlen("-> minishell "));
        get_next_line(0,&line);
        indice_start = skipe_space(line);
        token_manipulation(indice_start,line);
    }
    return(0);
}