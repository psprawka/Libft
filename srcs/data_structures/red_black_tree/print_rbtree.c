/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rbtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:09:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 13:09:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_rbtree.h"

/*
**	I didnt code those functions, but I need them now, but I'll code it later.
*/


typedef struct	s_rbdata
{
	int		size;
	// int8_t	if_free;
}				t_rbdata;

// ------------------------- PRINT TREE	------------------------------

typedef struct asciinode_struct asciinode;

struct asciinode_struct
{
	asciinode * left, * right;

	//length of the edge from this node to its children
	int edge_length;

	int height;

	int lablen;

	//-1=I am left, 0=I am root, 1=right
	int parent_dir;

	//max supported unit32 in dec, 10 digits max
	char label[11];
};

#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1<<20)

//adjust gap between left and right nodes
int gap = 3;

//used for printing next node in the same level,
//this is the x coordinate of the next char printed
int print_next;

int MIN (int X, int Y)
{
	return ((X) < (Y)) ? (X) : (Y);
}

int MAX (int X, int Y)
{
	return ((X) > (Y)) ? (X) : (Y);
}

asciinode * build_ascii_tree_recursive(t_rbtree * t)
{
	asciinode * node;

	if (t == NULL) return NULL;

	node = malloc(sizeof(asciinode));
	node->left = build_ascii_tree_recursive(t->left);
	node->right = build_ascii_tree_recursive(t->right);

	if (node->left != NULL)
	{
		node->left->parent_dir = -1;
	}

	if (node->right != NULL)
	{
		node->right->parent_dir = 1;
	}
	// sprintf(node->label, "%d", ((t_rbdata *)t->data)->size);
	sprintf(node->label, "%s%d%s", t->color == RBBLACK ? NORMAL : RED, ((t_rbdata *)t->data)->size, NORMAL);
	node->lablen = ft_strlen(node->label) - ft_strlen(t->color == RBBLACK ? NORMAL : RED) - ft_strlen(NORMAL);

	return node;
}


//Copy the tree into the ascii node structre
asciinode * build_ascii_tree(t_rbtree * t)
{
	asciinode *node;
	if (t == NULL) return NULL;
	node = build_ascii_tree_recursive(t);
	node->parent_dir = 0;
	return node;
}

//Free all the nodes of the given tree
void free_ascii_tree(asciinode *node)
{
	if (node == NULL) return;
	free_ascii_tree(node->left);
	free_ascii_tree(node->right);
	free(node);
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode *node, int x, int y)
{
	int i, isleft;
	if (node == NULL) return;
	isleft = (node->parent_dir == -1);
	lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
	if (node->left != NULL)
	{
		for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
		{
			lprofile[y+i] = MIN(lprofile[y+i], x-i);
		}
	}
	compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
	compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(asciinode *node, int x, int y)
{
	int i, notleft;
	if (node == NULL) return;
	notleft = (node->parent_dir != -1);
	rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
	if (node->right != NULL)
	{
		for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
		{
			rprofile[y+i] = MAX(rprofile[y+i], x+i);
		}
	}
	compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
	compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

//This function fills in the edge_length and
//height fields of the specified tree
void compute_edge_lengths(asciinode *node)
{
	int h, hmin, i, delta;
	if (node == NULL) return;
	compute_edge_lengths(node->left);
	compute_edge_lengths(node->right);

	/* first fill in the edge_length of node */
	if (node->right == NULL && node->left == NULL)
	{
		node->edge_length = 0;
	}
	else
	{
		if (node->left != NULL)
		{
			for (i=0; i<node->left->height && i < MAX_HEIGHT; i++)
			{
				rprofile[i] = -INFINITY;
			}
			compute_rprofile(node->left, 0, 0);
			hmin = node->left->height;
		}
		else
		{
			hmin = 0;
		}
		if (node->right != NULL)
		{
			for (i=0; i<node->right->height && i < MAX_HEIGHT; i++)
			{
				lprofile[i] = INFINITY;
			}
			compute_lprofile(node->right, 0, 0);
			hmin = MIN(node->right->height, hmin);
		}
		else
		{
			hmin = 0;
		}
		delta = 4;
		for (i=0; i<hmin; i++)
		{
			delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
		}

		//If the node has two children of height 1, then we allow the
		//two leaves to be within 1, instead of 2
		if (((node->left != NULL && node->left->height == 1) ||
					(node->right != NULL && node->right->height == 1))&&delta>4)
		{
			delta--;
		}

		node->edge_length = ((delta+1)/2) - 1;
	}

	//now fill in the height of node
	h = 1;
	if (node->left != NULL)
	{
		h = MAX(node->left->height + node->edge_length + 1, h);
	}
	if (node->right != NULL)
	{
		h = MAX(node->right->height + node->edge_length + 1, h);
	}
	node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level)
{
	int i, isleft;
	if (node == NULL) return;
	isleft = (node->parent_dir == -1);
	if (level == 0)
	{
		for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
		{
			printf(" ");
		}
		print_next += i;
		printf("%s", node->label);
		print_next += node->lablen;
	}
	else if (node->edge_length >= level)
	{
		if (node->left != NULL)
		{
			for (i=0; i<(x-print_next-(level)); i++)
			{
				printf(" ");
			}
			print_next += i;
			printf("/");
			print_next++;
		}
		if (node->right != NULL)
		{
			for (i=0; i<(x-print_next+(level)); i++)
			{
				printf(" ");
			}
			print_next += i;
			printf("\\");
			print_next++;
		}
	}
	else
	{
		print_level(node->left,
				x-node->edge_length-1,
				level-node->edge_length-1);
		print_level(node->right,
				x+node->edge_length+1,
				level-node->edge_length-1);
	}
}

//prints ascii tree for given Tree structure
void	ft_print_rbtree(t_rbtree *node)
{
	asciinode *proot;
	int xmin, i;
	if (node == NULL) return;
	proot = build_ascii_tree(node);
	compute_edge_lengths(proot);
	for (i=0; i<proot->height && i < MAX_HEIGHT; i++)
	{
		lprofile[i] = INFINITY;
	}
	compute_lprofile(proot, 0, 0);
	xmin = 0;
	for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
	{
		xmin = MIN(xmin, lprofile[i]);
	}
	for (i = 0; i < proot->height; i++)
	{
		print_next = 0;
		print_level(proot, -xmin, i);
		printf("\n");
	}
	if (proot->height >= MAX_HEIGHT)
	{
		printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
	}
	free_ascii_tree(proot);
}
