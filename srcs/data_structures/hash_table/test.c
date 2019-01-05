/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 01:08:25 by psprawka          #+#    #+#             */
/*   Updated: 2019/01/05 05:24:04 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

typedef struct  s_dtable
{
    char    *key;
    char    *value;
}               t_dtable;

t_dtable    items[20] =
{
    {"horse", "I'm a horse ihaa"},
    {"dog", "I'm a dog woof"},
    {"cat", "I'm a cat meow"},
    {"bird", "I'm a bird tweet"},
    {"cow", "I'm a cow moo"},
    {"goat", "I'm a goat meee"},
    {"chicken", "I'm a chicken coco"},
    {"wasp", "I'm a wasp bzzz"},
    {"hooman", "I'm a hooman bitch"},
    {"potato", "I'm a brown potato"},
    {"carrot", "I'm an orange carrot"},
    {"onion", "I'm a yellow onion"},
    {"lettuce", "I'm a green lettuce"},
    {"cucumber", "I'm a green cucumber"},
    {"beetroot", "I'm a purple beetroot"},
    {"grape", "I'm a purple grape"},
    {"orange", "I'm an orange orange"},
    {"watermelon", "I'm a pink watermelon"},
    {"tomato", "I'm a red tomato"},
    {"eggpland", "I'm a purple eggplant"},
};

int cmp(void *s1, void *s2)
{
    char    *str1;
    char    *str2;
    int     i;
    
    if (!s1 || !s2)
        return (EXIT_FAILURE);
    
    i = 0;
    str1 = (char *)s1;
    str2 = (char *)s2;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (EXIT_FAILURE);
        i++;
    }
    if (str1[i] || str2[i])
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    t_ht_table  *ht;
    t_ht_item   *item;

    ht = ft_init_table_ht(17);
    for (int i = 0; i < 20; i++)
    {
        printf("STEP1\n");
        item = ft_init_item_ht(ft_strdup(items[i].key), ft_strdup(items[i].value));
        printf("%sSTEP 2: created %s:%s item%s\n", PINK, item->key, item->value, NORMAL);
        ft_insert_ht(ht, item, &cmp);
        printf("STEP3\n");
        ft_print_ht(ht);
        printf("STEP4\n");
        if (!(i % 4))
        {
            printf("%sSTEP 5: removing %s:%s item%s\n", YELLOW,  items[i - ht->count + 2].key, items[i - ht->count + 2].value, NORMAL);
            ft_remove_item_ht(ht, items[i - ht->count + 2].key, &cmp);
        }
    } 
    printf("%sFINAL STEP:%s\n", RED, NORMAL);
    ft_print_ht(ht);
    printf("%sFINAL FREEING:%s\n", RED, NORMAL);
    ft_free_ht(ht);
    printf("DONE\n");
    return (0);
}