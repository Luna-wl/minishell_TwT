/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:06:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/03 16:35:19 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_2(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i++])
	{
		if (is_quote(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])) && \
		!is_quote(s[i + 1]))
		{
			count++;
			break ;
		}
		if (is_quote(s[i]) && (s[i + 1] == '\0' || !is_space(s[i + 1])))
		{
			if (is_space(s[i + 1]))
				break ;
			count++;
			break ;
		}
	}
	return (count);
}

int	count_len_quote2(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])) && \
		!is_quote(s[i + 1]))
		{
			i++;
			break ;
		}
	}
	return (i);
}

int	count_len_quote(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])) && \
		!is_quote(s[i + 1]))
		{
			i++;
			break ;
		}
	}
	return (i);
}

int	count_letter_split(char *s, int i)
{
	while (s[i] && is_tokens(s[i]) != -1)
		i++;
	if (is_quote(s[i]))
	{
		i = count_len_quote2(&s[i]);
		return (i);
	}
	while (s[i] && is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && \
		is_quote(s[i]) == 0)
	{
		if (i > 0 && is_tokens(s[i - 1]) != -1)
			return (i);
		if (is_space(s[i]) == 0 && is_tokens(s[i]) == -1)
			i++;
	}
	return (i);
}
