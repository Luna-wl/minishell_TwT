/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:44:26 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 00:42:16 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	sighandle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handel_c(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

void	sigint_handle(int mode)
{
	if (mode == 1)
		signal(SIGINT, sighandle);
	else if (mode == 2)
	{
		signal(SIGINT, handel_c);
		signal(SIGQUIT, sigquit_handle);
	}
}

void	sigquit_handle(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		ft_putstr_fd("Quit: ", STDOUT_FILENO);
		ft_putnbr_fd(sig, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void	init_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	sigint_handle(1);
}
