/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:08:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/07/15 21:16:17 by pnamwayk         ###   ########.fr       */
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
		exit(-1);
		// return (EXIT_FAILURE);
	}
	else
		printf("%s\n", path);
	exit(0);
	return (0);
}

/*
	This program places the name of the current directory in the
buffer array, then displays the name of the current directory
on the screen.
	Passing NULL as the buffer forces getcwd to allocate
memory for the path, which allows the code to support file paths
longer than _MAX_PATH, which are supported by NTFS.
*/
