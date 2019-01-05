/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:05:49 by psprawka          #+#    #+#             */
/*   Updated: 2019/01/05 04:40:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_ht(t_ht_table *table)
{
	t_ht_item	*item;
	int			i;

	if (!table || !table->hash_table)
		return ;
	i = 0;
	ft_printf("---------------- HASH TABLE ----------------\n[key:value]:\n");
	while (i < table->size)
	{
		item = table->hash_table[i];
		while (item)
		{
			printf("%d. [%s:%s]\n", i, (char *)item->key, (char *)item->value);
			item = item->next;
		}
		i++;
	}
	ft_printf("--------------------------------------------\n\n");
}
