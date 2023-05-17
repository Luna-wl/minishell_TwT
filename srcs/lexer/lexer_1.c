/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/05 23:28:01 by wluedara         ###   ########.fr       */
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

void	check_pipe(char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (s[len] == '|')
	{
		print_str(BCYN"Pipe is at the end ¯\\_ಠ_ಠ_/¯\n"RESET);
		exit(EXIT_FAILURE);
	}
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
	check_pipe(s);
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
