/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:33:52 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/20 15:33:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	unsigned	x;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && (i < len))
	{
		x = 0;
		while (big[i] && big[i] == little[x] && i < len)
		{
			x++;
			i++;
		}
		if (!little[x])
			return ((char *)&big[i - x]);
		i = i - x + 1;
	}
	return ((char *)0);
}
