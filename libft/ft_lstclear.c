/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:00 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/11 15:59:53 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		ptr2 = ptr->next;
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}
