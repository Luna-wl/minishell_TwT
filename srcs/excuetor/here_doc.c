/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/08 21:41:10 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	read_heredoc(t_main *main)
{
	char	*line;
	int		fd_heredoc;
	size_t	len;
	size_t	l;

	l = ft_strlen(argv[2]);
	fd_heredoc = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_heredoc == -1)
		err_file(main, argv[1]);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line && check_limiter(line, argv[2], l) == 1)
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
