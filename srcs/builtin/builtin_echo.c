/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:45:01 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/29 17:15:29 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	builtin_echo(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		opt;
	int		i;

	i = 0;
	opt = 0;
	tmp = cmd;
	while (tmp->str[i])
	{
		if (ft_strncmp(tmp->str[i], "echo", 4) == 0)
			i++;
		if (ft_strncmp(tmp->str[i], "-n", 2) == 0)
		{
			opt = 1;
			i++;
		}
		else
		{
			print_word(tmp->str[i]);
			if (tmp->str[i + 1] && tmp->str[i][0] != '\0' )
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (opt == 0)
		ft_putchar_fd('\n', 1);
}
