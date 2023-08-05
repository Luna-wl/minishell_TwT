#include "hell.h"

void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, t_cmd *tmp, int id);
void	parent_process(t_main *main, t_cmd *tmp, int id);
void	waiting_process(t_main *main);
int		check_redirect(char *s);
void	ft_close_pipe(t_main *main, int pfd);
void	builtin_parent_process(t_main *main, t_cmd *tmp, int id);
void	get_command(t_main *main, t_cmd *tmp);
void	free_command(char	**command);
void	get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);

void	start_process(t_main *main)
{
	main->cmd_nbr = main->num_pipe + 1;
	// main->found_path = find_path(main->envp);
	// if (main->found_path != -1)
	// 	main->path = ft_split(&main->envp[main->found_path][5], ':');

	// count_cmd(p, argv[1]);
	main->pid = malloc(sizeof(pid_t) * main->cmd_nbr);
	// if (p->heredoc == 1)
	get_heredoc(main);
		// get_command(main, main->cmd);
	create_process(main);
	// close(main->pfd[0]);
	// close(main->pfd[1]);
	waiting_process(main);
	free(main->pid);
	// free_path(p);
}

void	create_process(t_main *main)
{
	t_cmd *tmp;
	int	id;

	id = -1;
	tmp = main->cmd;
	while (++id < main->cmd_nbr)
	{
		get_command(main, tmp);
		if (id != main->cmd_nbr - 1)
		{
			if (pipe(main->pfd) == -1)
				err_msg_free(main, "Pipe error: ");
		}
		// if (check_builtin(tmp) != 2)
		// {
			main->pid[id] = fork();
			if (main->pid[id] == -1)
				err_msg_free(main, "Fork error: ");
			else if (main->pid[id] == 0)
				child_process(main, tmp, id);
				// printf("child process = %d, id = %d\n", main->pid[id], id);
			else
				parent_process(main, tmp, id);
		// }
		// else
		// {
		// 	printf("hiii\n");
		// 	builtin_parent_process(main, tmp, id);
		// }
		free_command(tmp->command);
		tmp = tmp->next;
	}
}

void	free_command(char	**command)
{
	int	i;

	i = -1;
	if(!command)
		return ;
	while(command[++i])
		free(command[i]);
	free(command);

}

void	ft_close_pipe(t_main *main, int pfd)
{
	if (main->num_pipe > 0)
		close(pfd);
}

void	child_process(t_main *main, t_cmd *tmp, int id)
{
	if (check_builtin(tmp) == 2)
	{
		ft_close_pipe(main, main->pfd[0]);
		ft_close_pipe(main, main->pfd[1]);
		exit(0);
		return ;
	}
	dup_infile(main, tmp, id);
	dup_outfile(main, tmp, id);
	ft_close_pipe(main, main->pfd[0]);
	ft_close_pipe(main, main->pfd[1]);
	// get_command(main, tmp);
	if (check_builtin(tmp) == 1)
	{
		into_builtin_child(main, tmp);
		exit(0);
	}
	else if (check_access_path(main, tmp->command[0]) == 0)
	{
		if (execve(main->cur_path, tmp->command, main->envp) == -1)
		{
			free(main->cur_path);
			err_cmd(main, tmp->command[0], 13);
		}
	}
}

// void	builtin_child_process(t_main *main, t_cmd *tmp, int id)
// {

// }

void	builtin_parent_process(t_main *main, t_cmd *tmp, int id)
{
	(void) id;
	// dup_infile(main, tmp, id);
	// dup_outfile(main, tmp, id);
	// ft_close_pipe(main, main->pfd[1]);
	// if (main->num_pipe > 0)
	// 	main->tmp_fd = dup(main->pfd[0]);
	// ft_close_pipe(main, main->pfd[0]);
	if (into_builtin_parent(main, tmp))
		err_builtin(main, tmp);
		// err_msg_free(main, "builtin error sth");
}

void	parent_process(t_main *main, t_cmd *tmp, int id)
{
		ft_close_pipe(main, main->pfd[1]);
		if (main->num_pipe > 0)
			main->tmp_fd = dup(main->pfd[0]);
		ft_close_pipe(main, main->pfd[0]);
	if (check_builtin(tmp) == 2)
		builtin_parent_process(main, tmp, id);
}

void	waiting_process(t_main *main)
{
	int	id;

	id = -1;
	while (++id < main->cmd_nbr)
		waitpid(main->pid[id], &main->status, WUNTRACED);
}

void	get_command(t_main *main, t_cmd *tmp)
{
	int		i;
	int		cnt_word;
	i = -1;
	(void) main;

	cnt_word = 0;
	while (tmp->str[++i])
	{
		// printf("tmp->str[%d] = %s\n", i, tmp->str[i]);
		cnt_word++;
	}
	cnt_word -= (main->cmd->all_infile + main->cmd->all_outfile) * 2;
	tmp->command = malloc(sizeof(char *) * (cnt_word + 1));
	if (!tmp->command)
		return ;
	tmp->command[cnt_word] = NULL;
	i = -1;
	cnt_word = 0;
	while (tmp->str[++i])
	{
		if (check_redirect(tmp->str[i]))
		{
			if (i == 0 || (i != 0 && check_redirect(tmp->str[i - 1])))
				get_letter_cmd(tmp, tmp->str[i], cnt_word++);
		}
		else
			i ++;
	}
}

void get_letter_cmd(t_cmd *tmp, char *s, int cnt_word)
{
	int	i;

	tmp->command[cnt_word] = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp->command[cnt_word])
		return ;
	i = -1;
	while (s[++i])
		tmp->command[cnt_word][i] = s[i];
	tmp->command[cnt_word][i] = '\0';
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

