/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:37:16 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/19 15:37:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	while (len--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		if (*(unsigned char *)(src - 1) == (unsigned char)c)
			return (dest);
	}
	return (NULL);
}
