/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 04:43:58 by jburlama          #+#    #+#             */
/*   Updated: 2024/02/20 07:29:30 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char	*str, char c)
{
	int		len;
	int		i;
	char	*strcut;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (str[len] == '\0')
		return (ft_strdup(str));
	strcut = ft_calloc(sizeof(*strcut), len + 1);
	if (strcut == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		strcut[i] = str[i];
	return (strcut);
}
