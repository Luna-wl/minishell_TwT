/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:22 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/08 21:42:48 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

	// init_value(&p, argc);
	// start_process(&p, argv, env);
	// return (WEXITSTATUS(p.status));

void	start_process(t_main *main)
{
	main->found_path = find_path();
	if (main->found_path != -1)
		main->path = ft_split(&environ[main->found_path][5], ':');
	// count_cmd(main);
	main->pid = malloc(sizeof(pid_t) * main->cmd_nbr);
	// if (main->heredoc == 1)
	// 	read_heredoc(main);
	create_process(main);
	// close(main->pfd[0]);
	// close(main->pfd[1]);
	// waiting_process(main);
	// free_path(main);
}

void	create_process(t_main *main)
{
	int	id;

	id = 0;
	while (main->cur < (main->argc - 1) && id < main->cmd_nbr)
	{
		if (id != main->cmd_nbr - 1)
		{
			if (pipe(main->pfd) == -1)
				err_msg_free(main, "Pipe error: ");
		}
		main->pid[id] = fork();
		if (main->pid[id] == -1)
			err_msg_free(main, "Fork error: ");
		else if (main->pid[id] == 0)
			child_process(main, id);
		else
			parent_process(main);
		id++;
		main->cur++;
	}
}

void	child_process(t_main *main, int id)
{
	close(main->pfd[0]);
	ft_dup2(main, argv, id);
	close(main->pfd[1]);
	main->cmd = ft_split(argv[main->cur], ' ');
	if (check_access_path(main, main->cmd[0]) == 0)
	{
		if (execve(main->cur_path, main->cmd, environ) == -1)
		{
			free(main->cur_path);
			err_cmd(main, main->cmd[0], 13);
		}
	}
}

void	parent_process(t_main *main)
{
	close(main->pfd[1]);
	main->tmp_fd = dup(main->pfd[0]);
	close(main->pfd[0]);
}

void	waiting_process(t_main *main)
{
	int	id;

	id = -1;
	while (++id < main->cmd_nbr)
		waitpid(main->pid[id], &main->status, WUNTRACED);
}
