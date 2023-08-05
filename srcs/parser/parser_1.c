/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:49:47 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 21:09:28 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

// int	find_pipe(t_main *main)
// {
// 	t_lexer	*tmp;
// 	int		num;

// 	tmp = main->lexer;
// 	num = 1;
// 	while (tmp != NULL)
// 	{
// 		if (ft_strncmp(tmp->str, "|", 1) == 0)
// 		{
// 			num++;
// 			main->num_pipe++;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (num);
// }

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

// int	find_cmd_size(t_cmd *cmd)
// {
// 	t_lexer	*tmp;
// 	int		cmd;

// 	tmp = cmd;
// 	cmd = 0;
// 	while (tmp != NULL)
// 	{
// 		cmd++;
// 		tmp = tmp->next;
// 	}
// 	return (cmd);
// }

// void	next_cmd(t_lexer **list, int index)
// {
// 	t_lexer	*tmp;

// 	tmp = *list;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->index <= index)
// 			tmp = tmp->next;
// 		else
// 			break ;
// 	}
// 	insert_index(&tmp, stack_lenght(&tmp));
// 	*list = tmp;
// }

void	add_last_new(t_cmd **cmd, t_cmd *last)
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

void	create_list(t_cmd **cmd, char **s)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return ;
	tmp->str = copy_two_stars_new(s);
	tmp->cnt_infile = cnt_infile(tmp->str);
	tmp->cnt_heredoc = cnt_heredoc(tmp->str);
	tmp->cnt_outfile = cnt_outfile(tmp->str);
	tmp->cnt_append = cnt_append(tmp->str);
	tmp->all_infile = tmp->cnt_infile + tmp->cnt_heredoc;
	tmp->all_outfile = tmp->cnt_outfile + tmp->cnt_append;
	tmp->heredoc_file = check_heredoc(tmp->str, tmp->cnt_heredoc);
	tmp->infile_name = check_infile(tmp->str, tmp->all_infile);
	tmp->outfile_name = check_outfile(tmp->str, tmp->all_outfile);
	tmp->append_file = check_append(tmp->str, tmp->cnt_append);
	tmp->next = NULL;
	add_last_new(cmd, tmp);
}

t_cmd	*list_cmd(t_main *main, char ***str)
{
	int	size;
	int	i;

	i = 0;
	size = find_size3(str);
	while (i < size)
	{
		create_list(&main->cmd, str[i]);
		i++;
	}
	return (main->cmd);
}
