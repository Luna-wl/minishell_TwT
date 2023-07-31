/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:44:26 by wluedara          #+#    #+#             */
/*   Updated: 2023/07/31 02:52:28 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	sig_handler_c(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		// rl_forced_update_display();
	}
}

// void	sig_handler_c(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		ft_putstr_fd("\n", STDOUT_FILENO);

// 	}
// }

void	init_signal(void)
{
	signal(SIGINT, sig_handler_c);
	signal(SIGQUIT, SIG_IGN);
}
