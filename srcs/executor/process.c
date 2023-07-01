#include "hell.h"

void	start_process(t_main *main);
// void	create_process(t_main *main, char **argv, char **env);
// void	child_process(t_main *main, char **argv, char **env, int id);
// void	parent_process(t_main *main);
// void	waiting_process(t_main *main);
int	check_redirect(char *s);
void	get_command(t_main *main, t_cmd *tmp);

void get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);

void	start_process(t_main *main)
{
	main->cmd_nbr = main->num_pipe + 1;
	// main->found_path = find_path(main->envp);
	// if (main->found_path != -1)
	// 	main->path = ft_split(&main->envp[main->found_path][5], ':');

	// count_cmd(p, argv[1]);
	// main->pid = malloc(sizeof(pid_t) * main->cmd_nbr);
	// if (p->heredoc == 1)
		get_heredoc(main->cmd);
		get_command(main, main->cmd);
	// create_process(main);
	// close(p->pfd[0]);
	// close(p->pfd[1]);
	// waiting_process(p);
	// free_path(p);
}

// void	create_process(t_main *main, char **argv, char **env)
// {
// 	tmd *tmp;
// 	int	id;

// 	id = 0;
// 	tmp = main->cmd;
// 	while (id < main->cmd_nbr)
// 	{
// 		if (id != p->cmd_nbr - 1)
// 		{
// 			if (pipe(p->pfd) == -1)
// 				err_msg_free(p, "Pipe error: ");
// 		}
// 		main->pid[id] = fork();
// 		if (main->pid[id] == -1)
// 			err_msg_free(main, "Fork error: ");
// 		else if (main->pid[id] == 0)
// 			child_process(main, id, tmp);
// 		else
// 			parent_process(main);
// 		id++;
// 		tmp = tmp->next;
// 	}
// }

// void	child_process(t_main *main, int id, t_cmd *tmp)
// {
// 	close(main->pfd[0]);
// 	ft_dup2(main, id);
// 	close(main->pfd[1]);
// 	get_command(main, tmp);
// 	// p->cmd = ft_split(argv[p->cur], ' ');
// 	if (check_access_path(p, p->cmd[0]) == 0)
// 	{
// 		if (execve(p->cur_path, p->cmd, env) == -1)
// 		{
// 			free(p->cur_path);
// 			err_cmd(p, p->cmd[0], 13);
// 		}
// 	}
// }

// void	parent_process(t_main *main)
// {
// 	close(p->pfd[1]);
// 	p->tmp_fd = dup(p->pfd[0]);
// 	close(p->pfd[0]);
// }

// void	waiting_process(t_main *main)
// {
// 	int	id;

// 	id = -1;
// 	while (++id < p->cmd_nbr)
// 		waitpid(p->pid[id], &p->status, WUNTRACED);
// }

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
	printf("af w %d\n", cnt_word);
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
		// printf("re = %d, str = %s, cnt_word = %d, i = %d\n",check_redirect(tmp->str[i]), tmp->command[cnt_word], cnt_word, i);
	}
	i = -1;
	while(tmp->command[++i])
		printf("cmd[%d] = %s\n", i, tmp->command[i]);
}

void get_letter_cmd(t_cmd *tmp, char *s, int cnt_word)
{
	int	i;

	printf("cmd = %s\n", s);
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

