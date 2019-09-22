/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:24:09 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 18:56:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function ft_strtrim() trims whitespaces from the beginning and the end of
**	the string. Space, tab and newline are treadted as whitespaces.
**	Firstly, it skips add the spaces from the beginning as saves the offset in
**	start variable, then it goes from the end to the last whitespaces it occurs.
**	New string is created in ft_strsub() and returned. If a function fails, it
**	returns NULL.
*/	
char    *ft_strtrim(char *str)
{
    char	*new_str;
	int		start;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i++;
	start = i;
	i = ft_strlen(str) - 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i--;
	return ((new_str = (ft_strsub(str, start, i - start + 1))));
}
