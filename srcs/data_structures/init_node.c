/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:38:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 10:14:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_init_node(void *data, size_t dsize)
{
	t_node	*new;

	if (!(new = ft_memalloc(sizeof(t_node))))
		return (NULL);
	new->data = data;
	new->d_size = dsize;
	new->next = NULL;
	return (new);
}
