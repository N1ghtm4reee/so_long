/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:46:45 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/14 20:36:32 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
        free(d->line);
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