/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rbtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:51:00 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/05 18:31:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

t_rbtree	*ft_create_rbtree(void *data)
{
	t_rbtree *new;

	new = (t_rbtree *)malloc(sizeof(t_rbtree));
	ft_bzero(new, sizeof(t_rbtree));
	new->data = data;
	new->color = RBRED;
	return (new);
}
