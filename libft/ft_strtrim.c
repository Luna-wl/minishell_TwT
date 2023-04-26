/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:13:00 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/17 20:56:17 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		len;
	int		x;
	int		i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	len = ft_strlen((char *)s1);
	while (x < len && ft_strchr(set, s1[x]))
		x++;
	while (len - 1 >= 0 && ft_strchr(set, s1[len - 1]))
		len--;
	if (len == 0)
		trim = (void *)malloc(sizeof(char) * 1);
	else
		trim = (void *)malloc(sizeof(char) * (len - x + 1));
	if (!trim)
		return (0);
	i = 0;
	while (x < len)
		trim[i++] = s1[x++];
	trim[i] = '\0';
	return (trim);
}
