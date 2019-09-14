/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:44:56 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 21:46:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_binary(unsigned long int nb)
{
	char	*print;
	int		i;

	i = 0;
	if (!(print = ft_memalloc(33)))
		return (NULL);
	if (nb == 0)
		print[i] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 2) + 48;
		nb /= 2;
	}
	return (ft_strrev(print));
}