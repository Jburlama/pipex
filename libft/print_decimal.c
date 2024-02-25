/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:35 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 00:13:56 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(t_flags *flags, long number)
{
	char	prefixo;
	char	sign;

	prefixo = ' ';
	sign = '-';
	if (flags->space == 1)
		sign = ' ';
	if (flags->zero == 1)
		prefixo = '0';
	if (flags->plus == 1)
		sign = '+';
	if (flags->minus > 0)
		return (print_decimal_minus(number, flags->width,
				flags->prec -1, sign));
	if (flags->width > 0 && flags->prec > 0)
		return (decwidprec(number, flags->width, flags->prec - 1, sign));
	if (flags->width > 0)
		return (print_decimal_width(number, flags->width, prefixo, sign));
	if (flags->prec > 0)
		return (print_decimal_prec(number, flags->prec - 1, sign));
	if (number < 0)
		return (ft_putnbr(number));
	if (sign == '+' || sign == ' ')
		return (ft_putchar(sign) + print_unsigned_dec(number));
	return (print_unsigned_dec(number));
}

int	print_decimal_minus(long number, int width, int prec, char sign)
{
	int	count;

	count = 0;
	if (number == 0 && width > 0)
	{
		if (prec != 0)
			count += ft_putchar('0');
		while (count < prec)
			count += ft_putchar('0');
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	count += print_decimal_prec(number, prec, sign);
	while (count < width)
		count += ft_putchar(' ');
	return (count);
}

int	decwidprec(long number, int width, int prec, char sign)
{
	int	count;
	int	len;

	count = 0;
	if (number < 0)
	{
		len = decimal_len(number) - 1;
		if (prec > len)
			len = prec;
		while (count < width - len - 1)
			count += ft_putchar(' ');
		return (count + print_decimal_prec(number, prec, sign));
	}
	if (sign == '+' || sign == ' ')
		return (decwidprec2(number, width, prec, sign));
	len = unsigned_decimal_len(number);
	if (number == 0)
		len = 0;
	if (prec > len)
		len = prec;
	while (count < width - len)
		count += ft_putchar(' ');
	return (count + print_decimal_prec(number, prec, sign));
}

int	print_decimal_width(long number, int width, char prefixo, char sign)
{
	int	len;
	int	count;

	count = 0;
	if (number < 0)
	{
		len = decimal_len(number);
		if (prefixo == '0')
			return (print_dec_wid_ze(number, width));
		while (count < width - len)
			count += ft_putchar(' ');
		return (count + ft_putnbr(number));
	}
	if (sign == '+')
		return (print_decimal_width2(number, width, prefixo, sign));
	len = unsigned_decimal_len(number);
	while (count < width - len)
		count += ft_putchar(prefixo);
	return (count + print_unsigned_dec(number));
}

int	print_decimal_prec(long number, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	if (number == 0 && precision == 0)
		return (0);
	if (number < 0)
		return (print_dec_wid_ze(number, precision + 1));
	len = unsigned_decimal_len(number);
	if (sign == '+' || sign == ' ')
	{
		ft_putchar(sign);
		while (count < precision - len)
			count += ft_putchar('0');
		return (count + print_unsigned_dec(number) + 1);
	}
	while (count < precision - len)
		count += ft_putchar('0');
	return (count + print_unsigned_dec(number));
}
