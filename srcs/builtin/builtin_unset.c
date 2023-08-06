/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:31:03 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 18:31:07 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		builtin_unset(t_cmd *cmd);
char	**delete_variable(int line);

int	builtin_unset(t_cmd *cmd)
{
	int	row_vrb;
	int	i;

	i = 0;
	while (cmd->command[++i])
	{
		if (check_format_variable(cmd->command[i]))
		{
			row_vrb = find_variable_inenv(cmd->command[i]);
			if (row_vrb != -1)
			{
				environ = delete_variable(row_vrb);
			}
		}
		else
			err_msg_builtin("unset", cmd->command[i]);
	}
	return (0);
}

char	**delete_variable(int line)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * i);
	i = -1;
	j = -1;
	while (environ[++i])
	{
		if (i != line)
		{
			new[j] = ft_strdup(environ[i]);
			j++;
		}
	}
	new[j] = NULL;
	free(environ);
	return (new);
}
