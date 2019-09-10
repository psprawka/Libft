/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:00:51 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 18:00:53 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strcount_chr(char *str, char chr)
{
    int count;
    int i;
    
    i = 0;
    count = 0;
    
    while (str[i])
    {
        if (str[i] == chr)
            count++;
        i++;
    }
    return (count);
}