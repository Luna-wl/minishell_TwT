/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:37:16 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/02 00:54:41 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*copy_str(char *s, int len)
{
	int		i;
	char	*new;

	new = malloc(len + 1);
	if (!new)
		return (0);
	i = -1;
	while (++i < len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}

int	len_quote(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (s[i] == '\'' | s[i] == '\"')
		len -= 2;
	return (len);
}

void	check_val(char **cmd)
{
	(void)cmd;
// 	printf("=======\n");
// 	pim_split(cmd);
// 	printf("=======\n");
}
