/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:03:55 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 21:09:38 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	stack_lenght(t_lexer **list)
{
	int		len;
	t_lexer	*tmp;

	len = 0;
	tmp = *list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char	**copy_two_stars_new(char **s)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (0);
	len = find_len_split(s);
	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (i < len && s[i])
	{
		new[i++] = ft_strdup(s[j++]);
	}
	new[i] = NULL;
	return (new);
}
