/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:49:47 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 23:50:45 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

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

char	**copy_two_stars_new(char **s)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (0);
	len = find_len_split(s);
	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (i < len && s[i])
	{
		new[i++] = ft_strdup(s[j++]);
	}
	new[i] = NULL;
	return (new);
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
	main->num_pipe = size - 1;
	while (i < size)
	{
		create_list(&main->cmd, str[i]);
		i++;
	}
	return (main->cmd);
}
