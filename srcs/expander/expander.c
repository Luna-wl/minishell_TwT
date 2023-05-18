/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/17 22:01:14 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*cut_quote(char *str)
{
	int		i;
	char	*new;

	i = len_quote(str);
	if (str[0] == '\'' | str[0] == '\"')
		new = copy_str(&str[1], i);
	else
		new = copy_str(str, i);
	free(str);
	return (new);
}

char	*detact_dollar(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i + 1]))
		return (&str[i + 1]);
	// if (&str[i + 1])
	return (0);
}

char	*expander_handel(t_main *main, char *str)
{
	char	*val;

	(void)main;
	if (str[0] == '\'')
		val = one_quote(str);
	else if (str[0] == '\"')
		val = double_quote(str);
	else if (str[0] == '$')
		val = detact_dollar(str);
	return (0);
}

void	expander(t_main *main)
{
	t_cmd	*tmp;
	int		i;
	char	*expan;

	(void)main;
	tmp = main->cmd;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->str[++i])
		{
			expan = expander_handel(main, tmp->str[i]);
			// printf("value = %s\n", expan);
			// tmp->str[i] = cut_quote(tmp->str[i]);
		}
		tmp = tmp->next;
	}
}
