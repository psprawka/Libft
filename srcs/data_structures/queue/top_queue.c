/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:22:54 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/15 10:29:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_top_queue(t_queue *queue)
{
	if (queue && queue->first)
		return (queue->first->data);
	return (NULL);	
}
