/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 00:30:27 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	**get_envp(void)
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
	char	**test1;
	char	**test2;
	char	***str2;

	if (str[0] == '\0' || !check_error(str))
		return (0);
	test1 = ft_split(str, ' ');
	test2 = ft_split(str, '|');
	if (!test1[0] || !check_quote_pair(test2))
	{
		del_split(test1);
		return (del_split(test2), 0);
	}
	str2 = cut_test(test2);
	del_split(test1);
	del_split(test2);
	main->cmd = list_cmd(main, str2);
	del_sam_dao(str2);
	return (1);
}
