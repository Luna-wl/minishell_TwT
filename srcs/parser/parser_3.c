/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/08 22:13:45 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	check_heredoc(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	cmd->heredoc_file = NULL;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->str[i])
		{
			if (ft_strncmp(tmp->str[i], "<<", 2) == 0)
				cmd->heredoc_file = ft_strdup(tmp->str[i - 1]);
			i++;
		}
		tmp = tmp->next;
	}
}
