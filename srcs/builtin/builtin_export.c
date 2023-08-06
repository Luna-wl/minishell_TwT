/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:32:04 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 18:32:09 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	do_export(char *cmd, int row_vrb, char *vrb);
int		builtin_export(t_main *main, t_cmd *cmd);
char	*ft_strtrim_vrb(char *cmd, char set);
char	**add_variable(char *cmd);
void	instead_variable(char *cmd, int row_vrb);

void	do_export(char *cmd, int row_vrb, char *vrb)
{
	row_vrb = find_variable_inenv(vrb);
	if (row_vrb != -1)
		instead_variable(cmd, row_vrb);
	else
		environ = add_variable(cmd);
}

int	builtin_export(t_main *main, t_cmd *cmd)
{
	int		i;
	char	*vrb;

	if (!cmd->command[1])
		print_sorted_env();
	else
	{
		i = 0;
		while (cmd->command[++i])
		{
			vrb = ft_strtrim_vrb(cmd->command[i], '=');
			if (vrb && check_format_variable(vrb))
				do_export(cmd->command[i], 0, vrb);
			else
			{
				err_msg_builtin("export", cmd->command[i]);
				main->exit_status = 1;
				return (free(vrb), 1);
			}
			if (vrb)
				free(vrb);
		}
	}
	return (0);
}

char	*ft_strtrim_vrb(char *cmd, char set)
{
	char	*str;
	int		i;
	int		check;

	i = 0;
	check = 0;
	str = NULL;
	while (cmd[i] && cmd[i] != set)
		i++;
	if (i > 0)
		check = 1;
	if (check == 1 && i > 0)
	{
		str = malloc(sizeof(char) * (i + 1));
		i = -1;
		while (cmd[++i] && cmd[i] != set)
			str[i] = cmd[i];
		str[i] = 0;
	}
	return (str);
}

char	**add_variable(char *cmd)
{
	int		i;
	char	**new;

	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (environ[++i])
		new[i] = ft_strdup(environ[i]);
	new[i] = ft_strdup(cmd);
	new[i + 1] = NULL;
	if (environ)
		free_2d(environ);
	return (new);
}

void	instead_variable(char *cmd, int row_vrb)
{
	unsigned int	len;

	len = ft_strlen(cmd) + 1;
	free(environ[row_vrb]);
	environ[row_vrb] = malloc(sizeof(char) * len);
	ft_strlcpy(environ[row_vrb], cmd, len);
}
