/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:03:29 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 15:37:36 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(t_flags *flags, size_t number)
{
	int	len;

	if (number == 0)
	{
		len = 5;
		if (flags->width <= 5)
			return (ft_putstr("(nil)"));
		if (flags->minus == 1)
		{
			ft_putstr("(nil)");
			while (flags->width > len)
				len += ft_putchar(' ');
			return (len);
		}
		while (flags->width > len)
			len += ft_putchar(' ');
		ft_putstr("(nil)");
		return (len);
	}
	if (flags->width > 0)
		return (print_ptr_width(flags->width, flags->minus, number));
	ft_putstr("0x");
	print_ptr2(number, 'x');
	return (ptr_len(number) + 2);
}

int	print_ptr_width(int width, int minus, size_t number)
{
	int	len;

	len = ptr_len(number) + 2;
	if (width <= len)
	{
		ft_putstr("0x");
		print_ptr2(number, 'x');
		return (len);
	}
	if (minus == 1)
	{
		ft_putstr("0x");
		print_ptr2(number, 'x');
		while (width > len)
			len += ft_putchar(' ');
		return (len);
	}
	while (width > len)
		len += ft_putchar(' ');
	ft_putstr("0x");
	print_ptr2(number, 'x');
	return (len);
}

void	print_ptr2(size_t number, char x)
{
	if (number < 16)
	{
		if (x == 'x')
			ft_putchar("0123456789abcdef"[number]);
		else if (x == 'X')
			ft_putchar("0123456789ABCDEF"[number]);
		return ;
	}
	print_ptr2(number / 16, x);
	print_ptr2(number % 16, x);
}

int	ptr_len(size_t number)
{
	int	len;

	len = 1;
	while (number > 15)
	{
		len++;
		number /= 16;
	}
	return (len);
}
