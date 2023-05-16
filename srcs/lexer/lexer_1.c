/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/03 14:31:51 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	init_int(void)
{
	g_i.i = 0;
	g_i.j = 0;
}

int	check_quote(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = ft_strlen(s[i]);
		if (is_quote(s[i][0]) == 1 && is_quote(s[i][j - 1]) != 1)
			return (0);
		else if (is_quote(s[i][0]) == 2 && is_quote(s[i][j - 1]) != 2)
			return (0);
		i++;
	}
	return (1);
}

char	*my_split(char *s)
{
	char	*str;
	char	*s2;
	int		letter;
	int		i;
	int		j;

	s2 = ft_strtrim(s, " ");
	letter = count_letter_split(s2);
	// printf(BLU"letter = %d\n"RESET, letter);
	str = malloc(sizeof(char) * (letter + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s2[j] && j < letter)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s2);
	return (str);
}

char	**cut_cmd(char *s)
{
	char	**new;
	int		word;
	int		i;
	int		j;
	int		letter;

	if (!s)
		return (0);
	word = check_word(s, ft_strlen(s));
	new = malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (i < word)
	{
		new[i++] = my_split(&s[j]);
		letter = count_letter(&s[j]);
		j += letter;
	}
	new[i] = NULL;
	return (new);
}
