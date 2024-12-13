#include "so_long.h"

int is_outsider_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'F')
        return 0;
    return 1;
}

int get_width(char *line)
{
    int i = 0;
    while(line && line[i] && line[i] != '\n')
    {
        if (line[i] != '1')
        {
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
                map_cnfg->enemy++;
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

void last_row(char *last_row)
{
    int i = 0;
    while(last_row[i])
    {
        if (last_row[i] != '1')
        {
            write(2, "INVALID BORDERS\n", 16);
            exit(2);
        }
        i++;
    }
}

void flood_fill_check(char **map, int start_x, int start_y, t_m_config *map_cnfg)
{
    if (map[start_y][start_x] == 'F' || map[start_y][start_x] == '1')
        return ;
    if (map[start_y][start_x] == 'E')
        map_cnfg->winable = 1;
    if (map[start_y][start_x] == 'C')
        map_cnfg->reachable_c++;
    map[start_y][start_x] = 'F';
    flood_fill_check(map, start_x++, start_y, map_cnfg);
    flood_fill_check(map, start_x--, start_y, map_cnfg);
    flood_fill_check(map, start_x, start_y++, map_cnfg);
    flood_fill_check(map, start_x, start_y--, map_cnfg);
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

void is_winable(char **map, t_m_config *map_config)
{
    flood_fill_check(map, map_config->player_position[1], map_config->player_position[0], map_config);
    if (map_config->winable == 0)
    {
        write(2, "NOT WINABLE MAP\n", 16);
        exit(2);
    }
    if (map_config->reachable_c != map_config->c_count)
    {
        write(2, "NOT REACHABLE COLLECTABLE\n", 26);
        exit(2);
    }
}

void get_player_position(t_m_config *map_config, char **map)
{
    int i = 1;
    int j;
    while(map[i])
    {
        j = 1;
        while(map[i][j])
        {
            if (map[i][j] == 'P')
            {
                map_config->player_position[0] = i;
                map_config->player_position[1] = j;
            }
            if (map[i][j] == 'E')
            {
                map_config->exit_position[0] = i;
                map_config->exit_position[1] = j;
            }
            j++;
        }
        i++;
    }
}

char **map_copy(char **map, t_m_config *map_config)
{
    int i = 0;
    char **t_map = malloc(sizeof(char *) * (map_config->y_size + 1));
    while(map[i])
    {
        t_map[i] = ft_strdup1(map[i]);
        i++;
    }
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

void get_map_config(t_m_config *map_config, char **map)
{
    int i = 0;
    int j = 0;

    map_config->x_size = get_width(map[0]);
    map_config->y_size = get_lines(map, map_config, map_config->x_size);
    if (map_config->x_size == map_config->y_size)
    {
        write(2, "NOT RECTANGULAR MAP\n", 20);
        exit(2);
    }
    if (map_config->y_size < 3)
    {
        write(2, "TINNY MAP\n", 10);
        exit(2);
    }
    last_row(map[map_config->y_size - 1]);
    if (map_config->c_count == 0)
    {
        write(2, "NO COLLECTIBLES\n", 16);
        exit(2);
    }
    if (map_config->player != 1)
    {
        write(2, "INVALID PLAYER\n", 15);
        exit(2);
    }
    if (map_config->exit != 1)
    {
        write(2, "INVALID EXIT\n", 13);
        exit(2);
    }
    get_player_position(map_config, map);
    //send a copy to edit on it.
    is_winable(map_copy(map, map_config), map_config);
    // are_all_collectables(map, map_config);
}