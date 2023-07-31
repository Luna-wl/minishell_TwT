/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/10 21:17:22 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	cnt_infile(char **cmd)
{
	int	i;
	int	infile;

	i = -1;
	infile = 0;
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], "<", 1) == 0 && cmd[i + 1] != NULL \
		&& ft_strncmp(cmd[i], "<<", 2))
			infile++;
	}
	return (infile);
}

int	cnt_heredoc(char **cmd)
{
	int	i;
	int	heredoc;

	i = -1;
	heredoc = 0;
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], "<<", 2) == 0 && cmd[i + 1] != NULL)
			heredoc++;
	}
	return (heredoc);
}

int	cnt_outfile(char **cmd)
{
	int	i;
	int	outfile;

	i = -1;
	outfile = 0;
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], ">", 1) == 0 && cmd[i + 1] != NULL \
		&& ft_strncmp(cmd[i], ">>", 2))
			outfile++;
	}
	return (outfile);
}

int	cnt_append(char **cmd)
{
	int	i;
	int	append;

	i = -1;
	append = 0;
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], ">>", 2) == 0 && cmd[i + 1] != NULL)
			append++;
	}
	return (append);
}
