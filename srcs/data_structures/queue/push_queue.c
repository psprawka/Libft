/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:47:12 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 08:34:49 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_queue(t_queue **head, t_node *new)
{
	t_node	*tmp;

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
