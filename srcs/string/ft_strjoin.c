/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:34:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:19:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define S1	1
#define S2	2

char	*ft_strjoin(char *s1, char *s2, bool sfree)
{
	char	*f;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(f = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		f[i] = s1[i];
	if (sfree & S1)
		free(s1);
	if (sfree & S2)
		free(s2);
	j = 0;
	while (s2[j])
		f[i++] = s2[j++];
	f[i] = '\0';
	return (f);
}
//LOL DOESNT WORK AND SEGFAULTS GHAHAH 
