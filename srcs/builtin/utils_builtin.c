/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:31:41 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 18:31:44 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	ft_swap(char **s1, char **s2);
int		find_variable_inenv(char *vrb);
int		check_format_variable(char *cmd);
char	*ft_join(char *s1, char *s2);
void	err_msg_builtin(char *cmd1, char *cmd2);

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	find_variable_inenv(char *vrb)
{
	int		i;
	char	*find;
	size_t	len1;
	size_t	len2;

	find = ft_join(vrb, "=");
	len1 = ft_strlen(find);
	len2 = ft_strlen(vrb);
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(find, environ[i], len1) \
		|| !ft_strncmp(vrb, environ[i], len2))
			return (free(find), i);
	}
	return (free(find), -1);
}

int	check_format_variable(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (i == 0)
		{
			if (!ft_isalpha(cmd[i]) && cmd[i] != '_')
				return (0);
		}
		else
		{
			if (!ft_isalpha(cmd[i]) && !ft_isdigit(cmd[i]) && cmd[i] != '_')
				return (0);
		}
	}
	return (1);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len +1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s2_len + 1);
	return (str);
}

void	err_msg_builtin(char *cmd1, char *cmd2)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, cmd1, ft_strlen(cmd1));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd2, ft_strlen(cmd2));
	write(STDERR_FILENO, ": not a valid identifier\n", 25);
}
