/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:11:25 by ayafdel           #+#    #+#             */
/*   Updated: 2021/11/25 12:11:27 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
int     is_int(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' && ft_strlen(str) > 2)
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
        ft_putstr_fd("bash: ", 2);
        ft_putstr_fd(args[1], 2);
        ft_putstr_fd(": numeric argument required\n ", 2);
        exit(255);
    }
    if (args[2])
    {
        ft_putstr_fd("bash: exit: too many arguments\n", 2);
        return (1);
    }
    exit(ft_atoi(args[1]) % 256);
    return (0);
}