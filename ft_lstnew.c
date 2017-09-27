/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:07:50 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/24 20:08:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = NULL;
		return (new);
	}
	if (!(new->content = (void *)malloc(sizeof(void) * content_size)))
		return (NULL);
	new->content = ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	if (!(new->next = (t_list *)malloc(sizeof(new))))
		return (NULL);
	new->next = NULL;
	return (new);
}
