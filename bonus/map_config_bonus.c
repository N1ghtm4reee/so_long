/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:30:03 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 14:39:20 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int is_outsider_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'F')
        return 0;
    return 1;
}

int get_width(char *line, char **map)
{
    int i = 0;
    while(line && line[i] && line[i] != '\n')
    {
        if (line[i] != '1')
        {
            free_map(map);
            write(2, "INVALID BORDERS\n", 16);
            exit(2);
        }
        i++;
    }
    return (i);
}

int get_lines(char **map, t_m_config *map_cnfg, int x_size)
{
    int i;
    int y = 0;
    while(map[y])
    {
        i = 0;
        while(map[y][i] && map[y][i] != '\n')
        {
            if (is_outsider_char(map[y][i]))
            {
                write(2, "INVALID COMPONENT\n", 18);
                exit(2);
            }
            if (map[y][i] == 'C')
                map_cnfg->c_count++;
            if (map[y][i] == 'P')
                map_cnfg->player++;
            if (map[y][i] == 'E')
                map_cnfg->exit++;
            if (map[y][i] == 'F')
                map_cnfg->enemie++;
            i++;
        }
        if (i != x_size)
        {
            write(2, "NOT RECTANGULAR MAP\n", 20);
            exit(2);
        }
        if (map[y][0] != '1' || map[y][x_size - 1] != '1')
        {
            write(2, "INVALID BORDERS\n", 16);
            exit(2);
        }
        i++;
        y++;
    }
    return (y);
}

void flood_fill_check2(char **map, int start_x, int start_y, t_m_config *map_cnfg)
{
    if (map[start_y][start_x] == 'F' || map[start_y][start_x] == '1')
        return ;
    if (map[start_y][start_x] == 'P')
        map_cnfg->reachable_c = 1;
    map[start_y][start_x] = 'F';
    flood_fill_check2(map, start_x, start_y++, map_cnfg);
    flood_fill_check2(map, start_x, start_y--, map_cnfg);
    flood_fill_check2(map, start_x++, start_y, map_cnfg);
    flood_fill_check2(map, start_x--, start_y, map_cnfg);
}

char **map_copy(char **map, t_m_config *map_config)
{
    int i = 0;
    char **t_map;

    t_map = malloc(sizeof(char *) * (map_config->y_size + 1));
    if (!t_map)
        return (NULL);
    while(map[i])
    {
        t_map[i] = strdup(map[i]);
        if (!t_map[i])
        {
            // free()
        }
        i++;
    }
    t_map[i] = NULL;
    return t_map;
}

void are_all_collectables(char **map, t_m_config *map_config)
{
    int i = 0;
    int s = 0;
    int j = 0;
    map_config->c_arr = malloc(sizeof(int *) * (map_config->c_count));
    if (!map_config->c_arr)
        return ;
    //c_arr[0] -> y | c_arr[1] -> x
    while (map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if (map[j][i] == 'C')
            {
                map_config->c_arr[s] = malloc(sizeof(int) * 2);
                map_config->c_arr[s][0] = j;
                map_config->c_arr[s][1] = i;
                s++;
            }
            i++;
        }
        j++;
    }
    s = 0;
    while (s < map_config->c_count)
    {
        map_config->reachable_c = 0;
        char **t_map = map_copy(map, map_config);
        flood_fill_check2(t_map, map_config->c_arr[s][1], map_config->c_arr[s][0], map_config);
        // free_map();
        if (map_config->reachable_c != 1)
        {
            write(2, "COLLECTABLE NOT REACHABLE\n", 26);
            exit(2);
        }
        s++;
    }
}

void enemies_position(char **map, t_m_config *map_cnfg)
{
    map_cnfg->enemies_positions = malloc(sizeof(int *) * map_cnfg->enemies_count);
    int i = 0;
    while(i < map_cnfg->enemies_count)
    {
        map_cnfg->enemies_positions[i] = malloc(sizeof(int) * 2);
        i++;
    }
    i = 1;
    int j;
    int s = 0;
    while(map[i])
    {
        j = 1;
        while(map[i][j])
        {
            if (map[i][j] == 'F')
            {
                map_cnfg->enemies_positions[s][0] = i;
                map_cnfg->enemies_positions[s][1] = j;
                s++;
            }
            j++;
        }
        i++;
    }
}
