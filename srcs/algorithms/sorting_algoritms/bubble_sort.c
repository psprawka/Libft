/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:54:40 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/02 16:17:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_nodes(t_node *a, t_node *b)
{
	void	*tmp;

	if (!a || !b)
		return ;
		
	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
	a->d_size = sizeof(a->data);
	b->d_size = sizeof(b->data);
}

void		bubble_sort(t_node *head, int (*cmp)(t_node *, t_node *))
{
	t_node	*out;
	t_node	*in;
	
	out = head;
	while (out)
	{
		in = head;
		while (in && in->next)
		{
			if (cmp(in, in->next) == EXIT_SUCCESS)
				swap_nodes(in, in->next);
			in = in->next;
		}
		out = out->next;
	}
}
