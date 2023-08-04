/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 00:08:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	**get_envp()
{
	char	**tmp;
	int		i;

	i = 0;
	while (environ[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (environ[i])
	{
		tmp[i] = ft_strdup(environ[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	get_cmd(t_main *main, char *str)
{
	char	**test;
	char	***str2;

	if (str[0] == '\0')
		return (0);
	test = ft_split(str, '|');
	str2 = cut_test(test);
	del_split(test);
	// pim_sam_dao(str2);
	main->cmd = list_cmd(main, str2);
	del_sam_dao(str2);
	// if (!check_error(main->str_cmd))
	// {
		// pim_split(main->str_cmd);
	// 	return (0);
	// }
	// pim_cmd(main->cmd);
	return (1);
}
