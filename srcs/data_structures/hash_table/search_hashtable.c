/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 05:49:00 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 08:53:03 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_search_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *))
{
	int		i;
	int		pos;

	if (!table || !table->hash_table || !key || !fcmp)
		return (NULL);
	i = 0;
	pos = ft_hash_ht(key, table->size, i++);
	while (table->hash_table[pos])
	{
		if (table->hash_table[pos] != &HASH_DELETED_ITEM &&
			fcmp(key, table->hash_table[pos]->value) == EXIT_SUCCESS)
			return (table->hash_table[pos]->value);
		pos = ft_hash_ht(key, table->size, i++);
	}
	return (NULL);
}