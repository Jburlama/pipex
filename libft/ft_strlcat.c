/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:25:48 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/06 16:15:33 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	while (src[j] != '\0' && (i + 1 < size))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (i > size)
		return (len_src + size);
	return (len_dst + len_src);
}
