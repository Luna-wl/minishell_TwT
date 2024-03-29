/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/02 23:36:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	init_mimi(t_main *main)
{
	main->lexer = NULL;
	main->cmd = NULL;
	main->num_pipe = 0;
	environ = get_envp(); // make extern environ to malloc
	main->envp = get_envp2(); // word that before '=' in env to check sth. as USER PWD
	main->path = get_path(main->envp); // value after that spilt with ':' PATH=
}

int	main(int argc, char **argv)
{
	char		*str;
	t_main		main;

	(void)argv;
	(void)argc;
	if (argc > 1)
		print_str(YEL"You put the wrong input\n"RESET);
	printf(YEL"====> ~ HELLO WELCOME ~ <====\n"RESET); // welcome message
	while (1) // loop till want to exit
	{
		init_signal(); // catch signal
		sigint_handle(1);
		str = readline(RED"mini(s)hell >> "RESET); // รับinputเข้ามา
		add_history(str); // ใส่ในhistory
		if (!str) // detact for ctrl-D if it NULL break
		{
			printf(BCYN"========= ~Bye Bye~ =========\n"RESET);
			break ;
		}
		init_mimi(&main); // init value in struct
		if(get_cmd(&main, str)) // start cut cmd
		{
			// expander(&main); // after split cmd then go to expander to detact quote and $
			// sigint_handle(2);
			// start_process(&main);
		}
		free(str); // free input
		// reset_tool(&main);
	}
	rl_clear_history();
	// free_all(&main); // free everything after finish execue cmd or reset everything to start again
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
