/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:12:30 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/03 14:31:54 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	find_len_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	add_last(t_lexer **list, t_lexer *last)
{
	t_lexer	*tmp;

	if (*list == NULL)
	{
		*list = last;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = last;
}

void	init_list(t_lexer **list, char *str)
{
	t_lexer	*hua;

	hua = malloc(sizeof(t_lexer));
	hua->str = ft_strdup(str);
	hua->next = NULL;
	add_last(list, hua);
}

void	insert_index(t_lexer **list, int len)
{
	t_lexer	*tmp;
	int		i;

	tmp = *list;
	i = -1;
	while (tmp != NULL && i < len)
	{
		if (tmp->str != NULL)
			tmp->index = i + 1;
		tmp = tmp->next;
		i++;
	}
}

t_lexer	*spilt_to_list(char **str, t_lexer *list)
{
	int	i;
	int	len;

	i = 0;
	len = find_len_split(str);
	while (i < len)
	{
		init_list(&list, str[i]);
		i++;
	}
	insert_index(&list, len);
	del_split(str);
	return (list);
}
