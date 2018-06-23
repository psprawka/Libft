/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:15 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 09:36:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_list(t_node **list, void *data)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *list;
	prev = NULL;

	while (tmp)
	{
		if (tmp->data == data)
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