/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:50:51 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 15:36:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
// #include "../gnl/get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	str[s1_len] = '/';
	ft_strlcpy(&str[s1_len + 1], s2, s2_len + 1);
	return (str);
}
