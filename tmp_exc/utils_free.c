/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:41 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/07/01 23:18:58 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	free_path(t_main *main);
void	free_cmd(t_main *main);

void	free_path(t_main *main)
{
	int	i;

	if (p->pid)
		free(p->pid);
	if (!p->path)
		return ;
	i = -1;
	while (p->path[++i])
		free(p->path[i]);
	free(p->path);
}

void	free_cmd(t_main *main)
{
	int	i;

	if (!p->cmd)
		return ;
	i = -1;
	while (p->cmd[++i])
		free(p->cmd[i]);
	free(p->cmd);
}
