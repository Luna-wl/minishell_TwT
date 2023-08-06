/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:49:38 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 02:10:34 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	open_infile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	open_outfile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	dup_infile(t_main *main, t_cmd *tmp, int id);
void	dup_outfile(t_main *main, t_cmd *tmp, int id);

void	open_infile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr)
{
	int	i;

	i = -1;
	while (++i < file_nbr && file_name[i])
	{
		main->fd_file = open(file_name[i], O_RDONLY);
		if (main->fd_file == -1)
			err_file(tmp, file_name[i]);
		if (i != file_nbr - 1)
		{
			close(main->fd_file);
			if (!check_heredoc_file(tmp, file_name[i]) \
			&& ft_strncmp(file_name[i], file_name[file_nbr - 1], \
			ft_strlen(file_name[i])))
				unlink(file_name[i]);
		}
	}
}

void	open_outfile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr)
{
	int	i;

	i = -1;
	while (++i < file_nbr && file_name[i])
	{
		if (!check_append_file(tmp, file_name[i]))
			main->fd_file = open(file_name[i], O_WRONLY \
			| O_CREAT | O_APPEND, 0644);
		else
			main->fd_file = open(file_name[i], O_WRONLY \
			| O_CREAT | O_TRUNC, 0644);
		if (main->fd_file == -1)
			err_file(tmp, file_name[i]);
		if (i != file_nbr - 1)
			close(main->fd_file);
		else
			dup2(main->pfd[1], STDOUT_FILENO);
	}
}

void	dup_outfile(t_main *main, t_cmd *tmp, int id)
{
	if (tmp->all_outfile)
	{
		open_outfile(main, tmp, tmp->outfile_name, tmp->all_outfile);
		dup2(main->fd_file, STDOUT_FILENO);
		close(main->fd_file);
	}
	else if (id != main->cmd_nbr - 1 && main->num_pipe > 0)
		dup2(main->pfd[1], STDOUT_FILENO);
}

void	dup_infile(t_main *main, t_cmd *tmp, int id)
{
	if (tmp->all_infile)
	{
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
