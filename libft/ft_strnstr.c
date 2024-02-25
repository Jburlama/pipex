/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:02:04 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/07 17:38:35 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;
	size_t	k;

	little_len = ft_strlen(little);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (big[k] == little[j] && little[j] != '\0'
			&& big[k] != '\0' && k < len)
		{
			j++;
			k++;
		}
		if (little_len == j)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
