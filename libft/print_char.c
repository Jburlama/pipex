/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:04:36 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/28 17:29:07 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_flags *flags, int c)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_putchar(c);
		flags->width--;
		while (flags->width > 0)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		return (count);
	}
	while (flags->width > 1)
	{
		count += ft_putchar(' ');
		flags->width--;
	}
	count += ft_putchar(c);
	return (count);
}

int	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}
