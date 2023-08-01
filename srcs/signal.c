/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:44:26 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/01 15:16:21 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

// void	sighandle(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		ft_putstr_fd("\n", STDOUT_FILENO);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// }

// void	handel_c(int sig)
// {
// 	if (sig == SIGINT)
// 		ft_putstr_fd("\n", STDOUT_FILENO);
// }

// void	sigint_handle(int mode)
// {
// 	if (mode == 1)
// 		signal(SIGINT, sighandle);
// 	else
// 		signal(SIGINT, handel_c);
// }

// void	init_signal(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	sigint_handle(1);
// }
