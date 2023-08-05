/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 18:20:07 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_lexer3(char *s, int len, int i)
{
	int	count;

	count = 0;
	while (i < len)
	{
		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
			count++;
		if (is_quote(s[i]))
		{
			count += check_word_2(&s[i]);
			i += count_len_quote(&s[i]);
		}
		if (!is_space(s[i])  && is_tokens(s[i]) == -1 && \
		!is_quote(s[i]) && s[i])
		{
			while (!is_space(s[i]) && is_tokens(s[i]) == -1 && \
			!is_quote(s[i]) && s[i])
			{
				if (is_quote(s[i + 1]))
					i++;
				i++;
			}
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**split_to_cmd(char *s)
{
	int		i;
	int		j;
	int		word;
	int		letter;
	char	**cmd;

	i = 0;
	word = check_word_lexer3(s, ft_strlen(s), i);
	printf("word = %d\n", word);
	cmd = malloc(sizeof(char *) * (word + 1));
	if (!cmd)
		return (0);
	i = 0;
	j = 0;
	while (i < word)
	{
		cmd[i++] = my_split_lexer(&s[j]);
		letter = count_letter_lexer(&s[j]);
		j += letter;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	***cut_test(char **s)
{
	int		i;
	int		len;
	char	***cmd;

	i = 0;
	len = find_len_split(s);
	cmd = malloc(sizeof(char **) * (find_len_split(s) + 1));
	if (!cmd)
		return (0);
	while (i < len)
	{
		cmd[i] = split_to_cmd(s[i]);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
