/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:28:47 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 17:45:06 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(t_flags *flags, size_t number, char x)
{
	int		len;
	char	pref;

	pref = ' ';
	if (flags->zero == 1)
		pref = '0';
	if (flags->width > 0 && flags->prec > 0)
		pref = ' ';
	if (flags->minus == 1)
		return (print_hexa_minus(number, x, flags));
	if (flags->hash == 1)
		return (print_hexa_hash(flags, number, x, pref));
	if (flags->width > 0)
		return (print_hexa_width(number, x, flags, pref));
	if (flags->prec > 0)
		return (print_hexa_prec(number, x, flags->prec - 1));
	len = ptr_len(number);
	print_ptr2(number, x);
	return (len);
}

int	print_hexa_hash(t_flags *flags, size_t number, char x, char pref)
{
	int	count;
	int	len;

	count = 0;
	len = ptr_len(number);
	if (flags->prec - 1 > len)
		len = flags->prec - 1;
	if (pref == '0')
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
		while (count < flags->width - len)
			count += ft_putchar(pref);
		count += print_hexa_prec(number, x, flags->prec - 1);
		return (count);
	}
	while (count < flags->width - 2 - len)
		count += ft_putchar(pref);
	if (number != 0)
		count += ft_putchar('0') + ft_putchar(x);
	count += print_hexa_prec(number, x, flags->prec - 1);
	return (count);
}

int	print_hexa_minus(size_t number, char x, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->hash > 0)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
	}
	count += print_hexa_prec(number, x, flags->prec - 1);
	while (count < flags->width)
		count += ft_putchar(' ');
	return (count);
}

int	print_hexa_width(size_t number, char x, t_flags *flags, char pref)
{
	int	count;
	int	len;

	count = 0;
	len = ptr_len(number);
	if (flags->prec - 1 > len)
		len = flags->prec - 1;
	if (number == 0 && flags->prec == 1)
		len = 0;
	while (count < flags->width - len)
		count += ft_putchar(pref);
	count += print_hexa_prec(number, x, flags->prec - 1);
	return (count);
}

int	print_hexa_prec(size_t number, char x, int precision)
{
	int	count;

	if (number == 0 && precision == 0)
		return (0);
	count = ptr_len(number);
	while (count < precision)
		count += ft_putchar('0');
	print_ptr2(number, x);
	return (count);
}
