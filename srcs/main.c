/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/17 13:39:47 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	init_mimi(t_main *main)
{
	main->lexer = NULL;
	main->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_main		main;

	(void)argv;
	if (argc > 1)
		print_str(YEL"You put the wrong input\n"RESET);
	printf(YEL"====> ~ HELLO WELCOME ~ <====\n"RESET);
	while (1)
	{
		init_signal();
		str = readline(RED"mini(s)hell >> "RESET);
		add_history(str);
		if (!str)
		{
			printf(BCYN"========= ~Bye Bye~ =========\n"RESET);
			break ;
		}
		init_mimi(&main);
		copy_info(&main, str, envp);
		get_cmd(&main);
		expander(&main);
		free(str);
	}
	return (0);
}

// # echo hello world|echo hello| echo ". hello "|ls| echo "'hello'"""
// -> Parser Sent to expander
// # {echo}, {hello}, {world}, NULL,
// # {echo}, {hello}, NULL,
// # {echo}, {". hello "}, NULL,
// # {ls}, NULL,
// # {echo}, {"'hello'"}, {""}, NULL.
// if '' / "" not complete pair ret"urn ERROR in lexer.

//fd inout of redirect