/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:27:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		add_list(t_list **list, int key)
{
	t_list *tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = create_list(key);
		return (EXIT_SUCCESS);
	}
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = create_list(key);
	return (EXIT_SUCCESS);
}


