/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:25:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/26 18:12:17 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

int	check_redirect(char *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	// g_num.num_redirect = 0;
	while (s[i])
	{
		while (j < 4)
		{
			if (ft_strncmp(s, "<", 1) == 0)
				return (1);
			else if (ft_strncmp(s, "<<", 2) == 0)
				return (2);
			else if (ft_strncmp(s, ">", 1) == 0)
				return (3);
			else if (ft_strncmp(s, ">>", 2) == 0)
				return (4);
			j++;
		}
		i++;
	}
	return (-1);
}
