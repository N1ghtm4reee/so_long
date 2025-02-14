/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:30:03 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 12:48:48 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_outsider_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'F')
		return (0);
	return (1);
}

int	get_width(char *line, char **map)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
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

void	get_line_error(char **map, int flag)
{
	free_map(map);
	if (flag == 1)
		write(2, "INVALID COMPONENT\n", 18);
	if (flag == 2)
		write(2, "NOT RECTANGULAR MAP\n", 20);
	if (!flag)
		write(2, "INVALID BORDERS\n", 16);
	exit(11);
}

int	get_lines(char **map, t_m_config *map_cnfg, int x_size)
{
	int	r[2];

	r[0] = -1;
	while (map[++r[0]])
	{
		r[1] = 0;
		while (map[r[0]][r[1]] && map[r[0]][r[1]] != '\n')
		{
			if (is_outsider_char(map[r[0]][r[1]]))
				get_line_error(map, 1);
			if (map[r[0]][r[1]] == 'C')
				map_cnfg->c_count++;
			if (map[r[0]][r[1]] == 'P')
				map_cnfg->player++;
			if (map[r[0]][r[1]] == 'E')
				map_cnfg->exit++;
			r[1]++;
		}
		if (r[1] != x_size)
			get_line_error(map, 2);
		if (map[r[0]][0] != '1' || map[r[0]][x_size - 1] != '1')
			get_line_error(map, 0);
		r[1]++;
	}
	return (r[0]);
}

char	**map_copy(char **map, t_m_config *map_config)
{
	int		i;
	char	**t_map;

	i = 0;
	t_map = malloc(sizeof(char *) * (map_config->y_size + 1));
	if (!t_map)
		return (NULL);
	while (map[i])
	{
		t_map[i] = strdup(map[i]);
		if (!t_map[i])
		{
			while (i)
				free(t_map[i--]);
			free(t_map);
			exit(11);
		}
		i++;
	}
	t_map[i] = NULL;
	return (t_map);
}
