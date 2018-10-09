/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:13:32 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/08 14:10:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_pop_stack(t_node **stack)
{
	t_node	*tmp;

	if (!(tmp = *stack))
		return (NULL);
	*stack = tmp->next;
	return (tmp);
}
