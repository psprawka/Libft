/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:19 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:35:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_double_list(t_dnode **list, t_dnode *node)
{
	t_dnode	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp == node)
		{
			if (!tmp->prev)
				*list = tmp->next;
			else
				tmp->prev->next = tmp->next;
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}