/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 04:24:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:27:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *list)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = list;
	printf("%s\nLIST:\n", YELLOW);
	while (tmp)
	{
		printf("%d. p:[%p], k:[%d]\n", i++, tmp, tmp->key);
		tmp = tmp->next;
	}
	printf("%s\n", NORMAL);
}
