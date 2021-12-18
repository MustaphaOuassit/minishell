/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:11:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/18 12:48:11 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
int     is_int(char *str)
{
    int i;

    i = 0;
    if (ft_strcmp(str, "9223372036854775807") > 0 && ft_strlen(str) > 18)
        return (0);
    if (*str == '-' && ft_strcmp(str, "-9223372036854775808") > 0 && ft_strlen(str) > 19)
        return (0);
    if (str[0] == '-' && ft_strlen(str) >= 2)
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int    ft_exit(char **args)
{
    int i;

    i = 0;

    ft_putstr_fd("exit\n", 2);
    if (!args[1])
        exit(0);
    if (!is_int(args[1]))
    {	
        ft_putstr_fd("-> minishell: ", 2);
        ft_putstr_fd(args[1], 2);
        ft_putstr_fd(": numeric argument required\n", 2);
        exit(255);
    }
    if (args[2])
    {
        ft_putstr_fd("-> minishell: exit: too many arguments\n", 2);
        return (1);
    }
    exit(ft_atoi(args[1]) % 256);
    return (0);
}