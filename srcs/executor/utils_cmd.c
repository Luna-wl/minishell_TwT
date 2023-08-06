/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:52:27 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 02:49:19 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		ft_find_slash(char *str);
void	get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);
void	get_command(t_main *main, t_cmd *tmp);
int		check_redirect(char *s);
void	ft_close_pipe(t_main *main, int pfd);

int	ft_find_slash(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '/')
			return (0);
	}
	return (-1);
}

void	get_letter_cmd(t_cmd *tmp, char *s, int cnt_word)
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

void	get_command(t_main *main, t_cmd *tmp)
{
	int		i;
	int		cnt_word;

	i = -1;
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
			i++;
	}
}

int	check_redirect(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (!ft_strncmp(s, ">>", len) || !ft_strncmp(s, "<<", len))
		return (0);
	if (!ft_strncmp(s, ">", len) || !ft_strncmp(s, "<", len))
		return (0);
	return (1);
}

void	ft_close_pipe(t_main *main, int pfd)
{
	if (main->num_pipe > 0)
		close(pfd);
}
