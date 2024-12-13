#include "so_long.h"

char **parse(int fd)
{
    if (fd == -1)
        exit(1);
    t_parse *list = NULL;
    char **map;
    int t_x = 0;
    int t_y = 0;
    int x = 0;
    int y = 0;
    char *line;

    line = get_next_line(fd);
    while(line)
    {
        ft_lst_addback(&list, line);
        free(line);
        line = get_next_line(fd);
        if(!line)
        {
            //free line;
        }
    }
    y = ft_lst_size(list);
    map = malloc(sizeof(char *) * (y + 1));
    while(list)
    {
        map[t_y++] = ft_strdup1(list->line);
        list = list->next;
    }
    map[t_y] = NULL;
    return (map);
}