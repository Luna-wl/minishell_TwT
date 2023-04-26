/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:22:15 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 13:49:45 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	ch;

	s1 = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == ch)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
