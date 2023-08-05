/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 14:44:51 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*my_split_lexer(char *s)
{
	char	*str;
	char	*s2;
	int		letter;
	int		i;
	int		j;

	s2 = ft_strtrim(s, " ");
	letter = count_letter_split(s2, 0);
	// printf("letter = %d\n", letter);
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

int	check_error(char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (len == 0)
		return (0);
	if (s[len] == '|')
	{
		print_str(BCYN"Pipe is at the end ¯\\_ಠ_ಠ_/¯\n"RESET);
		return (0);
	}
	else if (s[len] == '>' || s[len] == '<')
	{
		print_str(BMAG"Command is not complete ۹( ÒہÓ )۶\n"RESET);
		return (0);
	}
	return (1);
}

int	check_quote_pair(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{

	}
	return (1);
}
