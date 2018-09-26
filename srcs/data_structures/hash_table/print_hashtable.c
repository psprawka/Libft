/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:05:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 09:16:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_ht(t_ht_table *table)
{
	int		i;

	if (!table || !table->hash_table)
		return ;
	i = 0;
	ft_printf("---------------- HASH TABLE ----------------\n[key:value]:\n");
	while (i < table->size)
	{
		if (table->hash_table[i])
			printf("%d. [%s:%s]\n", i, (char *)table->hash_table[i]->key,
			(char *)table->hash_table[i]->value);
		i++;
	}
	ft_printf("--------------------------------------------\n\n");
}
