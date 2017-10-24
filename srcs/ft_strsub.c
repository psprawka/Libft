/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:33:53 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/21 19:33:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	int		i;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
	{
		fresh[i++] = s[start++];
	}
	fresh[i] = '\0';
	return (fresh);
}
