/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rbtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:52 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 13:50:14 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

typedef struct	s_rbdata
{
	int		size;
	// int8_t	if_free;
}				t_rbdata;

static void	delete_case1_2(t_rbtree *to_delete, t_rbtree *replace)
{
	printf("DELETE CASE1_2\n");
	if (to_delete->parent && to_delete->parent->left == to_delete)
		to_delete->parent->left = replace;
	else if (to_delete->parent && to_delete->parent->right == to_delete)
		to_delete->parent->right = replace;
	if (replace)
	{
		replace->parent = to_delete->parent;
		replace->color = RBBLACK;
	}
}

static void	delete_case3(t_rbtree *to_delete, t_rbtree *successor)
{
	printf("DELETE CASE3\n");
	if (to_delete->parent && to_delete->parent->left == to_delete)
		to_delete->parent->left = successor;
	else if (to_delete->parent && to_delete->parent->right == to_delete)
		to_delete->parent->right = successor;
	successor->parent = to_delete->parent;
	successor->left = to_delete->left;
	successor->left->parent = successor;

	if (successor->right)
	{
		if (successor->right->color & RBBLACK)
			successor->right->color |= DB_RBBLACK; //successor->right->color = DB_RBBLACK;
		else
			successor->right->color = RBBLACK;
	}
	successor->color = to_delete->color;
}

static void	delete_case4(t_rbtree *to_delete, t_rbtree *successor)
{
	printf("DELETE CASE4\n");
	successor->parent->left = successor->right;							/* CONNECTING CHILD */
	if (successor->right)
		successor->right->parent = successor->parent;
		
	successor->left = to_delete->left;									/* CONNECTING LEFT */
	if (successor->left)
		successor->left->parent = successor;
		
	successor->right = to_delete->right;								/* CONNECTING RIGHT */
	if (successor->right)
		successor->right->parent = successor;
		
	if (to_delete->parent && to_delete->parent->left == to_delete)		/* CONNECTING PARENT */
		to_delete->parent->left = successor;
	else if (to_delete->parent && to_delete->parent->right == to_delete)
		to_delete->parent->right = successor;
	successor->parent = to_delete->parent;

	if (successor->color & RBBLACK && successor->right)					/* RECOLORING */
	{
		if (successor->right->color & RBBLACK)
			successor->right->color |= DB_RBBLACK; //successor->right->color = DB_RBBLACK;
		else
			successor->right->color |= RBBLACK;
	}
	successor->color = to_delete->color;
}


void	ft_delete_rbtree(t_rbtree **root, t_rbtree *to_delete, void (*free_data)(void *))
{
	t_rbtree	*to_replace;
	
	if (!to_delete)
		return ;
	// printf("meow\n");
	if (!to_delete->left || !to_delete->right)
	{
		printf("FT_DELETE_RBTREE1\n");
		to_replace = to_delete->left ? to_delete->left : to_delete->right;
		// printf("FT_DELETE_RBTREE2\n");
		delete_case1_2(to_delete, to_replace);
		// printf("FT_DELETE_RBTREE3\n");
	}
	else
	{
		printf("FT_DELETE_RBTREE2 -> LOOKING FOR SUCCESSOR\n");
		to_replace = ft_search_successor_rbtree(to_delete);
		if (to_replace && to_replace == to_delete->right)
			delete_case3(to_delete, to_replace);
		else
			delete_case4(to_delete, to_replace);
	}
	// printf("I AM AFTER DELETEION CASES IN FT_DELETE_RBTREE\n");
	if (*root == to_delete)
		*root = to_replace;
	// if (to_replace->color & DB_RBBLACK)
	printf("\n***********************************************\n");
	printf("REPEARING TREE -> %d\n", to_delete ? ((t_rbdata *)to_delete->data)->size : -1);
	ft_print_rbtree(*root);
	printf("***********************************************\n\n");
	// ft_delete_repair_rbtree(to_replace);
	ft_delete_repair_rbtree(to_delete);
	free_data(to_delete->data);
	free(to_delete);
}

/*
**	if (!to_delete->left)
**	{
**		to_replace = to_delete->right;
**		delete_case1_2(to_delete, to_delete->right);
**	}
**	else if (!to_delete->right)
**	{
**		to_replace = to_delete->left;
**		delete_case1_2(to_delete, to_delete->left);
**	}
*/
