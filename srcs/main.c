/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/12 16:43:52 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	init_mimi(t_main *main)
{
	main->lexer = NULL;
	main->cmd = NULL;
	main->num_pipe = 0;
	environ = get_envp();
	main->envp = get_envp2();
	main->path = get_path(main->envp);
}

int	main(int argc, char **argv)
{
	char		*str;
	t_main		main;

	(void)argv;
	if (argc > 1)
		print_str(YEL"You put the wrong input\n"RESET);
	printf(YEL"====> ~ HELLO WELCOME ~ <====\n"RESET);
	while (1)
	{
		// init_signal();
		str = readline(RED"mini(s)hell >> "RESET);
		add_history(str);
		if (!str)
		{
			printf(BCYN"========= ~Bye Bye~ =========\n"RESET);
			break ;
		}
		init_mimi(&main);
		get_cmd(&main, str);
		// expander(&main);
		// start_process(&main);
		// into_builtin(&main);
		free(str);
		// free_all(&main);
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


/*
echo with option -n.
cd with only a relative or absolute path.
pwd (no flags).
export (no flags).
unset (no flags).
env (no flags or arguments).
exit (no flags).
*/