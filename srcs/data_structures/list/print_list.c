/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 04:24:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 09:36:39 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_node *list)
{
	int		i;
	t_node	*tmp;

	i = 1;
	tmp = list;
	printf("%s\nLIST:\n", YELLOW);
	while (tmp)
	{
		printf("%d. p:[%p], pdata:[%d]\n", i++, tmp, tmp->data);
		tmp = tmp->next;
	}
	printf("%s\n", NORMAL);
}
