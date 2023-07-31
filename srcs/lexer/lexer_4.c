/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:06:14 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/09 17:20:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	count_letter_lexer(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && is_space(s[i]) == 1)
		i++;
	j = i;
	while (s[i] && is_tokens(s[i]) != -1 && is_space(s[i]) == 0)
	{
		i++;
		if (is_tokens(s[i]) == -1)
			return (i);
	}
	if (is_quote(s[i]) > 0)
		return (count_letter2(s, i, j));
	while (s[i] && is_tokens(s[i]) == -1 && is_space(s[i]) == 0)
	{
		i++;
		if (is_quote(s[i]) > 0)
			return (i);
	}
	return (i);
}

int	count_letter2(char *s, int i, int j)
{
	while (s[i] && is_quote(s[i]) > 0)
	{
		j++;
		if (is_quote(s[i]) == is_quote(s[j]))
			break ;
	}
	return (j + 1);
}
