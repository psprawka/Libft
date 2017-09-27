/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:28:28 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/19 15:28:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr2;

	ptr2 = (char *)src;
	ptr = (char *)dst;
	if (ptr == ptr2)
		return (ptr);
	if (ptr > ptr2)
	{
		ptr += len - 1;
		ptr2 += len - 1;
		while (len--)
			*ptr-- = *ptr2--;
	}
	else
		while (len--)
			*(ptr++) = *(ptr2++);
	return (dst);
}
