/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:37:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 13:13:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, int size)
{ 
	void	*dest;
	
	if (!src || !(dest = ft_memalloc(size)))
		return (NULL);
		
	ft_memcpy(dest, src, size);
	return (dest);
}
