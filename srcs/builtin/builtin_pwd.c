/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:08:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 02:24:57 by pnamwayk         ###   ########.fr       */
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
	}
	else
	{
		printf("%s\n", path);
		main->exit_status = 0;
	}
	exit(main->exit_status);
}
