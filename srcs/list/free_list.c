/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 03:35:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:27:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{

		printf("free: p:[%p], k:[%d]\n", tmp, tmp->key);
		tmp = tmp->next;
		free(*list);
		*list = tmp; 
	}
}
