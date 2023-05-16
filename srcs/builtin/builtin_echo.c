/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:45:01 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/03 14:31:40 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		write(1, &str[i], 1);
		i++;
	}
}

void	builtin_echo(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		opt;

	g_i.i = 0;
	opt = 0;
	tmp = cmd;
	while (tmp->str[g_i.i])
	{
		if (ft_strncmp(tmp->str[g_i.i], "echo", 4) == 0)
			g_i.i++;
		if (ft_strncmp(tmp->str[g_i.i], "-n", 2) == 0)
		{
			opt = 1;
			g_i.i++;
		}
		else
		{
			print_word(tmp->str[g_i.i]);
			if (tmp->str[g_i.i + 1] && tmp->str[g_i.i][0] != '\0' )
				ft_putchar_fd(' ', 1);
			g_i.i++;
		}
	}
	if (opt == 0)
		ft_putchar_fd('\n', 1);
}
