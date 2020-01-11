/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:13 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:43:16 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode		*ft_init_double_list(void *data, size_t dsize)
{
	t_dnode	*new;

	if (!(new = ft_memalloc(sizeof(t_dnode))))
		return (NULL);
	new->data = data;
	new->d_size = dsize;
	new->next = NULL;
    new->prev = NULL;
	return (new);
}