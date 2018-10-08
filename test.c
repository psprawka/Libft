/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:20:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 13:24:24 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/libft.h"
#include "includes/libft_rbtree.h"
#include "string.h"
#include <stdio.h>

typedef struct	s_rbdata
{
	int		size;
	// int8_t	if_free;
}				t_rbdata;	

int		cmp(void *n1, void *n2)
{
	if (((t_rbdata *)n1)->size > ((t_rbdata *)n2)->size)
		return (1);
	return (0);
}

t_rbdata	*create_data(int size)
{
	t_rbdata *node;

	if (!(node = (t_rbdata *)malloc(sizeof(t_rbdata))))
		return (NULL);
	node->size = size;
	return (node);
}

void	free_data(void *data)
{
	data = NULL;
}

int		main(int ac, char **av)
{
	int i = 1;
	t_rbtree	*root = NULL;
	t_rbtree	*to_insert;
	t_rbtree	*to_delete = NULL;

	while (i < ac)
	{
		to_insert = ft_create_rbtree(create_data(atoi(av[i])));
		if (to_delete == NULL)
			to_delete = to_insert; 
		printf("Created %s\n", av[i]);
		ft_insert_rbtree(&root, to_insert, &cmp);
		printf("----------------------------------------------\n");
		ft_print_rbtree(root);
		printf("----------------------------------------------\n");
		printf("Inserted %s\n", av[i]);
		if (!(i % 4))
		{
			if (to_delete != root)
			{
				printf("\nDELETING %d...\n", ((t_rbdata *)to_delete->data)->size);
				ft_delete_rbtree(&root, to_delete, &free_data);
				printf("DELETED:\n----------------------------------------------\n");
				ft_print_rbtree(root);
				printf("----------------------------------------------\n");
			}
			to_delete = NULL;
		}
		i++;
	}
	printf("------------------FINAL TREE-----------------\n");
	ft_print_rbtree(root);
	return (0);
}


