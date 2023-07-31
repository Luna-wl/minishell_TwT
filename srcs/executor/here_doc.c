/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/07/03 03:21:34 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
// #include "../gnl/get_next_line.h"

void	get_heredoc(t_main	*main);
void	read_heredoc(t_main *main, t_cmd *tmp, size_t len_filename, int i);
int		check_limiter(char *line, char *limiter, size_t n);
int		check_append_file(t_cmd *tmp, char *file_name);
int		check_heredoc_file(t_cmd *tmp, char *file_name);

void	get_heredoc(t_main *main)
{
	t_cmd	*tmp;
	size_t	len_filename;
	int		i;

	tmp = main->cmd;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < tmp->cnt_heredoc)
		{
			// printf("i = %d, cnt_heredic =- %d\n", i, tmp->cnt_heredoc);
			// printf("tmp->heredoc_file[%d] = %s\n", i, tmp->heredoc_file[i]);
			len_filename = ft_strlen(tmp->heredoc_file[i]);
			read_heredoc(main, tmp, len_filename, i);
		}
		tmp = tmp->next;
	}
}

void	read_heredoc(t_main *main, t_cmd *tmp, size_t len_filename, int i)
{
	char	*line;
	int		fd_heredoc;
	size_t	len;

	fd_heredoc = open(tmp->heredoc_file[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_heredoc == -1)
		err_file(main, tmp->heredoc_file[i]);
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
	close(fd_heredoc);
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

int	check_heredoc_file(t_cmd *tmp, char *file_name)
{
	int	i;

	i = -1;
	while (++i < tmp->cnt_heredoc)
		if (!ft_strncmp(file_name, tmp->heredoc_file[i], ft_strlen(file_name)))
			return (0);
	return (1);
}

int	check_append_file(t_cmd *tmp, char *file_name)
{
	int	i;

	i = -1;
	while (++i < tmp->cnt_append)
		if (!ft_strncmp(file_name, tmp->append_file[i], ft_strlen(file_name)))
			return (0);
	return (1);
}
