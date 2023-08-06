/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:27:29 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 02:49:29 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, t_cmd *tmp, int id);
void	parent_process(t_main *main, t_cmd *tmp);
void	waiting_process(t_main *main);

void	start_process(t_main *main)
{
	main->cmd_nbr = main->num_pipe + 1;
	main->pid = malloc(sizeof(pid_t) * main->cmd_nbr);
	get_heredoc(main);
	create_process(main);
	waiting_process(main);
	free(main->pid);
}

void	create_process(t_main *main)
{
	t_cmd	*tmp;
	int		id;

	id = -1;
	tmp = main->cmd;
	while (++id < main->cmd_nbr)
	{
		get_command(main, tmp);
		if (id != main->cmd_nbr - 1)
		{
			if (pipe(main->pfd) == -1)
				return (err_msg("Pipe error: "));
		}
		main->do_cmd = check_builtin(tmp);
		main->pid[id] = fork();
		if (main->pid[id] == -1)
			return (err_msg("Fork error: "));
		else if (main->pid[id] == 0)
			child_process(main, tmp, id);
		else
			parent_process(main, tmp);
		free_2d(tmp->command);
		tmp = tmp->next;
	}
}

void	child_process(t_main *main, t_cmd *tmp, int id)
{
	if (main->do_cmd == 2)
	{
		ft_close_pipe(main, main->pfd[0]);
		ft_close_pipe(main, main->pfd[1]);
		free_2d(tmp->command);
		exit(main->exit_status);
	}
	dup_infile(main, tmp, id);
	dup_outfile(main, tmp, id);
	ft_close_pipe(main, main->pfd[0]);
	ft_close_pipe(main, main->pfd[1]);
	if (main->do_cmd == 1)
		exit(into_builtin_child(main, tmp));
	else if (check_access_path(main, tmp, tmp->command[0]) == 0)
	{
		if (execve(main->cur_path, tmp->command, main->envp) == -1)
		{
			free(main->cur_path);
			free_2d(tmp->command);
			err_cmd(main, tmp, tmp->command[0], 13);
		}
	}
}

void	parent_process(t_main *main, t_cmd *tmp)
{
	main->exit_status = 0;
	ft_close_pipe(main, main->pfd[1]);
	if (main->num_pipe > 0)
		main->tmp_fd = dup(main->pfd[0]);
	ft_close_pipe(main, main->pfd[0]);
	if (main->do_cmd == 2)
		main->exit_status = builtin_parent_process(main, tmp);
}

void	waiting_process(t_main *main)
{
	int	id;

	id = -1;
	while (++id < main->cmd_nbr)
	{
		waitpid(main->pid[id], &main->status, WUNTRACED);
		if (!main->do_cmd && WIFEXITED(main->status))
			main->exit_status = WEXITSTATUS(main->status);
	}
}
