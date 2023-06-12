/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/12 16:42:25 by wluedara         ###   ########.fr       */
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

void	get_cmd(t_main *main, char *str)
{
	if (!cut_cmd(str))
		return ;
	main->str_cmd = cut_cmd(str);
	if (!check_error(main->str_cmd))
	{
		del_split(main->str_cmd);
		return ;
	}
	main->lexer = spilt_to_list(main->str_cmd, main->lexer);
	// pim_list(main->lexer);
	main->cmd = list_cmd(main);
	del_list_lexer(&main->lexer);
	pim_cmd(main->cmd);
}
