/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:33 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 15:40:13 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
// #include "../gnl/get_next_line.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	// int				diff;
	unsigned int	index;

	index = 0;
	// diff = 0;
	while (index < n && (s1[index] != 0 || s2[index] != 0))
	{
		if (s1[index] != s2[index])
			return (1);
		index++;
	}
	return (0);
}
