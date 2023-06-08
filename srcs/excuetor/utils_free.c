/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:41 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 23:19:01 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	free_path(t_main *main);
void	free_cmd(t_main *main);

void	free_path(t_main *main)
{
	int	i;

	if (main->pid)
		free(main->pid);
	if (!main->path)
		return ;
	i = -1;
	while (main->path[++i])
		free(main->path[i]);
	free(main->path);
}

void	free_cmd(t_main *main)
{
	int	i;

	if (!main->cmd)
		return ;
	i = -1;
	while (main->cmd[++i])
		free(main->cmd[i]);
	free(main->cmd);
}
