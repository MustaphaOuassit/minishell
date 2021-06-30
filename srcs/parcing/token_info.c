/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:07:58 by mouassit          #+#    #+#             */
/*   Updated: 2021/06/30 20:11:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parcing.h"

int    skipe_space(char *cmd)
{
    int i;

    i = 0;
    while (i != (int)ft_strlen(cmd))
    {
        if((cmd[i] != ' ') || (cmd[i] != '\t'))
            break;
        i++;
    }
    return(i);
}

void    put_in_parcer(char *value, int type)
{
    printf("%s : %d\n",value,type);
}

int    check_arrow(int indice, char *cmd)
{
    if(indice + 1 < (int)ft_strlen(cmd))
    {
           if(cmd[indice + 1] == '>')
           {
               put_in_parcer(">>",2);
               return(indice + 1);
           }
    }
    put_in_parcer(">",1);
    return(indice);
}

int     check_word(int indice , char *cmd)
{
    int i;
    char *str;
    int j;
    int start;

    i = 0;
    j = 0;
    start = indice;
    if (cmd[indice] == ' ')
        return(indice++);
    while((indice != (int)ft_strlen(cmd)) && (cmd[indice] != ' ') && (cmd[indice] != '\t') && (cmd[indice] != '|') && (cmd[indice] != '>'))
    {
        if(cmd[indice] == '"')
        {
            start = indice;
            indice++;
            while(indice != (int)ft_strlen(cmd))
            {
                if(cmd[indice] == '"')
                    break;
                indice++;
                i++;
            }
            if(i > 0)
            {
                str = (char *)malloc((i + 1) * sizeof(char));
                start++;
                while (start != indice)
                {
                    str[j] = cmd[start];
                    start++;   
                    j++;
                }
                str[j] = '\0';
                put_in_parcer(str,3);
                free(str);
            }
            break;
        }
        else
            indice++;
     }
     return(indice);   
}

void    token_manipulation(int indice, char *cmd)
{
    while (indice <= (int)ft_strlen(cmd))
    {
        if(cmd[indice] == '|')
        {
            put_in_parcer("|",0);
        }
        else if(cmd[indice] == '>')
            indice = check_arrow(indice,cmd);
        else
            indice = check_word(indice,cmd);
        indice++;
    }
}