/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 06:00:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 09:07:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_remove_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *))
{
	int		pos;
	int		i;

	if (!table || !table->hash_table || !key || !fcmp)
		return (EXIT_FAILURE);
	i = 0;
	pos = ft_hash_ht(key, table->size, i++);
	while (table->hash_table[pos] && i < table->count)
	{
		if (table->hash_table[pos] != &HASH_DELETED_ITEM &&
			fcmp(key, table->hash_table[pos]->value) == EXIT_SUCCESS)
		{
			ft_free_item_ht(table->hash_table[pos]);
            table->hash_table[pos] = &HASH_DELETED_ITEM;
			table->count--;
			return (EXIT_SUCCESS);
        }
		pos = ft_hash_ht(key, table->size, i++);
	}
	return (EXIT_FAILURE);
}