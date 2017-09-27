/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:34:05 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/21 19:34:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*f;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if (!(f = (char *)malloc(ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		f[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		f[i] = *s2++;
		i++;
	}
	f[i] = '\0';
	return (f);
}
