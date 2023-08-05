#include "hell.h"

void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, t_cmd *tmp, int id);
void	parent_process(t_main *main, t_cmd *tmp);
void	waiting_process(t_main *main);
int		check_redirect(char *s);
void	ft_close_pipe(t_main *main, int pfd);
int		builtin_parent_process(t_main *main, t_cmd *tmp);


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
				return (err_msg_free(main, "Pipe error: "));
		}
		main->do_cmd = 0;
		if (check_builtin(tmp) == 2)
			main->do_cmd = 1;
		main->pid[id] = fork();
		if (main->pid[id] == -1)
			err_msg_free(main, "Fork error: ");
		else if (main->pid[id] == 0)
			child_process(main, tmp, id);
		else
			parent_process(main, tmp);
		free_2d(tmp->command);
		tmp = tmp->next;
	}
}

void	ft_close_pipe(t_main *main, int pfd)
{
	if (main->num_pipe > 0)
		close(pfd);
}

void	child_process(t_main *main, t_cmd *tmp, int id)
{
	if (main->do_cmd == 1)
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
	if (check_builtin(tmp) == 1)
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

int	builtin_parent_process(t_main *main, t_cmd *tmp)
{
	int		err;

	err = into_builtin_parent(main, tmp);
	if (err)
		err_builtin(main, tmp, err);
	return (err);
}

void	parent_process(t_main *main, t_cmd *tmp)
{
	main->exit_status = 0;
	ft_close_pipe(main, main->pfd[1]);
	if (main->num_pipe > 0)
		main->tmp_fd = dup(main->pfd[0]);
	ft_close_pipe(main, main->pfd[0]);
	if (check_builtin(tmp) == 2)
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


int	check_redirect(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if (!ft_strncmp(s, ">>", len) || !ft_strncmp(s, "<<", len))
		return (0);
	if (!ft_strncmp(s, ">", len) || !ft_strncmp(s, "<", len))
		return (0);
	return (1);
}

