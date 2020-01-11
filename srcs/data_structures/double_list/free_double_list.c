/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:10 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:39:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double_list(t_dnode *list, void (*fct_free)(void *))
{
	t_dnode *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (fct_free)
			fct_free(tmp->data);
		free(tmp);
	}
}