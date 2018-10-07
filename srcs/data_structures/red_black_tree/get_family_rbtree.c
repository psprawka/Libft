/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_family_rbtree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/06 20:00:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

t_rbtree	*ft_get_sibling_rbtree(t_rbtree *node)
{
	if (!node || !NPARENT)
		return (NULL);
	return (NGRANDPA->left == node ? NGRANDPA->right : NGRANDPA->left);
}

t_rbtree	*ft_get_uncle_rbtree(t_rbtree *node)
{
	if (!node)
		return (NULL);
	return (ft_get_sibling_rbtree(NPARENT));
}