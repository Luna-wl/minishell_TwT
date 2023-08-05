/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:06:14 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 18:22:31 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	count_letter_lexer(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && is_space(s[i]))
		i++;
	j = i;
	while (s[i] && is_tokens(s[i]) != -1 && !is_space(s[i]))
	{
		i++;
		if (is_quote(s[i + 1]))
			i++;
		if (is_tokens(s[i]) == -1)
			return (i);
	}
	if (is_quote(s[i]))
		return (count_letter2(s, i, j));
	while (s[i++] && is_tokens(s[i]) == -1 && !is_space(s[i]))
	{
		// printf("s[i] = %c\n", s[i]);
		if (is_quote(s[i]))
			return (i);
	}
	return (i);
}

int	count_letter2(char *s, int i, int j)
{
	while (s[i])
	{
		j++;
		if (is_quote(s[j]) && (s[j + 1] == '\0' || is_space(s[j + 1])) && \
		!is_quote(s[j + 1]))
			break ;
		if (s[j + 1] == '\0' || is_space(s[j + 1]))
			break ;
	}
	return (j + 1);
}
