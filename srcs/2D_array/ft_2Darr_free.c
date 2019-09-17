/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Darr_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:01:47 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/17 21:03:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Ft_2Darr_free() frees an array of strings. It works properly only when
**	the array is terminated with NULL.
*/
void	ft_2Darr_free(char **arr)
{
	int i;
	
	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}