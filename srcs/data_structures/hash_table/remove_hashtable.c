/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 06:00:57 by psprawka          #+#    #+#             */
/*   Updated: 2019/01/05 05:03:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_remove_item_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *))
{
	t_ht_item	*item;
	t_ht_item	*prev;
	int			pos;

	if (!table || !table->hash_table || !table->count || !key || !fcmp)
		return (EXIT_FAILURE);
	pos = ft_hash_ht(key, table->size);
	item = table->hash_table[pos];
	if (item)
		printf("[FT_REMOVE_ITEM] item: %s:%s\n", (char *)item->key, (char *)item->value);
	else
		printf("NO ITEM FOUND TO REMOVE\n");
	prev = NULL;
	while (item)
	{
		printf("%s::%s\n", (char *)key, (char *)(item->key));
		if (fcmp(key, item->key) == EXIT_SUCCESS)
		{
			printf("ITEM TO REMOVE FOUND!! REMOVING...\n");
			if (prev)
				prev->next = item->next;
			else
				table->hash_table[pos] = item->next;
			ft_free_item_ht(item);
			table->count--;
			return (EXIT_SUCCESS);
        }
		prev = item;
		item = item->next;
	}
	printf("NO IT FAILS...\n");
	return (EXIT_FAILURE);
}