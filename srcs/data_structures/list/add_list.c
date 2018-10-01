/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 15:20:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_add_back_list(t_node **list, t_node *node)
{
	t_node *tmp;

	if (!(*list))
	{
		*list = node;
		return (EXIT_SUCCESS);
	}
	
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = node;
	return (EXIT_SUCCESS);
}

int		ft_add_front_list(t_node **list, t_node *node)
{
	t_node *tmp;

	if (!(*list))
	{
		*list = node;
		return (EXIT_SUCCESS);
	}
	
	tmp = node;
	tmp->next = *list;
	*list = tmp;
	return (EXIT_SUCCESS);
}