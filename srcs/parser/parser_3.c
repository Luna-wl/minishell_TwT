/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/25 14:24:34 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_redirect(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (j < 4)
		{
			if (ft_strncmp(s, "<", 1) == 0)
				return (1);
			else if (ft_strncmp(s, "<<", 2) == 0)
				return (2);
			else if (ft_strncmp(s, ">", 1) == 0)
				return (3);
			else if (ft_strncmp(s, ">>", 2) == 0)
				return (4);
			j++;
		}
		i++;
	}
	return (-1);
}

void	add_fd_redi(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->str[i])
		{
			if (check_redirect(tmp->str[i]) == 1)
				cmd->num_redirect = 0;
			else if (check_redirect(tmp->str[i]) == 2)
				cmd->num_redirect = -2;
			else if (check_redirect(tmp->str[i]) == 3)
				cmd->num_redirect = 1;
			else if (check_redirect(tmp->str[i]) == 4)
				cmd->num_redirect = -3;
			else
				cmd->num_redirect = -1;
		}
		tmp = tmp->next;
	}
}
