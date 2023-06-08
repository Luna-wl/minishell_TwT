/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:27 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 23:15:08 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_find_slash(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '/')
			return (0);
	}
	return (-1);
}

void	count_cmd(t_main *main)
{
	// if (main->argc >= 6 && !ft_strncmp(filename, "here_doc", 9))
	// {
	// 	main->heredoc = 1;
	// 	main->cmd_nbr = main->argc - 4;
	// }
	// else
	// 	main->cmd_nbr = main->argc - 3;
	// main->cur = main->argc - (main->cmd_nbr + 1);
}
