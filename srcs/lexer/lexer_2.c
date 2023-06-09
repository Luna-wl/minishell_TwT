/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:06:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/09 17:19:43 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_2(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) == is_quote(s[0]))
		{
			count++;
			return (count);
		}
	}
	return (count);
}

int	count_len_quote(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) == is_quote(s[0]))
			return (i);
	}
	if (is_quote(s[i]) != is_quote(s[0]))
	{
		print_str(BMAG"quote are not pair in lexer (ㆆ_ㆆ)\n"RESET);
		exit(EXIT_FAILURE);
	}
	return (i);
}

int	check_word_lexer(char *s, int len, int i)
{
	int	count;

	count = 0;
	while (i < len)
	{
		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
			count++;
		if (is_quote(s[i]) > 0)
		{
			count += check_word_2(&s[i]);
			i += count_len_quote(&s[i]);
		}
		if (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && \
		is_quote(s[i]) == 0 && s[i])
		{
			while (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && \
			is_quote(s[i]) == 0 && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

int	count_letter_split(char *s, int i)
{
	while (s[i] && is_tokens(s[i]) != -1)
	{
		if (is_tokens(s[i]) != -1)
			i++;
	}
	if (is_quote(s[i]) > 0)
	{
		while (s[i])
		{
			i++;
			if (is_quote(s[i]) == is_quote(s[0]))
				return (i + 1);
		}
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
