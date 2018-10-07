/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_repair_rbtree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:35:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/06 20:12:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

static void	delete_repair_case1_2(t_rbtree *node, char rotation)
{
	int			tmp_color;
	
	rotation == 'L' ? ft_rotate_left_rbtree(NPARENT) : ft_rotate_right_rbtree(NPARENT);
	if (NGRANDPA)
	{
		tmp_color = NPARENT->color;
		NPARENT->color = NGRANDPA->color;
		NGRANDPA->color = tmp_color;
	}
	// *node_ref = node->parent;
}

static void delete_repair_case3_4(t_rbtree *node, t_rbtree *sibling)
{
	if (node->color & DB_RBBLACK)
		node->color &= (~DB_RBBLACK);
	else
		node->color = RBRED;
		
	if (sibling->color & DB_RBBLACK)
		sibling->color &= (~DB_RBBLACK);
	else
		sibling->color = RBRED;
	
	if (NPARENT && NPARENT->color & RBBLACK)
		NPARENT->color |= DB_RBBLACK;
	else if (NPARENT)
		NPARENT->color |= RBBLACK;
}

static void delete_repair_case5_6(t_rbtree *node, t_rbtree *sibling, char rotation)
{
	t_rbtree	*new_sibling;
	int			tmp_color;

	rotation == 'L' ? ft_rotate_left_rbtree(sibling) : ft_rotate_right_rbtree(sibling);
	if (!(new_sibling = ft_get_sibling_rbtree(node)))
		return ;
		
	tmp_color = new_sibling->color;
	new_sibling->color = sibling->color;
	sibling->color = tmp_color;
}

static void delete_repair_case7_8(t_rbtree *node, char rotation)
{
	t_rbtree	*uncle;
	int			tmp_color;

	rotation == 'L' ? ft_rotate_left_rbtree(NPARENT) : ft_rotate_right_rbtree(NPARENT);
	if (NGRANDPA)
	{
		tmp_color = NPARENT->color;
		NPARENT->color = NGRANDPA->color;
		NGRANDPA->color = tmp_color;
	}
	if (NPARENT->color & RBBLACK)
		NPARENT->color |= DB_RBBLACK;
	else
		NPARENT->color |= RBBLACK;
	if (node->color & DB_RBBLACK)
		node->color &= (~DB_RBBLACK);
	else
		node->color = RBRED;
	if (!(uncle = ft_get_uncle_rbtree(node)))
		return ;
	uncle->color = RBBLACK;
}

void	ft_delete_repair_rbtree(t_rbtree *node)
{
	t_rbtree	*sibling;
	t_rbtree	*left_child;
	t_rbtree	*right_child;
	char		lr_sibling;

	if (!(sibling = ft_get_sibling_rbtree(node)))
		return ;
	lr_sibling = (sibling == sibling->parent->left) ? 'L' : 'R'; 
	
	right_child = sibling->right;
	left_child = sibling->left;
	
	if (sibling->color & RBRED)										/* CASE 1 and CASE 1 SYMMETRIC */
		delete_repair_case1_2(node, lr_sibling);
	if (sibling->color & RBBLACK && left_child && left_child->color & RBBLACK && right_child && right_child->color & RBBLACK)
		delete_repair_case3_4(node, sibling);
	if (sibling->color & RBBLACK && left_child && left_child->color & RBRED && right_child && right_child->color & RBBLACK)
		delete_repair_case5_6(node, sibling, lr_sibling);
	if (sibling->color & RBBLACK && right_child && right_child->color & RBRED)
		delete_repair_case7_8(node, lr_sibling);
}
