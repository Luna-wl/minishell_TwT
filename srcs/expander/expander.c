/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/03 17:32:12 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*cut_quote(char *str, char *new)
{
	int	i;

	i = len_quote(str);
	if (str[0] == '\'' | str[0] == '\"')
		new = copy_str(&str[1], i, new);
	else
		new = copy_str(str, i, new);
	return (new);
}

int	dollar_sign()
{

}

void	expander(t_main *main)
{
	t_cmd	*tmp;
	// int		i;
	char	*new;

	(void)main;
	tmp = main->cmd;
	new = ft_strdup("\0");
	new = cut_quote(tmp->str[0], new);
	// while (tmp->next != NULL)
	// {
	// 	i = 0;
	// 	while (tmp->str[i])
	// 	{
	// 		new = cut_quote(tmp->str[i], new);
	// 		// printf("new = %s\n", new);
	// 		// printf("str = %s\n", tmp->str[i]);
	// 		i++;
	// 	}
	// 	tmp = tmp->next;
	// }
}