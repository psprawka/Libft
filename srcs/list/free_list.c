/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 09:36:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_node **list, void (*fct_free)(void *))
{
	t_node *tmp;

	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		if (fct_free)
			fct_free(tmp->data);
		free(tmp);
		*list = tmp; 
	}
}
