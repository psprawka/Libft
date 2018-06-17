/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:19:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:16:24 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (!(rev = ft_strnew(len)))
		return (NULL);
	while (i < len)
		rev[i++] = str[len];
	free(str);
	return (rev);
}
