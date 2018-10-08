/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_rbtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/06 13:27:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

/*
**	Insertion:
**	Inseriton is responsible for adding a node to a tree, then validate it based
**	on red black tree's rules. If tree is empty, assing a node to a root.
**	Otherwise find postion to be assigned, thus parent node and add son.
**	Validate insertion and set root to the currect root.
*/

void	ft_insert_rbtree(t_rbtree **root, t_rbtree *to_insert, int (*fct)(void *, void *))
{
	t_rbtree	*tptr;
	t_rbtree	*parent;
	
	if (!root || !(*root))
		*root = to_insert;
	else
	{
		tptr = *root;
		parent = ft_search_rbtree(*root, to_insert, fct);
		if (fct(parent->data, to_insert->data))
			parent->left = to_insert;
		else
			parent->right = to_insert;
		to_insert->parent = parent;
	}
	ft_insert_repair_tree(to_insert);
	while ((*root)->parent)
 		*root = (*root)->parent;
}