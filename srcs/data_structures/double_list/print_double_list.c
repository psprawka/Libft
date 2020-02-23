/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:16 by psprawka          #+#    #+#             */
/*   Updated: 2020/02/23 08:37:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_list(t_dnode *list, void (*fct_print)(void *))
{
	int		i;
	t_dnode	*tmp;

	i = 1;
	tmp = list;
	printf("%s\nDOUBLE LIST:\n", YELLOW);
	while (tmp)
	{
		printf("%d. p:[%p], pdata:[%p]\n", i++, tmp, tmp->data);
        if (fct_print)
			fct_print(tmp->data);
		tmp = tmp->next;
	}
	printf("%s\n", NORMAL);
}