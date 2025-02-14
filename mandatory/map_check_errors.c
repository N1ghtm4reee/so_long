/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:04:50 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/29 15:13:27 by aakhrif          ###   ########.fr       */
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

void	can_reach_exit(char **map, int x, int y, t_m_config *map_cnfg)
{
	if (x < 0 || y < 0 || x > map_cnfg->x_size
		|| y > map_cnfg->y_size || map[y][x] == '1' )
		return ;
	if (map[y][x] == 'E')
		map_cnfg->winable = 1;
	if (map[y][x] == 'C')
		map_cnfg->reachable_c++;
	map[y][x] = '1';
	can_reach_exit(map, x + 1, y, map_cnfg);
	can_reach_exit(map, x - 1, y, map_cnfg);
	can_reach_exit(map, x, y + 1, map_cnfg);
	can_reach_exit(map, x, y - 1, map_cnfg);
}

void	is_winable(char **map, t_m_config *map_config)
{
	char	**t_map;

	t_map = map_copy(map, map_config);
	can_reach_exit(t_map, map_config->player_pos[1],
		map_config->player_pos[0], map_config);
	if (map_config->winable == 0)
	{
		free_map(t_map);
		free_map(map);
		write(2, "NOT WINABLE MAP\n", 16);
		exit(1);
	}
	if (map_config->reachable_c != map_config->c_count)
	{
		free_map(t_map);
		free_map(map);
		write(2, "NOT REACHABLE COLLECTABLE\n", 26);
		exit(1);
	}
	free_map(t_map);
}
