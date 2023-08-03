/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:24:24 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/03 16:03:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_word_lexer3(char *s, int len, int i)
{
	int	count;

	// printf("check_word_lexer\n");
	count = 0;
	// printf("check_word_lexer3 -> s = |%s|\n", s);
	while (i < len)
	{
		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
			count++;
		if (is_quote(s[i]))
		{
			printf("i = %d\n", i);
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

char	**split_to_cmd(char *s)
{
	int		i;
	int		j;
	int		word;
	int		letter;
	char	**cmd;

	i = 0;
	word = check_word_lexer3(s, ft_strlen(s), i);
	// printf("word = %d\n", word);
	cmd = malloc(sizeof(char *) * (word + 1));
	if (!cmd)
		return(0);
	i = 0;
	j = 0;
	while (i < word)
	{
		cmd[i++] = my_split_lexer(&s[j]);
		letter = count_letter_lexer(&s[j]);
		printf("letter = %d\n", letter);
		j += letter;
	}
	cmd[i] = NULL;
	return (cmd);
}

char ***cut_test(char **s)
{
	int		i;
	int		len;
	char	***cmd;

	pim_split(s);
	i = 0;
	len = find_len_split(s);
	cmd = malloc(sizeof(char **) * find_len_split(s) + 1);
	if (!cmd)
		return (0);
	while (i < len)
	{
		cmd[i] = split_to_cmd(s[i]);
		// pim_split(cmd[i]);
		i++;
	}
	cmd[i] = NULL;
	for(int x = 0; x < len; x++) {
		printf("====x = |%d|=====\n", x);
		for(int o = 0; cmd[x][o] ; o++) {
			printf("cmd[%d] = |%s|\n", o, cmd[x][o]);
		}
	}
	return (cmd);
}