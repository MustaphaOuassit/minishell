/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:04:34 by ayafdel           #+#    #+#             */
/*   Updated: 2021/12/22 16:21:18 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ignore(int sig)
{
	if (sig)
	{
		return ;
	}
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_flag = 1;
		ft_putstr_fd("-> minishell ", 1);
		ft_putstr_fd(rl_line_buffer, 1);
		ft_putstr_fd("  \b\b\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("-> minishell ", 1);
		ft_putstr_fd(rl_line_buffer, 1);
		ft_putstr_fd("  \b\b", 1);
	}
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		close(0);
	}
}

void	ft_signal(int sig_place)
{
	if (sig_place == FIRST_SIG)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
	else if (sig_place == PRECHILD_SIG)
	{
		signal(SIGINT, ignore);
		signal(SIGQUIT, ignore);
	}
	else if (sig_place == HEREDOC_SIG)
		signal(SIGINT, heredoc_handler);
}
