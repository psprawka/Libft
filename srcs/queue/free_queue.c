/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:38:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 10:16:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_queue(t_queue *queue, void (*fct_free)(void *))
{
	t_node	*tmp;
	t_node	*next;

	if (!queue)
		return ;
	tmp = queue->first;

	while (tmp)
	{
		next = tmp->next;
		if (fct_free)
			fct_free(tmp->data);
		free(tmp);
		tmp = next;
	}
}