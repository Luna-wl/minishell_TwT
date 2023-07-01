/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/07/02 03:04:49 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
// #include "../gnl/get_next_line.h"

void	get_heredoc(t_cmd	*command);
int		read_heredoc(t_cmd	*tmp, size_t len_filename, int i);
int		check_limiter(char *line, char *limiter, size_t n);

void	get_heredoc(t_cmd	*command)
{
	t_cmd	*tmp;
	size_t	len_filename;
	int		i;

	tmp = command;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < tmp->cnt_heredoc)
		{
			// printf("i = %d, cnt_heredic =- %d\n", i, tmp->cnt_heredoc);
			// printf("tmp->heredoc_file[%d] = %s\n", i, tmp->heredoc_file[i]);
			len_filename = ft_strlen(tmp->heredoc_file[i]);
			close(read_heredoc(tmp, len_filename, i));
		}
		tmp = tmp->next;
	}
}

int	read_heredoc(t_cmd	*tmp, size_t len_filename, int i)
{
	char	*line;
	int		fd_heredoc;
	size_t	len;

	fd_heredoc = open(tmp->heredoc_file[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (fd_heredoc == -1)
	// 	err_file(tmp, tmp->heredoc_file[i]);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line && check_limiter(line, tmp->heredoc_file[i], len_filename) == 1)
	{
		len = ft_strlen(line);
		write(fd_heredoc, line, len);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	return (fd_heredoc);
}

int	check_limiter(char *line, char *limiter, size_t n)
{
	unsigned int	index;

	index = 0;
	while (index < n && (line[index] != 0 || limiter[index] != 0))
	{
		if (line[index] != limiter[index])
			return (1);
		index++;
	}
	if (line[index] != '\n')
		return (1);
	return (0);
}
