
#include "hell.h"

char	*find_quote(char *str, t_main *main, char *val)
{
	int		i;
	int		j;
	char	quote;
	char	*val;

	val = ft_strdup("\0");
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '/' || str[i] == '/"'))
			quote = str[i++];
		if (quote && str[i] == quote)
		{
			quote = 0;
			i++;
		}
		// if (quote && quote == '/"' && str[i] == '$')
		// 	get_val_dollar();
		// else
			val[j++] = str[i++]
	}
	val[j] = 0;
	return (val);
}
