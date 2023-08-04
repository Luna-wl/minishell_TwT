/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:12 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/01 23:22:54 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	builtin_cd(t_main *main, t_cmd *cmd)
{
	(void) cmd;
	(void) main;

	int		status;

	if (cmd->command[1] == NULL)
		status = chdir(getenv("HOME"));
	else
		status = chdir(cmd->command[1]);
	return (status);
}
