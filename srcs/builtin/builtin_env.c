/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:09:20 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 22:17:36 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	builtin_env(t_main *main, t_cmd *cmd)
{
	int	i;

	if (!environ || (cmd->command && cmd->command[1]))
	{
		// main->exit_status = 127;
		err_builtin(main, cmd, 127);
		// return (127);
		exit(127);
	}
	i = -1;
	while (environ[++i])
	{
		if (ft_strrchr(environ[i], '='))
			printf("%s\n", environ[i]);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

// int print_export_sorted
