/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:52:03 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/10 22:43:34 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(long n);
char	*get_nstr(long n, int len);
char	*get_str(long n, int len);

char	*ft_itoa(int n)
{
	long	l_n;
	int		len;
	char	*str;

	l_n = n;
	if (l_n == 0)
		return (ft_strdup("0"));
	len = get_len(l_n);
	if (l_n < 0)
	{
		l_n = -l_n;
		str = get_nstr(l_n, len + 1);
		return (str);
	}
	str = get_str(l_n, len);
	return (str);
}

char	*get_str(long n, int len)
{
	char	*str;

	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*get_nstr(long n, int len)
{
	char	*str;
	int		i;

	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	i = len;
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

int	get_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
