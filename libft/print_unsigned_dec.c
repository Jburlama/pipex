/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:28:22 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 00:05:42 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_dec(size_t number)
{
	int	count;

	count = 0;
	print_unsigned_dec2(number);
	count = unsigned_decimal_len(number);
	return (count);
}

void	print_unsigned_dec2(size_t number)
{
	if (number < 10)
	{
		ft_putchar('0' + number);
		return ;
	}
	print_unsigned_dec2(number / 10);
	print_unsigned_dec2(number % 10);
}

int	unsigned_decimal_len(size_t number)
{
	int	len;

	len = 1;
	while (number > 9)
	{
		len++;
		number /= 10;
	}
	return (len);
}
