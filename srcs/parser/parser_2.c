/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:03:55 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/31 14:00:36 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

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

char	*copy_str(char *str)
{
	char	*s;
	int		len;
	int		i;

	len = ft_strlen(str);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	i = 0;
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
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
		new[i++] = copy_str(tmp->str);
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
	tmp->str = copy_two_stars(&list);
	tmp->next = NULL;
	add_last_cmd(cmd, tmp);
}
