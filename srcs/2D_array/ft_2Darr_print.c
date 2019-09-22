/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Darr_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 09:49:41 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 10:11:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Ft_2Darr_print() prints an array of strings. It works properly only when
**	the array is terminated with NULL.
*/
void	ft_2Darr_print(char **arr, char *ink)
{
	int	i;
	
	if (!arr)
		return ;
	if (!ink)
		ink = NORMAL;
	i = 0;
	while (arr[i])
	{
		ft_printf("%sarr[%d] -> \"%s\"%s\n", ink, i, arr[i], NORMAL);
		i++;
	}
}
