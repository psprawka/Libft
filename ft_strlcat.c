/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:43:50 by psprawka          #+#    #+#             */
/*   Updated: 2017/07/04 15:43:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dstlen;
	size_t		srclen;
	size_t		i;

	dstlen = 0;
	srclen = 0;
	i = 0;
	while (size-- && (*(dst + dstlen) != '\0'))
		dstlen++;
	size++;
	if (size == 0)
		return (dstlen + ft_strlen((char *)src));
	while (*(src + srclen))
	{
		if (size != 1)
		{
			dst[dstlen + i++] = src[srclen];
			size--;
		}
		srclen++;
	}
	*(dst + dstlen + i) = '\0';
	return (dstlen + srclen);
}
