/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:12 by mouassit          #+#    #+#             */
/*   Updated: 2021/06/29 19:23:28 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parcing.h"

int main()
{
    char *line;
    while(1)
    {
        write(1,"-> mishell ",ft_strlen("-> mishell "));
        get_next_line(0,&line);
    }
    return(0);
}