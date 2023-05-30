/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:03:55 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/29 17:42:26 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	stack_lenght(t_lexer **list)
{
	int		len;
	t_lexer	*tmp;

	len = 0;
	tmp = *list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char	**copy_two_stars(t_lexer **list)
{
	t_lexer	*tmp;
	char	**new;
	int		len;
	int		i;

	if (!list)
		return (0);
	len = find_cmd_num(*list);
	new = malloc(sizeof(char *) * (len + 1));
	i = 0;
	tmp = *list;
	while (i < len && tmp != NULL)
	{
		new[i++] = ft_strdup(tmp->str);
		tmp = tmp->next;
	}
	new[i] = NULL;
	return (new);
}

void	add_last_cmd(t_cmd **cmd, t_cmd *last)
{
	t_cmd	*tmp;

	if (*cmd == NULL)
	{
		*cmd = last;
		return ;
	}
	tmp = *cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
}

void	create_list_cmd(t_cmd **cmd, t_lexer *list)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return ;
	tmp->str = copy_two_stars(&list);
	tmp->next = NULL;
	add_last_cmd(cmd, tmp);
}
