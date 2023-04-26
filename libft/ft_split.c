/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:27:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/22 14:34:59 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_word(char *s, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

int	count_letter(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] != c)
			i++;
	}
	return (i);
}

char	*my_split(char *s, char c)
{
	char	*str;
	int		letter;
	int		i;
	int		j;

	letter = count_letter(s, c);
	str = (char *)malloc(sizeof(char) * (letter + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[j] != 0 && s[j] != c)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**new;
	int		word;
	int		i;
	int		j;

	i = 0;
	word = check_word(s, c);
	new = (char **)malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	j = 0;
	while (i < word)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		new[i++] = my_split(&s[j], c);
		j += count_letter(&s[j], c);
	}
	new[i] = 0;
	return (new);
}
