/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_rbtree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:46:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 13:38:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RBTREE
# define LIBFT_RBTREE

typedef struct	s_rbtree
{
	void	*data;
	int		color:4;
	struct	s_rbtree *parent;
	struct	s_rbtree *left;
	struct	s_rbtree *right;

}				t_rbtree;

# define NPARENT		node->parent
# define NGRANDPA		NPARENT->parent
# define NUNCLE_LEFT	NGRANDPA->left
# define NUNCLE_RIGHT	NGRANDPA->right

# define PARENT			root->parent
# define GRANDPA		PARENT->parent
# define UNCLE_LEFT		GRANDPA->left
# define UNCLE_RIGHT	GRANDPA->right

# define RBBLACK		1
# define RBRED			2
# define DB_RBBLACK		4
# define DB_RBRED		8

t_rbtree		*ft_get_sibling_rbtree(t_rbtree *node);
t_rbtree		*ft_get_uncle_rbtree(t_rbtree *node);
t_rbtree		*ft_create_rbtree(void *data);
void			ft_rotate_left_rbtree(t_rbtree *node);
void			ft_rotate_right_rbtree(t_rbtree *node);
void			ft_insert_repair_tree(t_rbtree *node);
void			ft_insert_rbtree(t_rbtree **root, t_rbtree *to_insert, int (*fct)(void *, void *));
t_rbtree		*ft_search_rbtree(t_rbtree *root, t_rbtree *node, int (*fct)(void *, void *));
t_rbtree		*ft_search_successor_rbtree(t_rbtree *root);
void			ft_delete_rbtree(t_rbtree **root, t_rbtree *to_delete, void (*free_data)(void *));
int				ft_delete_repair_rbtree(t_rbtree *node);
void			ft_print_rbtree(t_rbtree *node);

#endif
