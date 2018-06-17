/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:40:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 12:52:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char		*ft_strjoin_newline(char const *s1, char const *s2, int *o_nl)
{
	char	*f;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if (!(f = (char *)malloc(ft_strlen((char *)s1)
	+ ft_strlen_chr((char *)s2, '\n') + 1)))
		return (NULL);
	*o_nl = ((GNL_BUFF_SIZE == 1 && *s2 == '\n') ? 1 : 0);
	while (s1[i])
	{
		f[i] = s1[i];
		i++;
	}
	while (*s2 && *s2 != '\n')
	{
		f[i] = *s2++;
		i++;
	}
	f[i] = '\0';
	return (f);
}

static char		*copy_new(char *s, int *len)
{
	int		i;
	char	*new;

	i = 0;
	while ((s[*len] != '\n') && (s[*len] != '\0'))
		*len += 1;
	new = (char *)malloc(*len + 1);
	while ((s[i] != '\n') && (s[i] != '\0'))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int		find_line(char **line, int fd, char *temp, int *i)
{
	int		ret;
	int		only_nl;

	only_nl = 0;
	while ((ret = read(fd, temp, GNL_BUFF_SIZE)) > 0)
	{
		*i = 0;
		temp[ret] = '\0';
		*line = (ret < 0 ? '\0' : ft_strjoin_newline(*line, temp, &only_nl));
		if (only_nl == 1)
			return (1);
		while (*i < ret)
		{
			if (temp[*i] == '\n')
				return (1);
			*i += 1;
		}
		ft_memset(temp, '\0', GNL_BUFF_SIZE + 1);
	}
	if (ret < 0)
		return (-1);
	return (ret == 0 ? 0 : 1);
}

int				gnl(int fd, char **line)
{
	static char	*rest;
	int			i_ret[2];
	char		temp[GNL_BUFF_SIZE + 1];

	i_ret[0] = 0;
	if (fd < 0 || !line || GNL_BUFF_SIZE < 1)
		return (-1);
	*line = ft_memalloc(1);
	if (rest == NULL)
		rest = ft_memalloc(1);
	if (*rest != '\0')
	{
		*line = copy_new(rest, &i_ret[0]);
		if ((rest[i_ret[0]] == '\n') &&
			(rest = ft_strsub(rest, i_ret[0] + 1, ft_strlen(rest) - i_ret[0])))
			return (1);
		rest = ft_strsub(rest, i_ret[0] + 1, ft_strlen(rest) - i_ret[0]);
	}
	i_ret[1] = find_line(line, fd, temp, &i_ret[0]);
	if (i_ret[1] == 1 && GNL_BUFF_SIZE != 1)
		rest = ft_strsub(temp, i_ret[0] + 1, ft_strlen(temp) - i_ret[0]);
    if ((i_ret[1] == 1 && GNL_BUFF_SIZE == 1) || (i_ret[1] == -1))
		return (i_ret[1]);
	return ((*rest == '\0' && **line == '\0') ? 0 : 1);
}