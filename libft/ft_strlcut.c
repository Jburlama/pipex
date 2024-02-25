/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 04:55:24 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/20 03:21:19 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcut(char *str, char c)
{
	int		len;
	int		i;
	char	*new;

	len = ft_strlen(str);
	while (len >= 0 && str[len] != c)
		len--;
	if (len < 0)
		return (ft_strdup(str));
	len++;
	new = ft_calloc(sizeof(*new), len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[len])
	{
		new[i++] = str[len];
		len++;
	}
	return (new);
}
