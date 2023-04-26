/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:49:29 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:11:51 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		len;
	char	*s;
	char	ch;

	ch = c;
	s = (char *)str;
	len = ft_strlen(s) - 1;
	if (ch == '\0')
		return (&s[len + 1]);
	while (len >= 0)
	{
		if (s[len] == ch)
			return (&s[len]);
		len--;
	}
	return (0);
}
