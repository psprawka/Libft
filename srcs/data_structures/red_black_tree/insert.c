/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/04 21:15:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	Description of functions insertion_case4 and valid_insertion avaliable here
**	https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
**	However in function valid_insertion I examine only three cases:
**		-> 1. Current node is a root of red back tree.
**		-> 3. Parent is red and uncle is red.
**		-> 4. Parent is red and uncle is black.
**	I skip case 2 (Parent is black) because in this case nothing happens - it's
**	goal was to prevent stepping into next if statement (if ... else if). Since
**	my if statement is more detailed than on website above, i don't need it.
*/

/*	Find_position:
**	this func traverses through a tree, finds and returns a parent node for new
**	son. Variable 'size' is son's size. If tree is empty returns null.
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct	s_rbtree
{
	void	*data;
	int8_t	color;
	struct	s_rbtree *parent;
	struct	s_rbtree *left;
	struct	s_rbtree *right;

}				t_rbtree;

typedef struct	s_rbdata
{
	int		size;
	int8_t	if_free;
}				t_rbdata;	

# define NPARENT		new->parent
# define NGRANDPA		NPARENT->parent
# define NUNCLE_LEFT	NGRANDPA->left
# define NUNCLE_RIGHT	NGRANDPA->right

# define PARENT			root->parent
# define GRANDPA		PARENT->parent
# define UNCLE_LEFT		GRANDPA->left
# define UNCLE_RIGHT	GRANDPA->right

# define RBBLACK	1
# define RBRED		2

# define NORMAL			"\x1B[0m"
# define RED			"\x1B[31m"


// t_rbtree	*find_position(t_rbtree *root, size_t size)
// {
// 	t_rbdata	*pdata;
// 	t_rbtree	*tptr;
	
// 	tptr = root;
// 	while (tptr)
// 	{
// 		if (tptr->size > size)
// 		{
// 			if (!tptr->left)
// 				return (tptr);
// 			tptr = tptr->left;
// 		}
// 		else
// 		{
// 			if (!tptr->right)
// 				return (tptr);
// 			tptr = tptr->right;
// 		}
// 	}
// 	return (tptr);
// }

// /*
// **	Find position traverses through red black tree and finds parent node
// **	for a given size

void	insert_repair_tree(t_rbtree *new);
void	insert_case4step2(t_rbtree *new);

//--------------------------------- CREATE -----------------------------------

t_rbtree	*create_rbtree(int size)
{
	t_rbtree *new;

	new = (t_rbtree *)malloc(sizeof(t_rbtree));
	bzero(new, sizeof(t_rbtree));
	new->data = (t_rbdata *)malloc(sizeof(t_rbdata));
	new->color = RBRED;
	((t_rbdata *)new->data)->size = size;
	
	return (new);
 }
 

//-------------------------------- ROTATIONS ----------------------------------

void	rotate_left(t_rbtree *tag)
{
	t_rbtree *new_head;

	if (!tag)
		return ;
	new_head = tag->right;
	if (!new_head)
		return ;
	tag->right = new_head->left;
	if (new_head->left)
		new_head->left->parent = tag;
	new_head->left = tag;
	new_head->parent = tag->parent;
	tag->parent = new_head;
	if (new_head->parent && new_head->parent->left == tag)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == tag)
		new_head->parent->right = new_head;
}

void	rotate_right(t_rbtree *tag)
{
	t_rbtree *new_head;

	if (!tag)
		return ;
	new_head = tag->left;
	if (!new_head)
		return ;
	// printf("1\n");
	tag->left = new_head->right;
	if (new_head->right)
		new_head->right->parent = tag;
	// printf("2\n");
	new_head->right = tag;
	new_head->parent = tag->parent;
	// printf("3\n");
	tag->parent = new_head;
	if (new_head->parent && new_head->parent->left == tag)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == tag)
		new_head->parent->right = new_head;
}


//----------------------------------- TOOLS -------------------------------------

t_rbtree	*find_position(t_rbtree *root, t_rbtree *new, int (*fct)(void *, void *))
{
	t_rbtree	*tptr;
	
	tptr = root;
	while (tptr)
	{
		if (fct(tptr->data, new->data))
		{
			if (!tptr->left)
				return (tptr);
			tptr = tptr->left;
		}
		else
		{
			if (!tptr->right)
				return (tptr);
			tptr = tptr->right;
		}
	}
	return (tptr);
}

#define COUNT 10

void print2DUtil(t_rbtree *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
	
	t_rbdata	*tdata;
	tdata = (t_rbdata *)root->data;
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s%d%s\n", root->color == RBRED ? RED : NORMAL, tdata->size, NORMAL);
    print2DUtil(root->left, space);
}
 
void print2D(t_rbtree *root)
{
	// printf("Before print\n");
	print2DUtil(root, 0);
	// printf("After print\n");
}


//--------------------------------- INSERTION -----------------------------------'

void	insert_case1(t_rbtree *new)
{
	if (!NPARENT)
		new->color = RBBLACK;
}

void insert_case2(t_rbtree *new)
{
	return; /* Do nothing since tree is still valid */
}

void insert_case3(t_rbtree *new)
{
	NPARENT->color = RBBLACK;
	if (new->parent == NGRANDPA->left && NUNCLE_RIGHT)
		NUNCLE_RIGHT->color = RBBLACK;
	else if (new->parent == NGRANDPA->right && NUNCLE_LEFT)
		NUNCLE_LEFT->color = RBBLACK;
	NGRANDPA->color = RBRED;
	insert_repair_tree(NGRANDPA);
}

void insert_case4(t_rbtree *new)
{
	t_rbtree *p = NPARENT;
	t_rbtree *g = NGRANDPA;

	if (g && new == g->left->right)
	{
		rotate_left(p);
		new = new->left;
	}
	else if (g && new == g->right->left)
	{
		rotate_right(p);
		new = new->right; 
	}
	
	new == p->left ? rotate_right(g) : rotate_left(g);
	p->color = RBBLACK;
	if (g)
		g->color = RBRED;
}

void	insert_repair_tree(t_rbtree *new)
{
	if (!NPARENT)
		insert_case1(new);
	else if (NPARENT->color == RBBLACK)
		insert_case2(new);
	else if (NGRANDPA && ((NUNCLE_LEFT && NUNCLE_LEFT != NPARENT && NUNCLE_LEFT->color & RBRED)
			|| (NUNCLE_RIGHT && NUNCLE_RIGHT != NPARENT && NUNCLE_RIGHT->color & RBRED)))
		insert_case3(new);
	else
		insert_case4(new);
}

/*	Insertion:
**	Inseriton is responsible for adding a node to a tree, then validate it based
**	on red black tree's rules. If tree is empty, assing a node. Otherwise find
**	postion to be assigned, thus parent node and add son. Validate insertion.
*/

void	insert_rbtree(t_rbtree **root, t_rbtree *to_insert, int (*fct)(void *, void *))
{
	t_rbtree	*tptr;
	t_rbtree	*parent;
	
	if (!root || !(*root))
		*root = to_insert;
	else
	{
		tptr = *root;
		parent = find_position(*root, to_insert, fct);
		if (fct(parent->data, to_insert->data))
			parent->left = to_insert;
		else
			parent->right = to_insert;
		to_insert->parent = parent;
	}
	
	///////////////////////////////////////////////////
	// printf("INSERTED\n");
	// printf("\n\n\n");
	// print2D(root);
	// // printf("\n\n\n");
	// printf("COLOR: [%d]\n",  to_insert->color);
	//////////////////////////////////////////////////
	
	insert_repair_tree(to_insert);
}




int		cmp(void *n1, void *n2)
{
	t_rbdata	*n1data;
	t_rbdata	*n2data;

	n1data = ((t_rbtree *)n1)->data;
	n2data = ((t_rbtree *)n2)->data;

	if (n1data->size > n2data->size)
		return (1);
	return (0);
}


int		main(int ac, char **av)
{
	int i = 1;
	t_rbtree	*root = NULL;
	t_rbtree	*to_insert;

	while (i < ac)
	{
		to_insert = create_rbtree(atoi(av[i]));
		printf("Created %s\n", av[i]);
		i++;
		insert_rbtree(&root, to_insert, &cmp);
		printf("Inserted %s\n", av[i]);
	}
	
	print2D(root);
	return (0);
}