/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:41:15 by msrun             #+#    #+#             */
/*   Updated: 2016/11/16 16:09:27 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*addr;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	addr = tmp;
	while (lst)
	{
		lst = lst->next;
		if (lst)
		{
			tmp->next = f(lst);
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
	return (addr);
}
