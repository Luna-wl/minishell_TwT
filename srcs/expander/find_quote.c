/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:33:14 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 18:33:17 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	check_open_close_quote(char quote, char *str, int *i);
int		strlen_quote(char *str, t_main *main, int i, int j);
char	*get_val_quote(char *str, t_main *main, char *val, int i);
char	*get_val_dollar(char *str, t_main *main, int i);
char	*get_val(char	*vrb, char	*val);

char	check_open_close_quote(char quote, char *str, int *i)
{
	if (!quote && (str[*i] == '\'' || str[*i] == '\"'))
		quote = str[(*i)++];
	if (quote && str[*i] == quote)
	{
		quote = 0;
		(*i)++;
	}
	return (quote);
}

int	strlen_quote(char *str, t_main *main, int i, int j)
{
	char	quote;
	char	*tmp;

	quote = 0;
	while (str[i])
	{
		quote = check_open_close_quote(quote, str, &i);
		if ((!quote || quote == '\"') && str[i] == '$')
		{
			tmp = get_val_dollar(&str[++i], main, 0);
			j += ft_strlen(tmp);
			free(tmp);
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
		}
		if (str[i] && (quote || (!quote && str[i] != '\'' && str[i] != '\"')))
		{
			j++;
			i++;
		}
	}
	return (j);
}

char	*get_val_quote(char *str, t_main *main, char *val, int i)
{
	int		j;
	char	quote;
	char	*tmp;

	j = 0;
	quote = 0;
	val = malloc(sizeof(char) * (strlen_quote(str, main, 0, 0) + 1));
	while (str[i])
	{
		quote = check_open_close_quote(quote, str, &i);
		if ((!quote || quote == '\"') && str[i] == '$')
		{
			tmp = get_val_dollar(&str[++i], main, 0);
			ft_strlcpy(&val[j], tmp, ft_strlen(tmp) + 1);
			j += ft_strlen(tmp);
			free(tmp);
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
		}
		if (str[i] && ((quote && str[i] != quote) \
		|| (!quote && str[i] != '\'' && str[i] != '\"')))
			val[j++] = str[i++];
	}
	val[j] = 0;
	return (val);
}

char	*get_val_dollar(char *str, t_main *main, int i)
{
	char	*vrb;
	char	*val;

	val = NULL;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	vrb = malloc(sizeof(char) * (i + 2));
	i = -1;
	while (str[++i] && str[i] != '\'' && str[i] != '\"')
		vrb[i] = str[i];
	vrb[i] = '=';
	vrb[i + 1] = '\0';
	if (!ft_strncmp(vrb, "?=", 3))
		return (free(vrb), ft_itoa(main->exit_status));
	else if (ft_isdigit(vrb[0]))
	{
		vrb[i] = 0;
		return (&vrb[1]);
	}
	else if (ft_isalpha(vrb[0]))
		val = get_val(vrb, val);
	return (val);
}

char	*get_val(char	*vrb, char	*val)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(vrb);
	while (environ[++i])
	{
		if (ft_strncmp(vrb, environ[i], len) == 0)
		{
			val = ft_strdup(getenv(environ[i]));
			return (free(vrb), val);
		}
	}
	if (!val)
	{
		val = malloc(sizeof(char));
		val[0] = 0;
	}
	return (val);
}
