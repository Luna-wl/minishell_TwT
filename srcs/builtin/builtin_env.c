/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:09:20 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 17:24:24 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		builtin_env(t_cmd *cmd);
char	**ft_strdup_env(void);
size_t	ft_min_len(char *s1, char *s2);
int		ft_envcpm(char *s1, char *s2);
void	sort_env(char **env);

int	builtin_env(t_cmd *cmd)
{
	int	i;

	if (!environ || (cmd->command && cmd->command[1]))
	{
		err_builtin(cmd, 127);
		exit(127);
	}
	i = -1;
	while (environ[++i])
	{
		if (ft_strrchr(environ[i], '='))
			printf("%s\n", environ[i]);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

char	**ft_strdup_env(void)
{
	int		i;
	char	**new;

	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (environ[++i])
	{
		new[i] = ft_strdup(environ[i]);
	}
	new[i] = NULL;
	return (new);
}

size_t	ft_min_len(char *s1, char *s2)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a > b)
		return (b);
	return (a);
}

int	ft_envcpm(char *s1, char *s2)
{
	size_t	a;
	size_t	b;

	if (ft_strncmp(s1, s2, ft_min_len(s1, s2)) != 0)
		return (ft_strncmp(s1, s2, ft_min_len(s1, s2)));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (ft_strncmp(s1, s2, ft_min_len(s1, s2)) == 0 && a != b)
	{
		if (a > b)
			return ((unsigned char) s1[b] - (unsigned char) '\0');
		else
			return ((unsigned char) s2[a] - (unsigned char) '\0');
	}
	return (0);
}

void	sort_env(char **env)
{
	int		i;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = i;
		while (env[++j])
		{
			if (ft_envcpm(env[i], env[j]) > 0)
				ft_swap(&env[i], &env[j]);
		}
	}
}
