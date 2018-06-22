/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 10:42:20 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/22 10:46:37 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_are_whitespaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (IS_WHITE(str[i]))
			return (1);
		i++;
	}
	return (0);
}
