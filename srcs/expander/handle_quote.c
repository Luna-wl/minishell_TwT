/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:36:06 by wluedara          #+#    #+#             */
/*   Updated: 2023/05/29 17:12:51 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*cut_quote(char *str)
{
	int		i;
	char	*new;

	i = len_quote(str);
	if (str[0] == '\'' | str[0] == '\"')
		new = copy_str(&str[1], i);
	else
		new = copy_str(str, i);
	free(str);
	return (new);
}

char	*detact_quote2(char *str, t_main *main, char *val)
{
	char	*tmp;
	char	*tmp2;
	int		len;
	int		i;
	int		j;

	tmp2 = detact_quote(str, main, val);
	len = ft_strlen(tmp2);
	tmp = malloc(len + 3);
	if (!tmp)
		return (0);
	tmp[0] = '\'';
	i = 1;
	j = 0;
	while (i <= len)
		tmp[i++] = tmp2[j++];
	tmp[i] = '\'';
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*detact_quote(char *str, t_main *main, char *val)
{
	str = cut_quote(str);
	if (str[0] == '$')
		val = detact_dollar(str, main);
	else if (str[0] == '\'')
	{
		val = detact_quote2(str, main, val);
		return (val);
	}
	else
		val = str;
	return (val);
}
