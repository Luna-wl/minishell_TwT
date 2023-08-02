/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:51:22 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/01 17:05:29 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	find_envp2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

char	*find_envp(char *str)
{
	char	*path;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = find_envp2(str);
	path = malloc(len + 1);
	if (!path)
		return (0);
	i = 0;
	j = 0;
	while (i < len)
		path[j++] = str[i++];
	path[j] = '\0';
	return (path);
}

char	**get_envp2()
{
	char	**path;
	int		i;
	int		j;

	i = 0;
	while (environ[i])
		i++;
	path = malloc(sizeof(char *) * (i + 1));
	if (!path)
		return (0);
	i = 0;
	j = 0;
	while (environ[i])
		path[j++] = find_envp(environ[i++]);
	path[j] = NULL;
	return (path);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			path = ft_split(&environ[i][5], ':');
		}
	}
	return (path);
}

void	reset_tool(t_main *main)
{
	free(main->input);
	del_split(main->path);
	del_split(main->envp);

	main->lexer = NULL;
	main->cmd = NULL;
	main->num_pipe = 0;
	environ = get_envp(); // make extern environ to malloc
	main->envp = get_envp2(); // word that before '=' in env to check sth. as USER PWD
	main->path = get_path(main->envp); // value after that spilt with ':' PATH=
}