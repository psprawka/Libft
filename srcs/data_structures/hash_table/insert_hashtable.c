/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:05:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 08:52:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_insert_ht(t_ht_table *table, t_ht_item *item, int (*fcmp)(void *, void *))
{
	int			pos;
	int			i;

	i = 0;
	if (!table || !table->hash_table || !item)
		return (EXIT_FAILURE);
	pos = ft_hash_ht(item->key, table->size, i++);
	while (table->hash_table[pos] && table->hash_table[pos] != &HASH_DELETED_ITEM)
	{
		if (!fcmp(table->hash_table[pos]->key, item->key))
			return (EXIT_FAILURE);
		pos = ft_hash_ht(item->key, table->size, i++);
	}
	table->hash_table[pos] = item; 
	table->count++;
	return (EXIT_SUCCESS);
}