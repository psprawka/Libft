/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:37:09 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/19 15:37:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr2;

	ptr = (char *)src;
	ptr2 = (char *)dst;
	while (len--)
		*(ptr2++) = *(ptr++);
	return (dst);
}
