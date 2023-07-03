/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:17:02 by wluedara          #+#    #+#             */
/*   Updated: 2023/07/03 13:45:09 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	**check_heredoc(char **cmd, int hc)
{
	int		i;
	int		j;
	char	**str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char *) * hc + 1);
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], "<<", 2) == 0 && cmd[i + 1] != NULL)
			str[j++] = ft_strdup(cmd[i + 1]);
	}
	str[j] = NULL;
	return (str);
}

char	**check_infile(char **cmd, int inf)
{
	int		i;
	int		j;
	char	**str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char *) * inf + 1);
	while (cmd[++i] && j < inf)
	{
		if ((!ft_strncmp(cmd[i], "<<", 2) || !ft_strncmp(cmd[i], "<", 1))
		&& cmd[i + 1] != NULL)
			str[j++] = ft_strdup(cmd[i + 1]);
	}
	str[j] = NULL;
	return (str);
}

char	**check_outfile(char **cmd, int of)
{
	int		i;
	int		j;
	char	**str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char *) * of + 1);
	while (cmd[++i] && j < of)
	{
		if ((!ft_strncmp(cmd[i], ">", 1) || !ft_strncmp(cmd[i], ">>", 2))
 		&& cmd[i + 1] != NULL)
			str[j++] = ft_strdup(cmd[i + 1]);
	}
	str[j] = NULL;
	return (str);
}

char	**check_append(char **cmd, int ap)
{
	int		i;
	int		j;
	char	**str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char *) * ap + 1);
	while (cmd[++i])
	{
		if (ft_strncmp(cmd[i], ">>", 2) == 0 && cmd[i + 1] != NULL)
			str[j++] = ft_strdup(cmd[i + 1]);
	}
	str[j] = NULL;
	return (str);
}
