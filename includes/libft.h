/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:35:16 by psprawka          #+#    #+#             */
/*   Updated: 2020/01/11 02:51:27 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft_define.h"
# include "libft_struct.h"
# include "libft_rbtree.h"


// static t_ht_item HASH_DELETED_ITEM = {NULL, NULL}; 

/*
**	io/
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(long long nb, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_get_next_line(int fd, char **line);
int				ft_printf(const char *format, ...);

/*
**	data_structures/
*/
t_node			*ft_init_node(void *data, size_t dsize);
void			remove_node(t_queue **queue, t_node *prev, t_node *remove);


/*
**  data_structures/btree
*/


/*
**	data_structures/double_list/
*/
int				ft_add_back_double_list(t_dnode **list, t_dnode *node);
int				ft_add_front_double_list(t_dnode **list, t_dnode *node);
void			ft_free_double_list(t_dnode *list, void (*fct_free)(void *));
t_dnode		    *ft_init_double_list(void *data, size_t dsize);
void			ft_print_double_list(t_dnode *list, void (*fct_print)(void *));
void			ft_remove_double_list(t_dnode **list, t_dnode *node);

/*
**	data_structures/hash_table/
*/
void			ft_free_item_ht(t_ht_item *item);
void			ft_free_ht(t_ht_table *table);
int				ft_hash_ht(void *value, int size);
t_ht_item		*ft_init_item_ht(void *key, void *value);
t_ht_table		*ft_init_table_ht(int size);
int				ft_insert_ht(t_ht_table *table, t_ht_item *item, int (*fcmp)(void *, void *));
void			ft_print_ht(t_ht_table *table);
int		        ft_remove_item_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *));
void			*ft_search_ht(t_ht_table *table, void *key, int (*fcmp)(void *, void *));

/*
**	data_structures/list/
*/
int				ft_add_back_list(t_node **list, t_node *node);
int				ft_add_front_list(t_node **list, t_node *node);
void			ft_free_list(t_node *list, void (*fct_free)(void *));
void			ft_print_list(t_node *list, void (*fct_print)(void *));
void			ft_remove_list(t_node **list, t_node *node);

/*
**	data_structures/queue/
*/
void			ft_free_queue(t_queue *queue, void (*fct_free)(void *));
t_queue			*ft_init_queue(void);
t_node			*ft_pop_queue(t_queue **queue);
void			ft_push_queue(t_queue **head, t_node *new);
void			ft_push_pqueue(t_queue **head, t_node *new, int (*fct)(t_node *, t_node *));
void			*ft_top_queue(t_queue *queue);

/*
**	data_structures/stack/
*/
bool			ft_is_empty_stack(t_node *stack);
int				ft_push_stack(t_node **stack, t_node *to_push);
t_node			*ft_pop_stack(t_node **stack);
void			*ft_top_stack(t_node *stack);

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
char			*ft_ulltoa(unsigned long long int nb);
char			*ft_convert_wchar_str(wchar_t *str, int len);
char			*ft_convert_binary(unsigned long int nb);

/*
**	2D_array/
*/
int 			ft_2Darr_size(char **arr);
void			ft_2Darr_free(char **arr);

/*
**	string/
*/
int				ft_are_whitespaces(char *str);
void			ft_putchar(char c);
void			ft_putendl(char *str);
void			ft_putstr(char *s);
void			ft_strclr(char *s);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(char *str, char to_find);
int				ft_strcmp(char *s1, char *s2);
int     		ft_strcount_chr(char *str, char chr);
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
char    		**ft_strsplit_chr(char *str, char c);
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
void			ft_set_max_fd(int *maxfd, int newfd);


//	to fix:
//	-> all numeric
//	-> string/strjoin
//	-> string/strnstr
//	-> string/strtrim
//	-> tools/either of them
//	-> data_structures/red_black_tree/* 
//	-> data_structures/hash_table add resizing function
//	-> fix printf becuase it frees static (ft_itoa)

#endif
