/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:09:20 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/01 15:18:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

void	builtin_env(t_cmd *cmd, char **envp)
{
	int	i;

	(void)cmd;
	i = 0;
	while (envp[i])
	{
		printf(GRN"%s\n"RESET, envp[i]);
		i++;
	}
}
