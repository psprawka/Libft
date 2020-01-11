/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:07 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:48:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_add_back_double_list(t_dnode **list, t_dnode *node)
{
	t_dnode *tmp;

	if (!(*list))
	{
		*list = node;
		return (EXIT_SUCCESS);
	}
	
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
        
	tmp->next = node;
    node->prev = tmp;
	return (EXIT_SUCCESS);
}

int		ft_add_front_double_list(t_dnode **list, t_dnode *node)
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