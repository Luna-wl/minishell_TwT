/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:03:55 by wluedara          #+#    #+#             */
/*   Updated: 2023/07/03 13:38:21 by pnamwayk         ###   ########.fr       */
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
		*cmd = last;
	else
	{
		tmp = *cmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = last;
	}
}

void	create_list_cmd(t_cmd **cmd, t_lexer *list)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return ;
	tmp->str = copy_two_stars(&list);
	tmp->cnt_infile = cnt_infile(tmp->str);
	tmp->cnt_heredoc = cnt_heredoc(tmp->str);
	tmp->cnt_outfile = cnt_outfile(tmp->str);
	tmp->cnt_append = cnt_append(tmp->str);
	tmp->all_infile = tmp->cnt_infile + tmp->cnt_heredoc;
	tmp->all_outfile = tmp->cnt_outfile + tmp->cnt_append;
	tmp->heredoc_file = check_heredoc(tmp->str, tmp->cnt_heredoc);
	// tmp->infile_name = check_infile(tmp->str, tmp->cnt_infile);
	tmp->infile_name = check_infile(tmp->str, tmp->all_infile);
	tmp->outfile_name = check_outfile(tmp->str, tmp->all_outfile);
	tmp->append_file = check_append(tmp->str, tmp->cnt_append);
	tmp->next = NULL;
	add_last_cmd(cmd, tmp);
}

