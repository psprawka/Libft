/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:07 by psprawka          #+#    #+#             */
/*   Updated: 2020/02/23 09:01:16 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_add_back_double_list(t_dnode **list, t_dnode *node) //void
{
	t_dnode *tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = node;
		return (EXIT_SUCCESS);
	}

	while (tmp->next)
		tmp = tmp->next;
        
	tmp->next = node;
    node->prev = tmp;
	return (EXIT_SUCCESS);
}

int		ft_add_front_double_list(t_dnode **list, t_dnode *node) //void
{
	if (!(*list))
	{
		*list = node;
		return (EXIT_SUCCESS);
	}
    
	node->next = *list;
    (*list)->prev = node;
	*list = node;
	return (EXIT_SUCCESS);
}