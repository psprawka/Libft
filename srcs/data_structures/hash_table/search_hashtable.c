/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 05:49:00 by psprawka          #+#    #+#             */
/*   Updated: 2019/01/04 02:26:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_search_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *))
{
	t_ht_item	*item;
	int			i;
	int			pos;

	if (!table || !table->hash_table || !key || !fcmp)
		return (NULL);
	i = 0;
	pos = ft_hash_ht(key, table->size);
	item = table->hash_table[pos];
	while (item)
	{
		if (fcmp(key, item->key) == EXIT_SUCCESS)
			return (item->value);
		item = item->next;
	}
	return (NULL);
}