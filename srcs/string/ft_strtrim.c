/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:24:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:17:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char *str)
{
    char			*fresh;
	int				start;
	unsigned int	i;

	if (!str)
		return (NULL);
	fresh = NULL;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i++;
	start = i;
	if (str[start] == '\0')
	{
		fresh = (char *)malloc(1);
		*fresh = '\0';
		return (fresh);
	}
	while (str[i])
		i++;
	i--;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i--;
	if (!(fresh = (ft_strsub(str, start, i - start + 1))))
		return (NULL);
	return (fresh);
}

//definitely check out this one 

