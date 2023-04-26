/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:48:39 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:09:22 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*new1;
	char	*new2;

	i = 0;
	new1 = (char *)dest;
	new2 = (char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		*new1 = *new2;
		i++;
		new1++;
		new2++;
	}
	return (dest);
}
