/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:09:20 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 16:05:17 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	builtin_env(t_main *main, t_cmd *cmd)
{
	int	i;

	if (cmd->command && cmd->command[1])
		exit(127);
		// return (err_builtin(main, cmd, 127));
	(void) cmd;
	(void) main;
	// if (!environ)
	// 	return (-1);
	i = -1;
	while (environ[++i])
	{
		if (ft_strrchr(environ[i], '='))
			printf("%s\n", environ[i]);
	}
	// exit(EXIT_SUCCESS);
	exit(0);
	return (0);
}

// int print_export_sorted
