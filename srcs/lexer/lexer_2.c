/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:06:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/03 11:49:08 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_2(char *s)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) == is_quote(s[0]))
		{
			if (is_quote(s[i + 1]))
			{
				// printf("s[%d] = %c\n", i + 1, s[i]);
				j = i + 1;
				i += 2;
				while (s[i++])
				{
					if (is_quote(s[i]) == is_quote(s[j]))
					{
						count++;
						// printf("quote2count = %d\n", count);
						return (count);
					}
				}
			}
			count++;
			// printf("quote1count = %d\n", count);
			return (count);
		}
	}
	// printf("count = %d\n", count);
	return (count);
}

int	count_len_quote2(char *s, int i)
{
	int	j;

	j = i + 1;
	i += 2;
	while (s[i++])
	{
		if (is_quote(s[i]) == is_quote(s[j]))
		{
			
			break;
		}
	}
	// if (is_quote(s[i]) != is_quote(s[j]))
	// {
	// 	print_str(BMAG"quote are not pair in lexer (ㆆ_ㆆ)\n"RESET);
	// 	exit(EXIT_FAILURE);
	// }
	return (i);
}

int	count_len_quote(char *s)
{
	int	i;

	printf("s = %s\n", s);
	i = 0;
	while (s[i])
	{
		i++;
		if (is_quote(s[i]) == is_quote(s[0]))
		{
			if (is_quote(s[i + 1]))
			{
				i = count_len_quote2(s, i);
				break;
			}
			i++;
			printf("len quote = %d\n", i);
			return (i);
		}
	}
	// if (is_quote(s[i]) != is_quote(s[0]))
	// {
	// 	print_str(BMAG"quote are not pair in lexer (ㆆ_ㆆ)\n"RESET);
	// 	exit(EXIT_FAILURE);
	// }
	// printf("len2 quote = %d\n", i);
	// printf("=========\n");
	return (i);
}

int	check_word_lexer(char *s, int len, int i)
{
	int	count;

	count = 0;
	while (i < len)
	{
		if (is_quote(s[i]) > 0)
		{
			count += check_word_2(&s[i]);
			i += count_len_quote(&s[i]);
			// printf("count = %d\n", count);
			// printf("i = %d\n", i);
		}
		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
		{
			i++;
			count++;
		}
		if (!is_space(s[i]) && is_tokens(s[i]) == -1 && !is_quote(s[i]) && s[i])
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

int	count_letter_split2(char *s, int i)
{
	int	j;

	while (s[i++])
	{
		if (is_quote(s[i]) == is_quote(s[0]))
		{
			if (is_quote(s[i + 1]))
			{
				j = i + 1;
				while (s[i++])
				{
					if (is_quote(s[i]) == is_quote(s[j]))
					break;
				}
			}
			else
				break;
		}
	}
	return (i + 1);
}

int	count_letter_split(char *s, int i)
{
	while (s[i] && is_tokens(s[i]) != -1)
			i++;
	if (is_quote(s[i]) > 0)
	{
		i = count_letter_split2(s, i);
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
