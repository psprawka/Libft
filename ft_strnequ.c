/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:33:44 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/21 19:33:46 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (*s1 && *s2)
	{
		while ((*s1 && *s2) && n-- && n > 0)
			if (*s1++ != *s2++)
				return (0);
		return (1);
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}
