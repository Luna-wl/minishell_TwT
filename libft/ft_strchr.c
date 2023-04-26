/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:20:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:10:58 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int				i;
	char			*s;
	unsigned char	ch;

	i = 0;
	ch = c;
	s = (char *)str;
	while (s[i] != '\0' && s[i] != ch)
		i++;
	if (s[i] == ch)
		return (&s[i]);
	return (0);
}
