/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:30:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:15:19 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_chr(char *src, char c)
{
	char	*dest;
	int		len;

	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	if (!(dest = ft_strnew(len)))
		return (NULL);
		
	dest = ft_strncpy(src, len);
	return (dest);
}
