/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:27:29 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 13:43:33 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t		i;
	unsigned	x;

	i = 0;
	if (!to_find)
		return (str);
	while (str[i] && (i < len))
	{
		x = 0;
		while (str[i] && str[i] == to_find[x] && i < len)
		{
			x++;
			i++;
		}
		if (to_find[x])
			return ((char *)&str[i - x]);
		i = i - x + 1;
	}
	return (NULL);

	//look here something is ugly and may not work
}
