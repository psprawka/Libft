/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wchar_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:18:18 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 21:48:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_wchar_str(wchar_t *str, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(len + 1);
	while (i < len)
	{
		new[i] = (char)str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

