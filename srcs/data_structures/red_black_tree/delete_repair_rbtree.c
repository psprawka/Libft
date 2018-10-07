/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_repair_rbtree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:35:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 14:12:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

typedef struct	s_rbdata
{
	int		size;
	// int8_t	if_free;
}				t_rbdata;	

static void	delete_repair_case1_2(t_rbtree *node, char rotation)
{
	int			tmp_color;
	
	// printf("DELETE REPAIR 1\n");
	rotation == 'L' ? ft_rotate_left_rbtree(NPARENT) : ft_rotate_right_rbtree(NPARENT);
	// rotation == 'L' ? ft_rotate_right_rbtree(NPARENT) : ft_rotate_left_rbtree(NPARENT);
	if (NPARENT && NGRANDPA)
	{
		tmp_color = NPARENT->color;
		NPARENT->color = NGRANDPA->color;
		NGRANDPA->color = tmp_color;
	}
	// *node_ref = node->parent;
}

static void delete_repair_case3_4(t_rbtree *node, t_rbtree *sibling)
{
	// printf("DELETE REPAIR 2\n");
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
		NPARENT->color = RBBLACK;
}

static void delete_repair_case5_6(t_rbtree *node, t_rbtree *sibling, char rotation)
{
	t_rbtree	*new_sibling;
	int			tmp_color;

	// printf("DELETE REPAIR 3\n");
	rotation == 'L' ? ft_rotate_left_rbtree(sibling) : ft_rotate_right_rbtree(sibling);
	// rotation == 'L' ? ft_rotate_right_rbtree(sibling) : ft_rotate_left_rbtree(sibling);
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

	// printf("DELETE REPAIR 4, nparent? %p\n", node->parent);
	rotation == 'L' ? ft_rotate_left_rbtree(NPARENT) : ft_rotate_right_rbtree(NPARENT);
	// rotation == 'L' ? ft_rotate_right_rbtree(NPARENT) : ft_rotate_left_rbtree(NPARENT);
	// printf("DELETE REPAIR 4.1\n");
	if (NPARENT && NGRANDPA)
	{
		// printf("SWITCHING COLORS 4\n");
		tmp_color = NPARENT->color;
		NPARENT->color = NGRANDPA->color;
		NGRANDPA->color = tmp_color;
	}
	// printf("DELETE REPAIR 4.2\n");
	if (NPARENT && NPARENT->color & RBBLACK)
		NPARENT->color |= DB_RBBLACK;
	else if (NPARENT)
		NPARENT->color |= RBBLACK;
	// printf("DELETE REPAIR 4.3\n");
	if (node->color & DB_RBBLACK)
		node->color &= (~DB_RBBLACK);
	else
		node->color = RBRED;
	// printf("DELETE REPAIR 4.4\n");
	if (!(uncle = ft_get_uncle_rbtree(node)))
		return ;
	// printf("DELETE REPAIR 4.5\n");
	uncle->color = RBBLACK;
}

int		ft_delete_repair_rbtree(t_rbtree *node)
{
	t_rbtree	*sibling;
	t_rbtree	*left_child;
	t_rbtree	*right_child;
	char		lr_sibling;

	// printf("Start repairing... Searching fot sibling for a node %d\n", ((t_rbdata *)node->data)->size);
	if (!(sibling = ft_get_sibling_rbtree(node)))
		return (EXIT_FAILURE);
	// printf("Sibling found!n")
	lr_sibling = (sibling == sibling->parent->left) ? 'L' : 'R'; 
	// printf("Sibling found! %d\n", ((t_rbdata *)sibling->data)->size);
	right_child = sibling->right;
	left_child = sibling->left;
	
	if (sibling->color & RBRED)										/* CASE 1 and CASE 1 SYMMETRIC */
		delete_repair_case1_2(node, lr_sibling);
	if (sibling->color & RBBLACK && left_child && left_child->color & RBBLACK && right_child && right_child->color & RBBLACK)
		delete_repair_case3_4(node, sibling);
	if (sibling->color & RBBLACK && left_child && left_child->color & RBRED && right_child && right_child->color & RBBLACK)
		delete_repair_case5_6(node, sibling, lr_sibling);
	if (sibling->color & RBBLACK && left_child && left_child->color & RBBLACK && right_child && right_child->color & RBRED)
		delete_repair_case7_8(node, lr_sibling);
	return (EXIT_SUCCESS);
}
