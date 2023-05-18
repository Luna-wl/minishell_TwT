/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/18 13:55:02 by wluedara         ###   ########.fr       */
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

int	dollar_sign()
{

}

void	expander(t_main *main)
{
	t_cmd	*tmp;
	int		i;

	(void)main;
	tmp = main->cmd;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->str[++i])
		{
			tmp->str[i] = cut_quote(tmp->str[i]);
		}
		tmp = tmp->next;
	}
}
