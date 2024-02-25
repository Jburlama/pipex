/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:40:30 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 00:02:28 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal_width2(long number, int width, char prefixo, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = unsigned_decimal_len(number) + 1;
	if (prefixo == '0')
	{
		ft_putchar(sign);
		while (count < width - len)
			count += ft_putchar('0');
		return (count + print_unsigned_dec(number) + 1);
	}
	while (count < width - len)
		count += ft_putchar(' ');
	ft_putchar(sign);
	return (count + print_unsigned_dec(number) + 1);
}

int	decwidprec2(long number, int width, int prec, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = unsigned_decimal_len(number);
	if (prec > len)
		len = prec;
	while (count < width - len - 1)
		count += ft_putchar(' ');
	return (count + print_decimal_prec(number, prec, sign));
}

int	ft_putnbr(long number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
		return (ft_putstr("-2147483648"));
	if (number < 0)
	{
		count += ft_putchar('-');
		count += print_unsigned_dec(-number);
		return (count);
	}
	return (print_unsigned_dec(number));
}

int	decimal_len(long number)
{
	int	len;

	if (number == -2147483648)
		return (10);
	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number > 9)
	{
		len++;
		number /= 10;
	}
	return (len);
}

int	print_dec_wid_ze(long number, int width)
{
	long	l_nbr;
	int		count;
	int		len;

	count = 0;
	len = decimal_len(number);
	l_nbr = number;
	if (l_nbr < 0)
	{
		ft_putchar('-');
		l_nbr = -l_nbr;
	}
	while (count < width - len)
		count += ft_putchar('0');
	count += print_unsigned_dec(l_nbr) + 1;
	return (count);
}
