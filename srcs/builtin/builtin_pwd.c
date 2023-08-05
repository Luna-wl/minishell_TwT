/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:08:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 21:44:04 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	builtin_pwd(t_main *main, t_cmd *cmd)
{
	char	*path;
	char	buf[PATH_MAX];

	(void)cmd;
	(void) main;
	path = getcwd(buf, PATH_MAX);
	if (path == NULL)
	{
		perror("getcwd() error");
		main->exit_status = 1;
		// exit(EXIT_FAILURE);
	}
	else
	{
		printf("%s\n", path);
		main->exit_status = 0;
	}
	// exit(cmd->exit_status);
	exit(main->exit_status);
}

/*
	This program places the name of the current directory in the
buffer array, then displays the name of the current directory
on the screen.
	Passing NULL as the buffer forces getcwd to allocate
memory for the path, which allows the code to support file paths
longer than _MAX_PATH, which are supported by NTFS.
*/
