/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:35:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:31:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# define NORMAL			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGNETA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define PINK			"\033[38;5;200m"
# define ORANGE			"\033[38;5;208m"
# define PURPLE			"\033[38;5;55m"
# define MAROON			"\033[38;5;88m"
# define GREY			"\033[38;5;246m"

# define IS_ALNUM(c)		(c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123) ? 1 : 0;
# define IS_ALPHA(c)		(c > 64 && c < 91) || (c > 96 && c < 123) ? 1 : 0;
# define IS_ASCII(c)		(c >= 0 && c < 128) ? 1 : 0;
# define IS_DIGIT(c)		(c > 47 && c < 58) ? 1 : 0;
# define IS_PRINTABLE(c)	(c > 31 && c < 127) ? 1 : 0;

# define TO_UPPER(c)		(c > 96 && c < 123) ? c - 32 : c;
# define TO_LOWER(c)		(c > 64 && c < 91) ? c + 32 : c;

typedef struct	s_node
{
	void			*data;
	size_t			d_size;
	struct s_node	*next;

}				t_node;

typedef struct	s_queue
{
	t_node		*first;
	t_node		*last;

}				t_queue;

typedef struct	s_list
{
	int				key;
	struct s_list	*next;
}				t_list;

/*
**	io/
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(long long nb, int fd);
void			ft_putstr_fd(char *s, int fd);
int				gnl(int fd, char **line);

/*
**	list/
*/
int				add_list(t_list **list, int key);
t_list			*create_list(int key);
void			free_list(t_list **list);
void			print_list(t_list *list);
void			remove_list(t_list **list, int key);

/*
**	memory/
*/
void			ft_bzero(void *str, unsigned int n);
void			*ft_memalloc(size_t size);
void			*ft_memchr(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, void *src, unsigned int size);
void			*ft_memdup(void *src, int size);
int				ft_memncmp(void *s1, void *s2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			ft_swap(int *a, int *b);

/*
**	numeric/	//those functions are HORRIBLE, to fix!!!
*/
long long		ft_atoi(char *s);
char			*ft_convert_hex(unsigned long int nb, int type);
char			*ft_convert_octal(unsigned long int nb);
char			*ft_convert_uni(wchar_t wide);
char			*ft_ftoa(double n);
char			*ft_itoa(int nbr);
void			ft_putnbr(int nb);

/*
**	queue/
*/
void			ft_free_queue(t_queue *queue, void (*fct_free)(void *));
t_node			*ft_init_node(void *data, size_t dsize);
t_queue			*ft_init_queue(void);
t_node			*ft_pop_queue(t_queue **queue);
void			ft_push_queue(t_queue **head, t_node *new);
void			ft_push_pqueue(t_queue **head, t_node *new, int (*fct)(t_node *, t_node *));
void			*ft_top_queue(t_queue *queue);
void			remove_node(t_queue **queue, t_node *prev, t_node *remove);

/*
**	string/
*/
void			ft_putchar(char c);
void			ft_putendl(char *str);
void			ft_putstr(char *s);
void			ft_strclr(char *s);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(char *str, char to_find);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup_chr(char *src, char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2, bool sfree);
int				ft_strlen_chr(char *str, char c);
int				ft_strlen(char *str);
char			*ft_strncat(char *dest, char *src, size_t size);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strncpy(char *str, int size);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strrev(char *str);
int				ft_strstr(char *str, char *to_find);
char			*ft_strsub(char *str, int start, size_t len);
int				ft_wstrlen(wchar_t *ws);
char			*ft_strtrim(char *str);

/*
**	tools/
*/
int				ft_count_words(char *str);
int				ft_is_sort(int *array, int length, int (*f)(int, int));
void			ft_sort_wordtab(char **array);

/*
**	ft_printf/
*/
int				ft_printf(const char *format, ...);

//	to fix:
//	-> all numeric
//	-> string/strjoin
//	-> string/strsplit
//	-> string/strnstr
//	-> string/strtrim
//	-> tools/either of them

#endif
