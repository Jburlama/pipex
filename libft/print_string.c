/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:40:24 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/27 21:50:57 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(t_flags *flags, char *str)
{
	if (flags->width > 0 && flags->prec > 0)
		return (strwidprec(flags->width, flags->prec - 1, str, flags->minus));
	if (flags->width > 0)
		return (print_string_width(flags->width, str, flags->minus));
	if (flags->prec > 0)
		return (print_string_precision(flags->prec - 1, str));
	return (ft_putstr(str));
}

int	strwidprec(int width, int precision, char *str, int minus)
{
	int	len;
	int	count;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		if (precision < 6)
			precision = 0;
	}
	len = ft_strlen(str);
	if (precision < len)
		len = precision;
	if (len >= width)
		return (print_string_precision(precision, str));
	if (minus == 1)
	{
		count = print_string_precision(precision, str);
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	while (count < width - len)
		count += ft_putchar(' ');
	return (count + print_string_precision(precision, str));
}

int	print_string_width(int width, char *str, int minus)
{
	int	len;
	int	count;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	count = 0;
	if (len >= width)
		return (ft_putstr(str));
	if (minus == 1)
	{
		count += ft_putstr(str);
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	while (count < width - len)
		count += ft_putchar(' ');
	count += ft_putstr(str);
	return (count);
}

int	print_string_precision(int precision, char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		if (precision < 6)
			precision = 0;
	}
	while (str[count] && count < precision)
		count += ft_putchar(str[count]);
	return (count);
}
