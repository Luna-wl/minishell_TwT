/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:13 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/07/01 23:15:02 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize > 0)
	{
		while (dstsize-- > 1 && src[index] != 0)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = 0;
	}
	return (ft_strlen(src));
}
