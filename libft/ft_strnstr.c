/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:20:10 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:11:48 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	x;
	char	*b;
	char	*l;

	if (big == NULL && len == 0)
		return (0);
	b = (char *)big;
	l = (char *)little;
	if (*l == '\0')
		return (b);
	i = 0;
	while (b[i] != '\0' && i < len && len > 0)
	{
		x = 0;
		while (b[i + x] == l[x] && l[x] != '\0' && i + x < len)
		{
			if (l[x + 1] == '\0')
				return (&b[i]);
			x++;
		}
		i++;
	}
	return (0);
}
