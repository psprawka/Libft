/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 00:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/12/05 00:27:05 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree     *ft_create_tree(void *data)
{
	t_tree *new;

	if (!(new = (t_rbtree *)malloc(sizeof(t_rbtree))))
        return (NULL);
	ft_bzero(new, sizeof(t_rbtree));
	new->data = data;
	return (new);
}