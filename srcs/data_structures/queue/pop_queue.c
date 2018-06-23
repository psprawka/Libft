/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:11:54 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/15 14:54:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_pop_queue(t_queue **queue)
{
	t_node *tmp;

	if (!(*queue) || !(*queue)->first)
		return (NULL);

	tmp = (*queue)->first;
	(*queue)->first = tmp->next;
	return (tmp);
}
