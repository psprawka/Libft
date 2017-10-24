/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:35:16 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/20 18:35:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_tolower(int x);
int				ft_toupper(int x);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_count_letters(char *str, char c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_is_sort(int *tab, int length, int (*f)(int, int));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_putnbr(int n);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			ft_swap(int *a, int *b);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
void			ft_sort_wordtab(char **tab);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *buffer, int c, size_t num);
void			ft_count_words(unsigned int *w, char *s, char c);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
char			*ft_strdup(char *src);
char			*ft_itoa(int n);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strtrim(char const *s);
char			*ft_strchr(char *str, char to_find);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strrchr(char *str, char to_find);
char			*ft_strncat(char *dest, char const *src, size_t nb);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *big, const char *little, size_t len);
size_t			ft_strlen(char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
