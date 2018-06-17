/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:19:50 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 13:44:42 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i++] == to_find[j++])
			;
		if (!to_find[j])
			return (EXIT_SUCCESS);
		if (str[i] == '\0')
			return (EXIT_FAILURE);
		i -= j - 1;
	}
	return (EXIT_FAILURE);
}
