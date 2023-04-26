/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:24:51 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:11:59 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)

{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (NULL);
	j = ft_strlen((char *)s);
	if (start > j || len <= 0)
		sub = (char *)malloc(sizeof(char) * 1);
	else if (len >= j)
		sub = (char *)malloc(sizeof(char) * (j - start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && start < j)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
