/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:52:00 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/08 18:10:04 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*str;

	i = (size_t)start;
	j = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	while (s[i] != '\0' && j < len)
	{
		i++;
		j++;
	}
	str = ft_calloc(sizeof(char), j + 1);
	if (str == NULL)
		return (NULL);
	str[j--] = '\0';
	i--;
	while (j + 1 > 0)
		str[j--] = s[i--];
	return (str);
}
