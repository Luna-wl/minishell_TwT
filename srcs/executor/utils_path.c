/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:48 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 02:49:00 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*ft_join_path(char *s1, char *s2);
int		check_access_path(t_main *main, t_cmd *tmp, char *cmd);

char	*ft_join_path(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	str[s1_len] = '/';
	ft_strlcpy(&str[s1_len + 1], s2, s2_len + 1);
	return (str);
}

int	check_access_path(t_main *main, t_cmd *tmp, char *cmd)
{
	size_t	i;

	if (!cmd)
		return (err_cmd(main, tmp, cmd, 2), -1);
	if (ft_find_slash(cmd) == 0)
	{
		main->cur_path = ft_strdup(cmd);
		if (access(cmd, F_OK & X_OK) == 0)
			return (0);
		free(main->cur_path);
		err_cmd(main, tmp, cmd, 9);
	}
	else
	{
		i = -1;
		while (main->path[++i])
		{
			main->cur_path = ft_join_path(main->path[i], cmd);
			if (access(main->cur_path, F_OK & X_OK) == 0)
				return (0);
			free(main->cur_path);
		}
		err_cmd(main, tmp, cmd, 2);
	}
	return (-1);
}
