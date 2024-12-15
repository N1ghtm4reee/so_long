/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:46:45 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 14:37:17 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void free_node(char *line)
{
    free(line);    
}

void free_list(t_parse **lst)
{
    t_parse *p = *lst;
    t_parse *d;

    if (*lst == NULL)
        return ;
    while(p)
    {
        d = p;
        p = p->next;
        free_node(d->line);
        free(d);
    }
    *lst = NULL;
}

void free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void free_int_arr(int **arr, int size)
{
    int i = 0;
    while(i < size)
        free(arr[i++]);
    free(arr);
}