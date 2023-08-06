/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:13:32 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 16:52:02 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		check_builtin(t_cmd *tmp);
int		into_builtin_parent(t_main *main, t_cmd *cmd);
int		into_builtin_child(t_main *main, t_cmd *cmd);
int		builtin_parent_process(t_main *main, t_cmd *tmp);

int	check_builtin(t_cmd *tmp)
{
	if (!ft_strncmp(tmp->command[0], "echo", 5) \
	|| !ft_strncmp(tmp->command[0], "pwd", 4) \
	|| !ft_strncmp(tmp->command[0], "env", 4))
		return (1);
	if (!ft_strncmp(tmp->command[0], "cd", 3) \
	|| !ft_strncmp(tmp->command[0], "unset", 5) \
	|| !ft_strncmp(tmp->command[0], "exit", 4))
		return (2);
	if (!ft_strncmp(tmp->command[0], "export", 6))
	{
		if (!tmp->command[1])
			return (1);
		else
			return (2);
	}
	return (0);
}

int	into_builtin_parent(t_main *main, t_cmd *cmd)
{
	(void) main;
	if (!ft_strncmp(cmd->command[0], "cd", 3))
		return (builtin_cd(cmd));
	else if (!ft_strncmp(cmd->command[0], "export", 7))
		return (builtin_export(main, cmd));
	else if (!ft_strncmp(cmd->command[0], "unset", 6))
		return (builtin_unset(cmd));
	else if (!ft_strncmp(cmd->command[0], "exit", 5))
		return (builtin_exit(main, cmd));
	return (1);
}

int	into_builtin_child(t_main *main, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command[0], "echo", 5))
		return (builtin_echo(cmd));
	else if (!ft_strncmp(cmd->command[0], "pwd", 4))
		return (builtin_pwd(main, cmd));
	else if (!ft_strncmp(cmd->command[0], "env", 4))
		return (builtin_env(cmd));
	else if (!ft_strncmp(cmd->command[0], "export", 7))
		return (builtin_export(main, cmd));
	return (1);
}

int	builtin_parent_process(t_main *main, t_cmd *tmp)
{
	int		err;

	err = into_builtin_parent(main, tmp);
	if (err)
		err_builtin(tmp, err);
	return (err);
}
