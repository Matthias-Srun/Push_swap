/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:39:16 by msrun             #+#    #+#             */
/*   Updated: 2016/11/16 13:10:38 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *freemaillon;

	if (del)
	{
		tmp = *alst;
		while (tmp)
		{
			freemaillon = tmp;
			tmp = tmp->next;
			del(freemaillon->content, freemaillon->content_size);
			free(freemaillon);
		}
		free(tmp);
		*alst = NULL;
	}
}
