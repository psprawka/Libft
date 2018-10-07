/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_family_rbtree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 11:59:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

t_rbtree	*ft_get_sibling_rbtree(t_rbtree *node)
{
	if (!node || !NPARENT)
		return (NULL);
	printf("THERE WILL BE A SIBLING\n");
	return (NPARENT->left == node ? NPARENT->right : NPARENT->left);
}

t_rbtree	*ft_get_uncle_rbtree(t_rbtree *node)
{
	if (!node)
		return (NULL);
	return (ft_get_sibling_rbtree(NPARENT));
}