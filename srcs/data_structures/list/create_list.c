/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 04:24:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:27:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_list(int key)
{
	t_list *new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->key = key;
	new->next = NULL;
	return (new);
}