/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:33 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:40:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_node *list, void (*fct_free)(void *))
{
	t_node *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (fct_free)
			fct_free(tmp->data);
		free(tmp);
	}
}
