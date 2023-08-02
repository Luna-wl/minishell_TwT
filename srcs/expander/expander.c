/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/02 14:12:39 by wluedara         ###   ########.fr       */
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
	len = ft_strlen(main->envp[j]);
	if (ft_isdigit(str[i + 1]))
	{
		str = replace_val(&str[i + 1], str);
		return (str);
	}
	else if (ft_isalpha(str[i + 1]))
	{
		while (main->envp[j])
		{
			if (ft_strncmp(&str[i + 1], main->envp[j], len) == 0)
			{
				val = getenv(main->envp[j]);
				str = replace_val(val, str);
				return (str);
			}
			j++;
		}
	}
	// else if (str[i + 1] == '?')
	// 	find_exit_code();
	return (0);
}

char	*expander_handel(t_main *main, char *str, char **cmd)
{
	char	*val;

	val = ft_strdup("\0");
	if (str[0] == '$')
	{
		val = ft_strjoin(val, detact_dollar(str, main));
	}
	else if (str[0] == '\"')
	{
		val = ft_strjoin(val, detact_quote(str, main, val));
		// printf("\" val = |%s|\n", val);
	}
	else if (str[0] == '\'')
	{
		str = cut_quote(str);
		val = ft_strjoin(val, str);
		// printf("\' val = |%s|\n", val);
	}
	check_val(cmd);
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
			expan = expander_handel(main, tmp->str[i], tmp->str);
			// printf("In expan main value = |%s|\n", expan);
			(void)expan;
			// printf("tmp->str[%d] = |%s|\n", i, tmp->str[i]);
		}
		tmp = tmp->next;
	}
}
