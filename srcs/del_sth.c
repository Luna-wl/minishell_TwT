/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:35:02 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/27 12:02:30 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	del_list_lexer(t_lexer **list)
{
	t_lexer	*tmp;
	t_lexer	*del;

	if (!list)
		return ;
	del = *list;
	while (del != NULL)
	{
		tmp = del->next;
		if (del->str != NULL)
			free(del->str);
		free(del);
		del = tmp;
	}
	*list = NULL;
}

void	del_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*del;

	if (!cmd)
		return ;
	del = *cmd;
	while (del != NULL)
	{
		tmp = del->next;
		if (del->str != NULL)
			del_split(del->str);
		if (del->infile_name != NULL)
			del_split(del->infile_name);
		if (del->outfile_name != NULL)
			del_split(del->outfile_name);
		if (del->heredoc_file != NULL)
			del_split(del->heredoc_file);
		if (del->append_file != NULL)
			del_split(del->append_file);
		free(del);
		del = tmp;
	}
}

void	del_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	del_sam_dao(char ***s)
{
	int	i;
	int	j;

	if (s)
	{
		i = 0;
		while (s[i] != NULL)
		{
			j = 0;
			while (s[i][j] != NULL)
			{
				free(s[i][j]);
				j++;
			}
			free(s[i]);
			i++;
		}
		free(s);
	}
}
