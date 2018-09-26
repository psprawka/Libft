/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:50:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/04 22:34:37 by psprawka         ###   ########.fr       */
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

t_rbtree	*find_position(t_rbtree *root, int size)
{
	t_rbtree	*tptr;
	t_rbdata	*tdata;
	
	tptr = root;
	while (tptr)
	{
		tdata = (t_rbdata *)tptr->data;
		if (tdata->size > size)
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
	if (new == NGRANDPA->left)
		NUNCLE_RIGHT->color = RBBLACK;
	else 
		NUNCLE_LEFT->color = RBBLACK;
	NGRANDPA->color = RBRED;
	insert_repair_tree(NGRANDPA);
}

void insert_case4(t_rbtree *new)
{
	t_rbtree *p = NPARENT;
	t_rbtree *g = NGRANDPA;

	if (new == g->left->right)
	{
		rotate_left(p);
		new = new->left;
	}
	else if (new == g->right->left)
	{
		rotate_right(p);
		new = new->right; 
	}
	insert_case4step2(new);
}

void insert_case4step2(t_rbtree *new)
{
	t_rbtree *p = NPARENT;
	t_rbtree *g = NGRANDPA;

	if (new == p->left)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = RBBLACK;
	g->color = RBRED;
}


void	insert_repair_tree(t_rbtree *new)
{
	if (!NPARENT)
		insert_case1(new);
	else if (NPARENT->color == RBBLACK)
		insert_case2(new);
	else if (NGRANDPA && ((NUNCLE_LEFT != NPARENT && NUNCLE_LEFT && NUNCLE_LEFT->color & RBRED)
			|| (NUNCLE_RIGHT && NUNCLE_RIGHT != NPARENT && NUNCLE_RIGHT->color & RBRED)))
		insert_case3(new);
	else
		insert_case4(new);
}

// (GRANDPA && (PARENT->color & RBRED) && ((UNCLE_LEFT != PARENT &&
// 			UNCLE_LEFT && UNCLE_LEFT->color & RBRED) || (UNCLE_RIGHT &&
// 			UNCLE_RIGHT != PARENT && UNCLE_RIGHT->color & RBRED)))
// void	insertion_case4(t_rbtree *root)
// {
// 	printf("INSERTION CASE 4 root: %p\n", root);
// 	if (GRANDPA->right && GRANDPA->right->left == root)
// 	{
// 		printf("case 1 beg\n");
// 		rotate_right(PARENT);
// 		root = root->right;
// 		printf("case 1 end\n");
// 	}
// 	else if (GRANDPA->left && GRANDPA->left->right == root)
// 	{
// 		printf("case 2 beg\n");
// 		rotate_left(PARENT);
// 		root = root->left;
// 		printf("case 2 end\n");
// 	}
// 	printf("IM HERE\n");
// 	root == PARENT->left ? rotate_right(GRANDPA) : rotate_left(GRANDPA);
// 	PARENT->color = RBBLACK;
// 	printf("IM HERE2\n");
// 	if (!PARENT->parent)
// 		root = PARENT;
// 	printf("IM HERE3\n");
// 	if (PARENT && PARENT->left != root)
// 	{
// 		printf("ONE\n");
// 		PARENT->left->color = RBRED;
// 		printf("ONE END");
// 	}
// 	else if (PARENT)
// 	{
// 		printf("TWO\n");
// 		PARENT->right->color = RBRED;
// 		printf("TWO END");
// 	}
// }

// void	valid_insertion(t_rbtree *root)
// {
// 	// printf("ENTERED INSERTION: ROOT %p %hd\n", root, ((t_rbdata *)root->data)->size);
// 	if (!PARENT)
// 	{
// 		root->color = RBBLACK;
// 		// printf("case 1\n");
// 	}
// 	else if (GRANDPA && (PARENT->color & RBRED) && ((UNCLE_LEFT != PARENT &&
// 			UNCLE_LEFT && UNCLE_LEFT->color & RBRED) || (UNCLE_RIGHT &&
// 			UNCLE_RIGHT != PARENT && UNCLE_RIGHT->color & RBRED)))
// 	{
// 		// printf("SECOND CASE\n");
// 		if (UNCLE_RIGHT)
// 			UNCLE_RIGHT->color = RBBLACK;
// 		if (UNCLE_LEFT)
// 			UNCLE_LEFT->color = RBBLACK;
// 		GRANDPA->color = RBRED;
// 		valid_insertion(GRANDPA);
// 	}
// 	else if (GRANDPA && (PARENT->color & RBRED))
// 	{
// 		// printf("CASE 4 before entering\n");
// 		insertion_case4(root);
// 	}
// }

/*	Insertion:
**	Inseriton is responsible for adding a node to a tree, then validate it based
**	on red black tree's rules. If tree is empty, assing a node. Otherwise find
**	postion to be assigned, thus parent node and add son. Validate insertion.
*/

t_rbtree	*insert_rbtree(t_rbtree *root, t_rbtree *to_insert)
{
	t_rbtree	*tptr;
	t_rbtree	*parent;
	t_rbdata	*tidata;
	t_rbdata	*pdata;
	
	tptr = root;
	if (tptr == NULL)
		root = to_insert;
	else
	{
		tidata = (t_rbdata *)to_insert->data;
		parent = find_position(root, tidata->size);
		pdata = (t_rbdata *)parent->data;
		
		if (pdata->size > tidata->size)
			parent->left = to_insert;
		else
			parent->right = to_insert;
		to_insert->parent = parent;
	}

	root = to_insert;
	while (to_insert->parent)
  		root = root->parent;
 	return root;

	// printf("INSERTED\n");
	// printf("\n\n\n");
	
	print2D(root);
	// printf("\n\n\n");
	printf("COLOR: [%d]\n",  to_insert->color);
	insert_repair_tree(to_insert);
}





int main(int ac, char **av)
{
	int i = 1;
	t_rbtree	*root = NULL;
	t_rbtree	*to_insert;

	while (i < ac)
	{
		to_insert = create_rbtree(atoi(av[i]));
		// printf("Created %s\n", av[i]);
		i++;
		root = insert_rbtree(root, to_insert);
	}
	
	print2D(root);
	return (0);
}