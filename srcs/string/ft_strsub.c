/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:33:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 13:44:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, int start, size_t len)
{
	char	*new;
	int		i;
	
	if (!str || !(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (len--)
		new[i++] = str[start++];
	return (new);
}
