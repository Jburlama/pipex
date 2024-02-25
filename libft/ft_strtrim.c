/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:49:22 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/10 22:41:32 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (*set == '\0')
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
