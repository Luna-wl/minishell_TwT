/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:57:32 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/05 00:46:55 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int		len;
	long	n;

	len = 0;
	n = num;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_putnbr2(unsigned int num, unsigned int base, char flag)
{
	int	len;

	len = 0;
	if (num >= base)
		len += ft_putnbr2(num / base, base, flag);
	if (flag != 'X')
		len += write(1, &"0123456789abcdef"[num % base], 1);
	else
		len += write(1, &"0123456789ABCDEF"[num % base], 1);
	return (len);
}

int	ft_puthex(size_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex(num / 16);
	len += write(1, &"0123456789abcdef"[num % 16], 1);
	return (len);
}
