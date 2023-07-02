/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:49:38 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/07/03 03:39:44 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

// void	ft_dup2(t_main *main, t_cmd *tmp, int id);
// void	dup_first_child(t_main *main, t_cmd *tmp);
// void	dup_last_child(t_main *main, t_cmd *tmp);
void	open_infile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	open_outfile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	dup_infile(t_main *main, t_cmd *tmp, int id);
void	dup_outfile(t_main *main, t_cmd *tmp, int id);

// void	ft_dup2(t_main *main, t_cmd *tmp, int id)
// {
// 	if (id == 0)
// 		dup_first_child(main, tmp);
// 	else if (id > 0 && id < main->cmd_nbr - 1)
// 	{
// 		dup2(main->tmp_fd, STDIN_FILENO);
// 		dup2(main->pfd[1], STDOUT_FILENO);
// 	}
// 	else if (id == main->cmd_nbr - 1)
// 		dup_last_child(main, tmp);
// }

void	open_infile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr)
{
	int	i;

	i = -1;
	dprintf(2, "file_nbr %d = %s\n", file_nbr, file_name[0]);
	while (++i < file_nbr && file_name[i])
	{
		dprintf(2, "infile %d = %s\n", i, file_name[i]);
		main->fd_file = open(file_name[i], O_RDONLY);
		if (main->fd_file == -1)
			err_file(main, file_name[i]);
		if (i != file_nbr - 1)
		{
			dprintf(2, "not the last infile %d = %s\n", i, file_name[i]);
			close(main->fd_file);
			if (!check_heredoc_file(tmp, file_name[i]))
				unlink(file_name[i]);
		}
		// else
		// 	dup2(main->fd_file, STDIN_FILENO);
	}
}

void	open_outfile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr)
{
	int	i;

	i = -1;
	while (++i < file_nbr && file_name[i])
	{
		if (!check_append_file(tmp, file_name[i]))
		{
			dprintf(2, "app_outfile %d = %s\n", i, file_name[i]);
			main->fd_file = open(file_name[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else
		{
			dprintf(2, "truc_outfile %d = %s\n", i, file_name[i]);
			main->fd_file = open(file_name[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		if (main->fd_file == -1)
			err_file(main, file_name[i]);
		if (i != file_nbr - 1)
			close(main->fd_file);
		else
			dup2(main->pfd[1], STDOUT_FILENO);
	}
}

// void	dup_first_child(t_main *main, t_cmd *tmp)
// {
// 	if (tmp->all_infile)
// 		open_infile(main, tmp, tmp->infile_name, tmp->all_infile);
// 	// dup2(main->fd_file, STDIN_FILENO);
// 	// p->fd_file = open(infile, O_RDONLY);
// 	if (!tmp->all_outfile)
// 		dup2(main->pfd[1], STDOUT_FILENO);
// 	else
// 		open_outfile(main, tmp, tmp->outfile_name, tmp->all_outfile);

// 	close(main->fd_file);
// 	if (!check_heredoc_file(tmp, tmp->infile_name[tmp->all_infile - 1]))
// 		unlink(tmp->infile_name[tmp->all_infile - 1]);
// }

// void	dup_last_child(t_main *main, t_cmd *tmp)
// {
// 	open_infile(main, tmp, tmp->infile_name, tmp->all_infile);
// 	if (tmp->all_infile)
// 		dup2(main->fd_file, STDIN_FILENO);
// 	else
// 		dup2(main->tmp_fd, STDIN_FILENO);
// 	open_outfile(main, tmp, tmp->outfile_name, tmp->all_outfile);
// 	if (tmp->all_outfile)
// 		dup2(main->fd_file, STDOUT_FILENO);
// 	else if (id != main->cmd_nbr - 1)
// 		dup2(main->pfd[1], STDOUT_FILENO);
// 	// if (p->heredoc == 1)
// 	// 	p->fd_file = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	// else
// 	// 	p->fd_file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	// if (main->fd_file == -1)
// 	// 	err_file(main, outfile);
// 	if (id != 0)
// 		dup2(main->tmp_fd, STDIN_FILENO);
// 	dup2(main->fd_file, STDOUT_FILENO);
// }

void	dup_outfile(t_main *main, t_cmd *tmp, int id)
{
	if (tmp->all_outfile)
	{
		dprintf(2, "all_outfile = %d\n", tmp->all_infile);
		open_outfile(main, tmp, tmp->outfile_name, tmp->all_outfile);
		dup2(main->fd_file, STDOUT_FILENO);
		close(main->fd_file);
	}
	else if (id != main->cmd_nbr - 1 || main->num_pipe > 0)
	{
		dup2(main->pfd[1], STDOUT_FILENO);
		// close(main->pfd[1]);
	}
}

void	dup_infile(t_main *main, t_cmd *tmp, int id)
{
	if (tmp->all_infile)
	{
		dprintf(2, "all_infile = %d -> %s\n", tmp->all_infile, tmp->heredoc_file[0]);
		open_infile(main, tmp, tmp->infile_name, tmp->all_infile);
		dup2(main->fd_file, STDIN_FILENO);
		close(main->fd_file);
		if (!check_heredoc_file(tmp, tmp->infile_name[tmp->all_infile - 1]))
			unlink(tmp->infile_name[tmp->all_infile - 1]);
	}
	else if (id != 0)
	{
		dup2(main->tmp_fd, STDIN_FILENO);
	}
}
