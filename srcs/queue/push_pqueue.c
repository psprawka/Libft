/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:54:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/16 15:18:37 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void		ft_push_pqueue(t_queue **head, t_node *new, int (*fct)(t_node *, t_node *))
{
	t_node 	*tmp;

	if (!fct)
	{
		ft_push_queue(head, new);
		return ;
	}
	if (!(*head) || !new)
		return ;
	tmp = (*head)->first;

	if (!tmp || !tmp->data || fct(tmp, new))
	{
		new->next = tmp;
		(*head)->first = new;
	}
	else
	{
		while (tmp->next && !(fct(tmp->next, new)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
