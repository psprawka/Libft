/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:15 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:27:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_list(t_list **list, int key)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	prev = NULL;

	while (tmp)
	{
		if (tmp->key == key)
		{
			if (prev == NULL)
				*list = tmp->next;
			else
			{
				prev->next = tmp->next;
				free(tmp);
			}
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}