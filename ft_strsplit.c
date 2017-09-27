/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:34:34 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/21 19:34:35 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	shorter_code(unsigned int *i, const char *s)
{
	*i = 0;
	if (!s)
		return (1);
	return (0);
}

char		**ft_strsplit(const char *s, char c)
{
	unsigned int	words;
	unsigned int	i;
	int				letters;
	char			**array;
	int				j;

	if (shorter_code(&i, s) == 1)
		return (NULL);
	ft_count_words(&words, (char*)s, c);
	if (!(array = (char **)malloc((sizeof(*array)) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		j = 0;
		while (*s != '\0' && *s == c)
			s++;
		letters = ft_count_letters((char *)s, c);
		if (!(array[i] = (char *)malloc(letters + 1)))
			return (NULL);
		while (j < letters)
			array[i][j++] = *s++;
		array[i++][j] = '\0';
	}
	array[i] = (char *)'\0';
	return (array);
}
