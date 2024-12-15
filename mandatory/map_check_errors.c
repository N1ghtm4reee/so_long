/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:04:50 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/14 14:48:44 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_itoa2(char *d, int len, long nb)
{
	d[len] = '\0';
	if (nb == 0)
	{
		d[0] = '0';
		return (d);
	}
	if (nb < 0)
	{
		nb = -nb;
		d[0] = '-';
	}
	while (nb > 0)
	{
		d[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*d;

	nb = n;
	len = 0;
	if (n <= 0)
		len++;
	if (n == 0)
		return (ft_strdup1("0"));
	while (n)
	{
		len++;
		n /= 10;
	}
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	d = ft_itoa2(d, len, nb);
	return (d);
}

void flood_fill_check(char **map, int start_x, int start_y, t_m_config *map_cnfg)
{
    if (map[start_y][start_x] == 'F' || map[start_y][start_x] == '1')
        return ;
    if (start_x == map_cnfg->exit_position[1] && start_y == map_cnfg->exit_position[0])
        map_cnfg->winable = 1;
    if (map[start_y][start_x] == 'C')
        map_cnfg->reachable_c++;
    map[start_y][start_x] = 'F';
    flood_fill_check(map, start_x++, start_y, map_cnfg);
    flood_fill_check(map, start_x--, start_y, map_cnfg);
    flood_fill_check(map, start_x, start_y++, map_cnfg);
    flood_fill_check(map, start_x, start_y--, map_cnfg);
}

void is_winable(char **map, t_m_config *map_config)
{
	char **t_map = map_copy(map, map_config);
    flood_fill_check(t_map, map_config->player_position[1], map_config->player_position[0], map_config);
    if (map_config->winable == 0)
    {
		free_map(t_map);
		free_map(map);
        write(2, "NOT WINABLE MAP\n", 16);
        exit(2);
    }
    if (map_config->reachable_c != map_config->c_count)
    {
		free_map(t_map);
		free_map(map);
	    write(2, "NOT REACHABLE COLLECTABLE\n", 26);
        exit(2);
    }
	free_map(t_map);
}
