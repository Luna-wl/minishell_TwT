/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:08:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/01 15:18:36 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

void	builtin_pwd(t_cmd *cmd)
{
	char	*path;

	(void)cmd;
	path = getcwd(NULL, 0);
	if (path == NULL)
		perror("getcwd() error");
	else
	{
		printf(YEL"%s\n"RESET, path);
		free(path);
	}
}

/*
	This program places the name of the current directory in the 
buffer array, then displays the name of the current directory 
on the screen.
	Passing NULL as the buffer forces getcwd to allocate
memory for the path, which allows the code to support file paths
longer than _MAX_PATH, which are supported by NTFS.
*/