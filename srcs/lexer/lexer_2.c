/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:06:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/27 11:57:26 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

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

int	check_word(char *s, int len)
{
	int	count;

	g_i.i = 0;
	count = 0;
	while (g_i.i < len)
	{
		if (is_tokens(s[g_i.i]) != -1 && is_tokens(s[g_i.i + 1]) == -1)
			count++;
		if (is_quote(s[g_i.i]) > 0)
		{
			count += check_word_2(&s[g_i.i]);
			g_i.i += count_len_quote(&s[g_i.i]);
		}
		if (is_space(s[g_i.i]) == 0 && is_tokens(s[g_i.i]) == -1 && \
		is_quote(s[g_i.i]) == 0 && s[g_i.i])
		{
			while (is_space(s[g_i.i]) == 0 && is_tokens(s[g_i.i]) == -1 && \
			is_quote(s[g_i.i]) == 0 && s[g_i.i])
				g_i.i++;
			count++;
		}
		else
			g_i.i++;
	}
	return (count);
}

int	count_letter_split(char *s)
{
	g_i.i = 0;
	while (s[g_i.i] && is_tokens(s[g_i.i]) != -1)
	{
		if (is_tokens(s[g_i.i]) != -1)
			g_i.i++;
	}
	if (is_quote(s[g_i.i]) > 0)
	{
		while (s[g_i.i])
		{
			g_i.i++;
			if (is_quote(s[g_i.i]) == is_quote(s[0]))
				return (g_i.i + 1);
		}
	}
	while (s[g_i.i] && is_space(s[g_i.i]) == 0 && is_tokens(s[g_i.i]) == -1 && \
		is_quote(s[g_i.i]) == 0)
	{
		if (g_i.i > 0 && is_tokens(s[g_i.i - 1]) != -1)
			return (g_i.i);
		if (is_space(s[g_i.i]) == 0 && is_tokens(s[g_i.i]) == -1)
			g_i.i++;
	}
	return (g_i.i);
}

int	count_letter(char *s)
{
	init_int();
	while (s[g_i.i] && is_space(s[g_i.i]) == 1)
	{
		g_i.i++;
		g_i.j++;
	}
	while (s[g_i.i] && is_tokens(s[g_i.i]) != -1 && is_space(s[g_i.i]) == 0)
	{
		g_i.i++;
		if (is_tokens(s[g_i.i]) == -1)
			return (g_i.i);
	}
	while (s[g_i.i] && is_quote(s[g_i.i]) > 0)
	{
		g_i.j++;
		if (is_quote(s[g_i.i]) == is_quote(s[g_i.j]))
			return (g_i.j + 1);
	}
	while (s[g_i.i] && is_tokens(s[g_i.i]) == -1 && is_space(s[g_i.i]) == 0)
	{
		g_i.i++;
		if (is_quote(s[g_i.i]) > 0)
			return (g_i.i);
	}
	return (g_i.i);
}
