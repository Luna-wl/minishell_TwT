/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:48:22 by wluedara          #+#    #+#             */
/*   Updated: 2022/09/27 23:07:01 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	len(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}	
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	long	nb;

	i = len(n) - 1;
	num = (char *)malloc(sizeof(char) * i + 2);
	if (!num)
		return (NULL);
	num[i + 1] = '\0';
	nb = n;
	if (nb == 0)
		num[i] = '0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		num[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (num);
}
