/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:47:12 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/16 12:54:11 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_queue(t_queue **head, t_node *new)
{
	t_node 		*tmp;

	if (!(*head) || !new)
		return ;
	tmp = (*head)->first;

	if (!tmp || !tmp->data)
	{
		new->next = tmp;
		(*head)->first = new;
		(*head)->last = new;
	}
	else if (!(tmp->next))
	{
		tmp->next = new;
		(*head)->last = new;
	}
	else
	{
		(*head)->last->next = new;
		(*head)->last = new;
	}
}
