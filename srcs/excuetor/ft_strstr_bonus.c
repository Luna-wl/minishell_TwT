/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:51:49 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/06 15:39:59 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_strstr(char *str, char *find)
{
	int	i;
	int	j;
	int	cp;

	i = 0;
	cp = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (find[j])
			{
				if (str[i] == find[j])
					cp++;
				j++;
				i++;
			}
			if (cp == j)
				return (0);
		}
		i++;
	}
	return (-1);
}
