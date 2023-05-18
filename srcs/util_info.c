/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:51:22 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/18 14:22:29 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	find_path2(char *str)
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

char	*find_path(char *str)
{
	char	*path;
	int		len;

	len = find_path2(str);
	path = malloc(len + 1);
	if (!path)
		return (0);
	g_i.i = 0;
	g_i.j = 0;
	while (g_i.i < len)
		path[g_i.j++] = str[g_i.i++];
	path[g_i.j] = '\0';
	return (path);
}

char	**get_path()
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
	i = -1;
	j = -1;
	while (environ[++i])
		path[++j] = find_path(environ[i]);
	path[j] = NULL;
	return (path);
}
