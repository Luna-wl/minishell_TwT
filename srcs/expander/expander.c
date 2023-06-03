/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/03 18:19:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*detact_dollar(char *str, t_main *main)
{
	char	*val;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(main->path[j]);
	if (ft_isdigit(str[i + 1]))
		return (&str[i + 1]);
	else if (ft_isalpha(str[i + 1]))
	{
		while (main->path[j])
		{
			if (ft_strncmp(&str[i + 1], main->path[j], len) == 0)
			{
				val = getenv(main->path[j]);
				return (val);
			}
			j++;
		}
	}
	// else if (str[i + 1] == '?')
	// 	find_exit_code();
	return (0);
}

char	*expander_handel(t_main *main, char *str)
{
	char	*val;

	val = ft_strdup("\0");
	if (str[0] == '$')
		val = ft_strjoin(val, detact_dollar(str, main));
	else if (str[0] == '\"')
		val = ft_strjoin(val, detact_quote(str, main, val));
	else if (str[0] == '\'')
	{
		str = cut_quote(str);
		val = ft_strjoin(val, str);
	}
	return (val);
}

void	expander(t_main *main)
{
	t_cmd	*tmp;
	int		i;
	char	*expan;

	tmp = main->cmd;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->str[++i])
		{
			expan = expander_handel(main, tmp->str[i]);
			printf("In expan main value = %s\n", expan);
		}
		tmp = tmp->next;
	}
	// free(expan);
}
