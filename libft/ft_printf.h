/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:30 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/29 17:04:41 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	prec;
	int	point;
	int	width;
}	t_flags;

int		ft_printf(const char *str, ...);
void	update_struct(t_flags *flags, const char *str, int *poss);
int		print_format(t_flags *flags, const char *str, int *poss, va_list ap);
int		print_char(t_flags *flags, int c);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long number);
int		decimal_len(long number);
int		print_string(t_flags *flags, char *str);
int		print_string_precision(int precision, char *str);
int		print_string_width(int width, char *str, int minus);
int		strwidprec(int width, int precision, char *str, int minus);
int		print_ptr(t_flags *flags, size_t number);
void	print_ptr2(size_t number, char x);
int		ptr_len(size_t number);
int		print_ptr_width(int width, int minus, size_t number);
int		print_unsigned(t_flags *flags, unsigned int number);
int		print_unsigned_dec(size_t number);
void	print_unsigned_dec2(size_t number);
int		unsigned_decimal_len(size_t number);
int		print_decimal(t_flags *flags, long number);
int		print_decimal_prec(long number, int precision, char sign);
int		print_decimal_width(long number, int width, char prefixo, char sign);
int		print_decimal_width2(long number, int width, char prefixo, char sign);
int		print_dec_wid_ze(long number, int width);
int		decwidprec(long number, int width, int prec, char sign);
int		decwidprec2(long number, int width, int prec, char sign);
int		print_decimal_minus(long number, int width, int prec, char sign);
int		print_hexa(t_flags *flags, size_t number, char x);
int		print_hexa_prec(size_t number, char x, int precision);
int		print_hexa_width(size_t number, char x, t_flags *flags, char pref);
int		print_hexa_minus(size_t number, char x, t_flags *flags);
int		print_hexa_hash(t_flags *flags, size_t number, char x, char pref);

#endif
