/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:48 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 23:18:39 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	find_path()
{
	int	i;

	i = -1;
	while (environ[++i] != NULL)
	{
		if (ft_strstr(environ[i], "PATH=") == 0)
			return (i);
	}
	return (-1);
}

int	check_access_path(t_main *main, char *cmd)
{
	size_t	i;

	if (!cmd)
		return (err_cmd(main, cmd, 2), -1);
	if (ft_find_slash(cmd) == 0)
	{
		main->cur_path = ft_strdup(cmd);
		if (access(cmd, F_OK & X_OK) == 0)
			return (0);
		free(main->cur_path);
		err_cmd(p, cmd, 9);
	}
	else
	{
		i = -1;
		while (main->path[++i])
		{
			p->cur_path = ft_strjoin(p->path[i], cmd);
			if (access(p->cur_path, F_OK & X_OK) == 0)
				return (0);
			free(main->cur_path);
		}
		err_cmd(main, cmd, 2);
	}
	return (-1);
}
