/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:29:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 16:56:35 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*detact_dollar(char *str, t_main *main);
char	*expander_handel(t_main *main, char *str);
void	expander(t_main *main);

char	*detact_dollar(char *str, t_main *main)
{
	char	*val;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(main->envp[j]);
	if (ft_isdigit(str[i + 1]))
		return (&str[i + 1]);
	else if (ft_isalpha(str[i + 1]))
	{
		while (main->envp[j])
		{
			if (ft_strncmp(&str[i + 1], main->envp[j], len) == 0)
			{
				val = getenv(main->envp[j]);
				return (val);
			}
			j++;
		}
	}
	return (0);
}

char	*expander_handel(t_main *main, char *str)
{
	char	*val;

	val = NULL;
	val = get_val_quote(str, main, val, 0);
	return (val);
}

void	expander(t_main *main)
{
	t_cmd	*tmp;
	int		i;
	char	*expan;

	tmp = main->cmd;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->str[++i])
		{
			expan = expander_handel(main, tmp->str[i]);
			if (expan)
			{
				free(tmp->str[i]);
				tmp->str[i] = ft_strdup(expan);
				free(expan);
			}
		}
		tmp = tmp->next;
	}
}
