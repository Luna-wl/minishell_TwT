
#include "hell.h"

char *get_val_dollar(char *str, t_main *main);

int	strlen_quote(char *str, t_main *main)
{
	int		i;
	int		j;
	char	quote;
	char	*tmp;

	// val = ft_strdup("\0");
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i++];
		if (quote && str[i] == quote)
		{
			quote = 0;
			i++;
		}
		if ((!quote || quote == '\"') && str[i] == '$')
		{
			tmp = get_val_dollar(&str[++i], main);
			j += ft_strlen(tmp);
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
		}
		if (quote || (!quote && str[i] != '\'' && str[i] != '\"'))
		{
			j++;
			i++;
		}
	}
	return (j + 1);
}

char	*get_val_quote(char *str, t_main *main, char *val)
{
	int		i;
	int		j;
	char	quote;
	char	*tmp;

	(void) main;
	i = 0;
	j = 0;
	quote = 0;
	val = malloc(sizeof(char) * strlen_quote(str, main));
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i++];
		if (quote && str[i] == quote)
		{
			quote = 0;
			i++;
		}
		if ((!quote || quote == '\"') && str[i] == '$')
		{
			tmp = get_val_dollar(&str[++i], main);
			// printf("Before &val[%d]= |%s|, tmp = |%s|, len(tmp) = %d\n", j, &val[j], tmp, ft_strlen(tmp));
			ft_strlcpy(&val[j], tmp, ft_strlen(tmp) + 1);
			// printf("After &val[%d]= |%s|, tmp = |%s|, len(tmp) = %d\n", j, &val[j], tmp, ft_strlen(tmp));
			// printf("Before j = %d\n", j);
			j += ft_strlen(tmp);
			// printf("After  j = %d\n", j);
			while (str[i] && str[i] != '\'' && str[i] != '\"')
			{
				// printf("vrb --> str[%d] = %c\n", i, str[i]);
				i++;
			}
		}
		if ((quote && str[i] != quote) || (!quote && str[i] != '\'' && str[i] != '\"'))
		{
			val[j++] = str[i++];
			// printf("val[%d] = |%c| -- str[%d]= |%c|\n", j - 1, val[j -1], i-1, str[i-1]);
		}
	}
	val[j] = 0;
	return (val);
}

char *get_val_dollar(char *str, t_main *main)
{
	char	*vrb;
	int		i;
	int		len;
	char	*val;

	i = 0;
	(void) main;
	val = NULL;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	vrb = malloc(sizeof(char) * (i + 2));
	i = -1;
	while (str[++i] && str[i] != '\'' && str[i] != '\"')
		vrb[i] = str[i];
	vrb[i] = '=';
	vrb[i + 1] = '\0';
	if (ft_isdigit(vrb[0]))
		return (&vrb[1]);
	else if (ft_isalpha(vrb[0]))
	{
		i = -1;
		len = ft_strlen(vrb);
		while (environ[++i])
		{
			// printf("environ[%d] = |%s| val = |%s| vrb = |%s|\n", i, environ[i], val, vrb);
			if (ft_strncmp(vrb, environ[i], len) == 0)
			{
				val = getenv(environ[i]);
				// printf("path[%d] = |%s| val = |%s|\n", i, environ[i], val);
				return (val);
			}
		}
		if (!val)
		{
			val = malloc(sizeof(char));
			val[0] = 0;
		}
	}
return (val);
}
