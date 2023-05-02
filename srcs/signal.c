/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:44:26 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:24 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

void	sig_handler_c(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_forced_update_display();
	}
}

void	init_signal(void)
{
	
	signal(SIGINT, sig_handler_c);
	signal(SIGQUIT, SIG_IGN);
}
