/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:20:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:23:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp_x(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (0);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void		ft_sort_wordtab(char **array)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (array[len])
		len++;
	while (i < len - 1)
	{
		if (ft_strcmp_x(array[i], array[i + 1]) > 0)
		{
			ft_swap((int *)array[i], (int *)array[i + 1]);
			i = -1;
		}
		i++;
	}
}
