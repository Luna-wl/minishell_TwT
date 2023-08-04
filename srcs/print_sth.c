/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/04 01:12:08 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	pim_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		j;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		printf(BYEL"cnt_infile = %d\n", tmp->cnt_infile);
		printf(BYEL"cnt_heredoc = %d\n", tmp->cnt_heredoc);
		printf(BYEL"cnt_outfile = %d\n", tmp->cnt_outfile);
		printf(BYEL"cnt_append = %d\n", tmp->cnt_append);
		printf(BYEL"all_infile = %d\n", tmp->all_infile);
		printf(BYEL"all_outfile = %d\n", tmp->all_outfile);
		printf(BMAG"heredoc_file\n");
		pim_split(tmp->heredoc_file);
		printf(BMAG"append_file\n");
		pim_split(tmp->append_file);
		printf(BMAG"infile_name\n");
		pim_split(tmp->infile_name);
		printf(BMAG"outfile_name\n");
		pim_split(tmp->outfile_name);
		printf(BMAG"=====[cmd %d]======\n", i);
		j = 0;
		while (tmp->str[j])
		{
			printf(GRN"tmp->str[%d] = %s\n"RESET, j, tmp->str[j]);
			j++;
		}
		tmp = tmp->next;
		i++;
		// tmp->cnt_cmd++;
	}
		// printf(BYEL"str[%d]\n", tmp->cnt_cmd );
	// tmp->command = malloc(sizeof * (tmp->cnt_cmd + 1))
	// printf(BMAG"cnt command = %d\n", tmp->cnt_cmd);
}

void	pim_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf(MAG"{s[%d] = %s}\n"RESET, i, s[i]);
		i++;
	}
}

void	pim_list(t_lexer *list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		printf(CYN"tmp->str[%d] = %s\t>>\ttmp->index = %d\n"RESET, i, \
		tmp->str, tmp->index);
		i++;
		tmp = tmp->next;
	}
}

void	pim_sam_dao(char ***s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != NULL)
	{
		// printf("==== i = |%d| =====\n", i);
		j = 0;
		while (s[i][j] != NULL)
		{
			printf("s[%d] = |%s|\n", j, s[i][j]);
			j++;
		}
		i++;
	}
}
