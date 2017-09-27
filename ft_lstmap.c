/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/24 20:12:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	if (lst)
	{
		new = f(lst);
		first = new;
		while (lst->next)
		{
			lst = lst->next;
			if (!(new->next = f(lst)))
			{
				free(new->next);
				return (NULL);
			}
			new = new->next;
		}
	}
	else
		first = NULL;
	return (first);
}
