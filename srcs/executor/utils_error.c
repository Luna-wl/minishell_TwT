/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:36 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 16:35:35 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	err_file(t_cmd *tmp, char *file);
void	err_cmd(t_main *main, t_cmd *tmp, char *cmd, int err);
int		err_builtin(t_cmd *cmd, int err);
void	err_msg(char *msg);
void	ft_exit(int err);

void	err_file(t_cmd *tmp, char *file)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, file, ft_strlen(file));
	write(STDERR_FILENO, ": ", 3);
	perror("");
	free_2d(tmp->command);
	exit(EXIT_FAILURE);
}

void	err_cmd(t_main *main, t_cmd *tmp, char *cmd, int err)
{
	(void) main;
	write(STDERR_FILENO, "minishell: ", 11);
	if (cmd)
		write(STDERR_FILENO, cmd, ft_strlen(cmd));
	if (ft_find_slash(cmd) == 0 && err == 9)
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	else if (err == 2)
		write(STDERR_FILENO, ": command not found\n", 20);
	else if (err == 13)
		write(STDERR_FILENO, ": Permission denied\n", 20);
	free_2d(tmp->command);
	ft_exit(err);
}

int	err_builtin(t_cmd *cmd, int err)
{
	if (err == 1)
		return (err);
	write(STDERR_FILENO, "minishell: ", 11);
	if (cmd->command[0])
		write(STDERR_FILENO, cmd->command[0], ft_strlen(cmd->command[0]));
	if (cmd->command[1])
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd->command[1], ft_strlen(cmd->command[1]));
	}
	if (err == 127)
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	return (err);
}

void	err_msg(char *msg)
{
	perror(msg);
	write(STDERR_FILENO, "\n", 1);
}

void	ft_exit(int err)
{
	if (err == 13)
		exit(126);
	else if (err == 2 || err == 9)
		exit(127);
	else
		exit(EXIT_FAILURE);
}
