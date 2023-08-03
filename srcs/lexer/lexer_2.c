/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:06:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/03 15:45:14 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_2(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	// printf("check_word_2 -> s = |%s|\n", s);
	while (s[++i])
	{
		if (is_quote(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])) && \
		!is_quote(s[i + 1]))
		{
			count++;
			break;
		}
	}
	return (count);
}

int	count_len_quote2(char *s)
{
	int		i;

	// printf("s in cl = %s\n", s);
	i = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])) && \
		!is_quote(s[i + 1]))
		{
			i++;
			break;
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
			break;
		}
	}
	return (i);
}

// int	check_word_lexer(char *s, int len, int i)
// {
// 	int	count;

// 	printf("check_word_lexer\n");
// 	count = 0;
// 	while (i < len)
// 	{
// 		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
// 			count++;
// 		if (is_pipe(s[i]))
// 			count++;
// 		if (is_quote(s[i]))
// 		{
// 			count += check_word_2(&s[i]);
// 			i += count_len_quote(&s[i]);
// 		}
// 		if (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && \
// 		is_quote(s[i]) == 0 && s[i])
// 		{
// 			while (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && \
// 			is_quote(s[i]) == 0 && s[i])
// 				i++;
// 			count++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count);
// }

int	count_letter_split(char *s, int i)
{
	// printf("s in letter = |%s|\n", s);
	while (s[i] && is_tokens(s[i]) != -1)
			i++;
	if (is_quote(s[i]))
	{
		i = count_len_quote2(&s[i]);
		// printf("i2 = |%d|\n", i);
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
