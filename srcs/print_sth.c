/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/08 22:14:01 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	pim_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		printf(BYEL"str[%d]\n", i);
		// printf(BYEL"heredoc_file = %s\n", cmd->heredoc_file);
		j = 0;
		while (tmp->str[j])
		{
			printf(GRN"tmp->str[%d] = %s\n"RESET, j, tmp->str[j]);
			j++;
		}
		tmp = tmp->next;
		i++;
	}
}

void	pim_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf(MAG"s[%d] = %s\n"RESET, i, s[i]);
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
