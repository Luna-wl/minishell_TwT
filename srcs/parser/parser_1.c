/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:49:47 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/31 14:00:11 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

int	find_pipe(t_lexer *list, t_cmd *cmd)
{
	t_lexer	*tmp;
	int		num;
	(void)cmd;

	tmp = list;
	num = 1;
	g_num.num_pipe = 0;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->str, "|", 1) == 0)
		{
			num++;
			g_num.num_pipe++;
		}
		tmp = tmp->next;
	}
	return (num);
}

int	find_cmd_num(t_lexer *list)
{
	t_lexer	*tmp;
	int		cmd;

	tmp = list;
	cmd = 0;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->str, "|", 1) != 0)
			cmd++;
		else
			break ;
		tmp = tmp->next;
	}
	return (cmd);
}

void	next_cmd(t_lexer **list, int index)
{
	t_lexer	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->index <= index)
			tmp = tmp->next;
		else
			break ;
	}
	*list = tmp;
}

t_cmd	*list_cmd(t_lexer *list, t_cmd *cmd)
{
	int			size;
	int			word;
	int			i;
	t_lexer		*new;

	size = find_pipe(list, cmd);
	i = 0;
	new = list;
	while (i < size)
	{
		create_list_cmd(&cmd, new);
		word = find_cmd_num(new);
		next_cmd(&new, word);
		insert_index(&new, stack_lenght(&new));
		i++;
	}
	return (cmd);
}
