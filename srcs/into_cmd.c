/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/03 16:20:47 by wluedara         ###   ########.fr       */
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
	// printf("str = %s\n", str);
	char	**test;
	char	***str2 = NULL;

	test = ft_split(str, '|');
	if (!cut_test(test))
		return (0);
	str2 = cut_test(test);
	for(int x = 0; str2[x]; x++) {
		printf("====x = |%d|=====\n", x);
		for(int o = 0; str2[x][o] ; o++) {
			printf("str2[%d] = |%s|\n", o, str2[x][o]);
		}
	}
	(void)main;
	// main->str_cmd = cut_test(test); // put lexer after split into main->str_cmd
	// pim_split(main->str_cmd);
	// if (!check_error(main->str_cmd))
	// {
		// pim_split(main->str_cmd);
	// 	return (0);
	// }
	// main->lexer = spilt_to_list(main->str_cmd, main->lexer); // make char** into linked list
	// pim_list(main->lexer);
	// exit(0);
	// main->cmd = list_cmd(main); // convert lexer to parser and redirect info
	// del_list_lexer(&main->lexer); // del lexer after finish parser
	return (1);
	// pim_cmd(main->cmd);
}
