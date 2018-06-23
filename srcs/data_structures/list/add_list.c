/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 09:36:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_add_list(t_node **list, void *data)
{
	t_node *tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = ft_init_node(data, sizeof(data));
		return (EXIT_SUCCESS);
	}
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = ft_init_node(data, sizeof(data));
	return (EXIT_SUCCESS);
}


