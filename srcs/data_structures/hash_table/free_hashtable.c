/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:05:24 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 08:51:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_free_item_ht(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	ft_free_table_ht(t_ht_table *table)
{
	free(table->hash_table);
	free(table);
}
