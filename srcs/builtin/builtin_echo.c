/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:45:01 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 18:42:00 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		builtin_echo(t_cmd *tmp);
void	print_word(char *str);
void	do_echo(t_cmd *tmp, int i, int opt);
void	print_sorted_env(void);

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

int	builtin_echo(t_cmd *tmp)
{
	int		opt;
	int		i;
	int		j;

	i = 1;
	opt = 0;
	if (ft_strncmp(tmp->command[i], "-n", 2) == 0)
	{
		opt = 1;
		j = 0;
		while (tmp->command[i][++j])
		{
			if (tmp->command[i][j] != 'n')
				opt = 0;
		}
	}
	if (opt == 1)
		i++;
	do_echo(tmp, i, opt);
	exit(0);
	return (0);
}

void	do_echo(t_cmd *tmp, int i, int opt)
{
	while (tmp->command[i])
	{
		print_word(tmp->command[i]);
		if (tmp->command[i + 1] && tmp->command[i][0] != '\0' )
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (opt == 0 || !tmp->command[1])
		ft_putchar_fd('\n', 1);
}

void	print_sorted_env(void)
{
	int		i;
	char	**str;

	str = ft_strdup_env();
	sort_env(str);
	i = -1;
	while (str[++i])
		printf("declare -x %s\n", str[i]);
	if (str)
		free_2d(str);
}
