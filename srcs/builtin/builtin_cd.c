/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:12 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 02:26:00 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	builtin_cd(t_cmd *cmd)
{
	int		status;

	if (cmd->command[1] == NULL)
		status = chdir(getenv("HOME"));
	else
		status = chdir(cmd->command[1]);
	return (status);
}
