/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:17:33 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 18:22:39 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_strsplit_chr(char *str, char c)
{
    int     i;
    int     len;
    int     offset;
    int     occurances;
    char    **split;
    
    if (!str || ((occurances = ft_strcount_chr(str, c)) == EXIT_FAILURE) ||
        (split = (char **)malloc(sizeof(char *) * (occurances + 1))) == NULL)
        return (NULL);
    i = 0;
    offset = 0;
    while (i < occurances + 1)
    {
        len = ft_strlen_chr(&str[offset], c);
        if ((split[i] = ft_strncpy(&str[offset], len)) == NULL)
        {
            while (i-- > -1)
                free(split[i]);
            free(split);
            return (NULL);
        }
        offset += len + 1;
        i++;
    }
    return (split);
}