/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/01 16:24:05 by pnamwayk         ###   ########.fr       */
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
	if (!cut_cmd(str))
		return (0);
	main->str_cmd = cut_cmd(str); // put lexer after split into main->str_cmd
	if (!check_error(main->str_cmd))
	{
		del_split(main->str_cmd);
		return (0);
	}
	main->lexer = spilt_to_list(main->str_cmd, main->lexer); // make char** into linked list
	// pim_list(main->lexer);
	main->cmd = list_cmd(main); // convert lexer to parser and redirect info
	del_list_lexer(&main->lexer); // del lexer after finish parser
	// pim_cmd(main->cmd);
	return (1);
}
