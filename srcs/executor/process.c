#include "hell.h"

void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, t_cmd *tmp, int id);
void	parent_process(t_main *main);
void	waiting_process(t_main *main);
int		check_redirect(char *s);
void	ft_close_pipe(t_main *main, int pfd);

void	get_command(t_main *main, t_cmd *tmp);

void get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);

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
		if (id != main->cmd_nbr - 1)
		{
			if (pipe(main->pfd) == -1)
				err_msg_free(main, "Pipe error: ");
		}
		main->pid[id] = fork();
		if (main->pid[id] == -1)
			err_msg_free(main, "Fork error: ");
		else if (main->pid[id] == 0)
			child_process(main, tmp, id);
			// printf("child process = %d, id = %d\n", main->pid[id], id);
		else
			parent_process(main);
			// printf("parent process = %d, id = %d\n", main->pid[id], id);
		// id++;
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
	ft_close_pipe(main, main->pfd[0]);
	dup_infile(main, tmp, id);
	dup_outfile(main, tmp, id);
	ft_close_pipe(main, main->pfd[1]);
	get_command(main, tmp);
	if (check_access_path(main, tmp->command[0]) == 0)
	{
		if (execve(main->cur_path, tmp->command, main->envp) == -1)
		{
			free(main->cur_path);
			err_cmd(main, tmp->command[0], 13);
		}
	}
}

void	parent_process(t_main *main)
{
	ft_close_pipe(main, main->pfd[1]);
	if (main->num_pipe > 0)
		main->tmp_fd = dup(main->pfd[0]);
	ft_close_pipe(main, main->pfd[0]);
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
		 cnt_word++;
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

