/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_repair_rbtree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:41:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/05 18:31:21 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

/*
**	------------------------ Insertion repair cases ---------------------------
*/
static void	insert_repair_case1(t_rbtree *node)
{
	if (!NPARENT)
		node->color = RBBLACK;
}

static void	insert_repair_case3(t_rbtree *node)
{
	NPARENT->color = RBBLACK;
	if (node->parent == NGRANDPA->left && NUNCLE_RIGHT)
		NUNCLE_RIGHT->color = RBBLACK;
	else if (node->parent == NGRANDPA->right && NUNCLE_LEFT)
		NUNCLE_LEFT->color = RBBLACK;
	NGRANDPA->color = RBRED;
	ft_insert_repair_tree(NGRANDPA);
}

static void	insert_repair_case4(t_rbtree *node)
{
	t_rbtree *p = NPARENT;
	t_rbtree *g = NGRANDPA;

	if (g && g->left && node == g->left->right)
	{
		ft_rotate_left_rbtree(p);
		node = node->left;
	}
	else if (g && g->right && node == g->right->left)
	{
		ft_rotate_right_rbtree(p);
		node = node->right; 
	}
	node == NPARENT->left ? ft_rotate_right_rbtree(g) : ft_rotate_left_rbtree(g);
	NPARENT->color = RBBLACK;
	if (g)
		g->color = RBRED;
}

/*
**	-------------------- Insertion repair starts here ----------------------
*/
void	ft_insert_repair_tree(t_rbtree *node)
{
	if (!NPARENT)
		insert_repair_case1(node);
	else if (NPARENT->color == RBBLACK)
		return ;
	else if (NGRANDPA && ((NUNCLE_LEFT && NUNCLE_LEFT != NPARENT && NUNCLE_LEFT->color & RBRED)
			|| (NUNCLE_RIGHT && NUNCLE_RIGHT != NPARENT && NUNCLE_RIGHT->color & RBRED)))
		insert_repair_case3(node);
	else
		insert_repair_case4(node);
}
