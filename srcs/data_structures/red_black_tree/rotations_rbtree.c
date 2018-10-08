/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_rbtree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:56:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/05 18:31:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

void	ft_rotate_left_rbtree(t_rbtree *node)
{
	t_rbtree	*new_head;

	if (!node || !node->right)
		return ;	
	new_head = node->right;
	node->right = new_head->left;
	if (new_head->left)
		new_head->left->parent = node;
	new_head->left = node;
	new_head->parent = node->parent;
	node->parent = new_head;
	if (new_head->parent && new_head->parent->left == node)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == node)
		new_head->parent->right = new_head;
}

void	ft_rotate_right_rbtree(t_rbtree *node)
{
	t_rbtree *new_head;

	if (!node || !node->left)
		return ;
	new_head = node->left;
	node->left = new_head->right;
	if (new_head->right)
		new_head->right->parent = node;
	new_head->right = node;
	new_head->parent = node->parent;
	node->parent = new_head;
	if (new_head->parent && new_head->parent->left == node)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == node)
		new_head->parent->right = new_head;
}
