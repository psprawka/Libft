/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 08:29:34 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 08:30:05 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_node(t_queue **queue, t_node *prev, t_node *remove)
{
	if (!prev)
		(*queue)->first = remove->next;
	else
		prev->next = remove->next;
}
