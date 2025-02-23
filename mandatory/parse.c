/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:04:36 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/29 16:48:32 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	last_row(char *last_row, char **map)
{
	int	i;

	i = 0;
	while (last_row[i + 1])
	{
		if (last_row[i] != '1')
		{
			free_map(map);
			write(2, "INVALID BORDERS\n", 16);
			exit(1);
		}
		i++;
	}
}

void	get_player_position(t_m_config *map_config, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map_config->player_pos[0] = i;
				map_config->player_pos[1] = j;
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

void	check_map_config(t_m_config *map_config, char **map)
{
	if (map_config->y_size < 3)
		return (write(2, "TINNY MAP\n", 10), free_map(map), exit(1));
	last_row(map[map_config->y_size - 1], map);
	if (map_config->c_count == 0)
	{
		free_map(map);
		write(2, "NO COLLECTIBLES\n", 16);
		exit(2);
	}
	if (map_config->player != 1)
	{
		free_map(map);
		write(2, "INVALID PLAYER\n", 15);
		exit(2);
	}
	if (map_config->exit != 1)
	{
		free_map(map);
		write(2, "INVALID EXIT\n", 13);
		exit(2);
	}
}

void	get_map_config(t_m_config *map_config, char **map)
{
	map_config->x_size = get_width(map[0], map);
	map_config->y_size = get_lines(map, map_config, map_config->x_size);
	check_map_config(map_config, map);
	get_player_position(map_config, map);
	is_winable(map, map_config);
	map[map_config->exit_position[0]][map_config->exit_position[1]] = '0';
}
