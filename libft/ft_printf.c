/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:53:27 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/17 19:32:56 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flags;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (str[i] == '%')
		{
			i++;
			while (ft_memchr("-0.# +", str[i], 6) || ft_isdigit(str[i]))
				update_struct(&flags, str, &i);
			count += print_format(&flags, str, &i, ap);
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(ap);
	return (count);
}

int	print_format(t_flags *flags, const char *str, int *poss, va_list ap)
{
	int	count;

	count = 0;
	if (str[*poss] == 'c')
		count += print_char(flags, va_arg(ap, int));
	if (str[*poss] == 's')
		count += print_string(flags, va_arg(ap, char *));
	if (str[*poss] == 'p')
		count += print_ptr(flags, va_arg(ap, size_t));
	if (str[*poss] == 'd' || str[*poss] == 'i')
		count += print_decimal(flags, va_arg(ap, int));
	if (str[*poss] == 'u')
		count += print_decimal(flags, va_arg(ap, unsigned int));
	if (str[*poss] == 'x' || str[*poss] == 'X')
		count += print_hexa(flags, va_arg(ap, unsigned int), str[*poss]);
	if (str[*poss] == '%')
		count += ft_putchar('%');
	(*poss)++;
	return (count);
}

void	update_struct(t_flags *flags, const char *str, int *poss)
{
	while (str[*poss] == '-' || str[*poss] == '+'
		|| str[*poss] == ' ' || str[*poss] == '#')
	{
		if (str[*poss] == ' ')
			flags->space = 1;
		if (str[*poss] == '+')
			flags->plus = 1;
		if (str[*poss] == '-')
			flags->minus = 1;
		if (str[*poss] == '#')
			flags->hash = 1;
		(*poss)++;
	}
	if (str[*poss] == '0')
		flags->zero = 1;
	if (ft_isdigit(str[*poss]) || str[*poss] == '.')
	{
		if (str[*poss] == '.')
			flags->prec = ft_atoi(&str[++(*poss)]) + 1;
		else
			flags->width = ft_atoi(&str[*poss]);
		while (ft_isdigit(str[*poss]))
			(*poss)++;
	}
}
