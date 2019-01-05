/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:05:24 by psprawka          #+#    #+#             */
/*   Updated: 2019/01/05 05:23:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_free_item_ht(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	ft_free_ht(t_ht_table *table)
{
	t_ht_item	*item;
	t_ht_item	*prev;
	int			i;
	
	if (!table)
		return ;
	
	i = 0;
	while (i < table->size)
	{
		item = table->hash_table[i];
		while (item)
		{
			prev = item;
			item = item->next;
			ft_free_item_ht(prev);
		}
		i++;
	}
	free(table->hash_table);
	free(table);
}
