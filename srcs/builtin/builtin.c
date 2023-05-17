/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:13:32 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/08 15:09:02 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	into_builtin2(t_cmd *cmd, int i, char **envp)
{
	if (ft_strncmp(cmd->str[i], "echo", 4) == 0)
		builtin_echo(cmd);
	// else if (ft_strncmp(cmd->str[i], "cd", 2) == 0)
	// 	builtin_cd(cmd);
	else if (ft_strncmp(cmd->str[i], "pwd", 3) == 0)
		builtin_pwd(cmd);
	// else if (ft_strncmp(cmd->str[i], "export", 6) == 0)
	// 	builtin_export(cmd);
	// else if (ft_strncmp(cmd->str[i], "unset", 5) == 0)
	// 	builtin_unset(cmd);
	else if (ft_strncmp(cmd->str[i], "env", 3) == 0)
		builtin_env(envp);
	// else if (ft_strncmp(cmd->str[i], "exit", 4) == 0)
	// 	builtin_exit(cmd);
}

void	into_builtin(t_main *main)
{
	t_cmd	*tmp;
	int		j;

	tmp = main->cmd;
	while (tmp != NULL)
	{
		j = 0;
		while (tmp->str[j])
		{
			into_builtin2(tmp, j, main->env);
			j++;
		}
		tmp = tmp->next;
	}
}
