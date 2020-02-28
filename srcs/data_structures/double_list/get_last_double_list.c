/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:22:07 by psprawka          #+#    #+#             */
/*   Updated: 2020/02/23 09:01:16 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode *ft_get_last_double_list(t_dnode *head)
{
    t_dnode *tmp;

    tmp = head;
    while (tmp && tmp->next)
        tmp = tmp->next;
    return (tmp);
}