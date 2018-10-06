/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rbtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:52 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/05 18:29:03 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_malloc.h"
// #include <assert.h>

//#define BROTHER right_son->parent->right
//#define	PARENTT right_son->parent

//void	repair_tree(t_rbnode *right_son)
//{
//	char	parent_color;
//	char	son_color;
//
//	if (!right_son || !PARENTT)
//		return ;
//	if (BROTHER->color_free & RED)
//	{
//		parent_color = PARENTT->color_free & RED ? RED : BLACK;
//		son_color = BROTHER->color_free & RED ? RED : BLACK;
//		PARENTT->color_free |= son_color;
//		PARENTT->color_free &= (son_color | FREE | USED);
//		BROTHER->color_free |= parent_color;
//		BROTHER->color_free &= (parent_color | FREE | USED);
//		rotate_left(PARENTT);
//	}
//	if (BROTHER->color_free & BLACK && (!BROTHER->left || BROTHER->left->color_free & BLACK) && (!BROTHER->right || BROTHER->right->color_free & BLACK))
//	{
//		BROTHER->color_free |= RED;
//		BROTHER->color_free |= (RED | FREE | USED);
//		PARENTT->color_free |= BLACK;
//		if (right_son->color_free & RED)
//			right_son->color_free &= (RED | USED | FREE);
//		repair_tree(PARENTT);
//	}
//	if (BROTHER->color_free & BLACK && (BROTHER->left->color_free & RED) && (BROTHER->right || BROTHER->right->color_free & BLACK))
//	{
//		parent_color = BROTHER->color_free & RED ? RED : BLACK;
//		son_color = BROTHER->left->color_free & RED ? RED : BLACK;
//		BROTHER->color_free |= son_color;
//		BROTHER->color_free &= (son_color | FREE | USED);
//		BROTHER->left->color_free |= parent_color;
//		BROTHER->color_free &= (parent_color | FREE | USED);
//		rotate_right(BROTHER);
//	}
//	if (BROTHER->color_free & BLACK && BROTHER->right->color_free & RED)
//	{
//		parent_color = PARENTT->color_free & RED ? RED : BLACK;
//		BROTHER->color_free |= parent_color;
//		BROTHER->color_free &= (parent_color | FREE | USED);
//		PARENTT->color_free |= BLACK;
//		PARENTT->color_free &= (BLACK | FREE | USED);
//		rotate_left(PARENTT);
//		if (PARENTT->parent->right)
//		{
//			PARENTT->parent->right->color_free |= BLACK;
//			PARENTT->parent->right->color_free &= (BLACK | FREE | USED);
//		}
//		if (right_son->color_free & RED)
//			right_son->color_free &= (RED | USED | FREE);
//	}
//}

// void	repair_tree(t_rbnode *to_fix)
// {
// 	t_rbnode	*idk;

// 	while (to_fix != g_tags_tree && to_fix->color_free & BLACK)
// 	{
// 		if (to_fix == to_fix->parent->left)
// 		{
			
// 			idk = to_fix->parent->right;
// 			assert(idk);
// //			printf("repair1 %p\n", idk);
// 			if (idk->color_free & RED)
// 			{
// 				idk->color_free = (BLACK | FREE);
// 				to_fix->parent->color_free = (RED | FREE);
// 				rotate_left(to_fix->parent);
// 				idk = to_fix->parent->right;
// 			}
// //			printf("l: %p | r: %p\n", idk->left, idk->right);
// 			if (idk->left && idk->left->color_free & BLACK && idk->right && idk->right->color_free & BLACK)
// 			{
// //				printf("1\n");
// 				idk->color_free = (RED | FREE);
// 				to_fix = to_fix->parent;
// 			}
// 			else if (idk->right && idk->right->color_free & BLACK)
// 			{
// //				printf("hi2\n");
// 				if (idk->left)
// 					idk->left->color_free = (BLACK | FREE);
// 				idk->color_free = (RED | FREE);
// //				printf("hi2\n");
// 				rotate_right(idk);
// //				printf("hi2\n");
// 				idk = to_fix->parent->right;
// 			}
// //			printf("hi\n");
// 			idk->color_free = ((to_fix->parent->color_free & RED ? RED : BLACK) | FREE);
// 			to_fix->parent->color_free = (BLACK | FREE);
// 			if (idk->right) idk->right->color_free = (BLACK | FREE);
// 			rotate_left(to_fix->parent);
// 			to_fix = g_tags_tree;
// 		}
// 		else
// 		{
// //			printf("repair2 %p\n", idk);
// 			idk = to_fix->parent->left;
// 			if (idk->color_free & RED)
// 			{
// 				idk->color_free = (BLACK | FREE);
// 				to_fix->parent->color_free = (RED | FREE);
// 				rotate_right(to_fix->parent);
// 				idk = to_fix->parent->left;
// 			}
// 			if (idk->right && idk->right->color_free & BLACK && idk->left && idk->left->color_free & BLACK)
// 			{
// 				idk->color_free = (RED | FREE);
// 				to_fix = to_fix->parent;
// 			}
// 			else if (idk->left && idk->left->color_free & BLACK)
// 			{
// 				if (idk->right)
// 					idk->right->color_free = (BLACK | FREE);
// 				idk->color_free = (RED | FREE);
// 				rotate_left(idk);
// 				idk = to_fix->parent->left;
// 			}
// 			idk->color_free = ((to_fix->parent->color_free & RED ? RED : BLACK) | FREE);
// 			to_fix->parent->color_free = (BLACK | FREE);
// 			if (idk->left) idk->left->color_free = (BLACK | FREE);
// 			rotate_right(to_fix->parent);
// 			to_fix = g_tags_tree;
// 		}
// 	}
// 	to_fix->color_free = (BLACK | FREE);
// }

// void	transplant(t_rbnode *to_delete, t_rbnode *to_replace)
// {
// 	if (!to_delete->parent)
// 		g_tags_tree = to_replace;
// 	else if (to_delete->parent->left == to_delete)
// 		to_delete->parent->left = to_replace;
// 	else
// 		to_delete->parent->right = to_replace;
// 	if (to_replace)
// 		to_replace->parent = to_delete->parent;
// }



// t_rbnode	*delete_two_children(t_rbnode *to_delete, char *orgcolor)
// {
// 	t_rbnode	*to_replace;
// 	t_rbnode	*x;
// 	char	color;
	
// //	printf("deletion: 3rd case\n");
// 	to_replace = to_delete->right;
// //	printf("1\n");
// 	while (to_replace->left)
// 		to_replace = to_replace->left;
// //	printf("2\n");
// 	*orgcolor = to_replace->color_free & RED ? RED : BLACK;
// //	printf("3\n");
// 	x = to_replace->right;
// //	printf("4 %p %p\n", to_replace, x);
// 	if (x && to_replace->parent == to_delete)
// 		x->parent = to_replace;
// 	else if (to_replace->right)
// 	{
// 		transplant(to_replace, to_replace->right);
// 		to_replace->right = to_delete->right;
// 		to_replace->right->parent = to_replace;
// 	}
// //	printf("5\n");
// 	transplant(to_delete, to_replace);
// 	to_replace->left = to_delete->left;
// 	to_replace->left->parent = to_replace;
// 	color = to_delete->color_free & RED ? RED : BLACK;
// 	to_replace->color_free = (color | FREE);
// 	return (x);
// }

// void	deletion(t_rbnode *to_delete)
// {
// 	t_rbnode	*x = NULL;
// 	char	orgcolor;

// 	orgcolor = to_delete->color_free;
// 	if (!to_delete->left && !to_delete->right)
// 	{
// 		printf("deletion: 1st case\n");
// 		if (!to_delete->parent)
// 			g_tags_tree = NULL;
// 		else if (to_delete->parent->right == to_delete)
// 			to_delete->parent->right = NULL;
// 		else
// 			to_delete->parent->left = NULL;
// 	}
// 	else if (!to_delete->left && to_delete->right)
// 	{
// 		printf("deletion: 2nd case 1\n");
// 		x = to_delete->right;
// 		transplant(to_delete, to_delete->right);
// 	}
// 	else if (to_delete->left && !to_delete->right)
// 	{
// 		printf("deletion: 2nd case 2\n");
// 		x = to_delete->left;
// 		transplant(to_delete, to_delete->left);
// 	}
// 	else
// 		x = delete_two_children(to_delete, &orgcolor);
// 	if (orgcolor & BLACK && x != NULL)
// 		repair_tree(x);
// }

