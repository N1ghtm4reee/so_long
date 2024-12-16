/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:13:40 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 11:44:47 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(char **map, t_m_config *m_con)
{
	if (map[m_con->player_position[0]][m_con->player_position[1] - 1] != '1')
	{
		if (map[m_con->player_position[0]][m_con->player_position[1] - 1] == '0'
			|| map[m_con->player_position[0]][m_con->player_position[1] - 1]
				== 'C')
		{
			map[m_con->player_position[0]][m_con->player_position[1] - 1] = 'P';
			map[m_con->player_position[0]][m_con->player_position[1] - 1] = '0';
		}
	}
}

void	check_resolution(t_textures all, t_m_config map_config, t_window *var)
{
	if (all.wall.img_width * map_config.x_size > MAX_WIDTH)
	{
		free_map(var->tmap);
		write(2, "INVALID WIDTH\n", 14);
		destroy_images(var);
		mlx_destroy_display(var->mlx_connection);
		free(var->mlx_connection);
		exit(1);
	}
	if (all.wall.img_height * map_config.y_size > MAX_HEIGHT)
	{
		free_map(var->tmap);
		write(2, "INVALID HEIGHT\n", 15);
		destroy_images(var);
		mlx_destroy_display(var->mlx_connection);
		free(var->mlx_connection);
		exit(1);
	}
}

void	ft_mlx_free(char **map, t_window *var)
{
	free_int_arr(var->map_cnfg.enemies_positions,
		var->map_cnfg.enemies_count);
	free_map(map);
	exit(1);
}

void	ft_mlx_work(char **map, t_m_config map_config)
{
	t_textures	all_textures;
	t_window	var;

	var.mlx_connection = mlx_init();
	if (!var.mlx_connection)
		return (ft_mlx_free(map, &var));
	var.tmap = map;
	var.map_cnfg = map_config;
	init_textures(&all_textures, &var);
	var.all_textures = all_textures;
	check_resolution(all_textures, map_config, &var);
	var.mlx_window = mlx_new_window(var.mlx_connection,
			all_textures.wall.img_width * map_config.x_size,
			all_textures.wall.img_height * map_config.y_size,
			"so_long");
	if (NULL == var.mlx_window)
		return (mlx_destroy_display(var.mlx_connection),
			free(var.mlx_connection),
			ft_mlx_free(map, &var), exit(1));
	mlx_hook(var.mlx_window, 17, 0, close_window, &var);
	mlx_key_hook(var.mlx_window, key_hook, &var);
	mlx_loop(var.mlx_connection);
	mlx_destroy_window(var.mlx_connection, var.mlx_window);
	mlx_destroy_display(var.mlx_connection);
}

int	main(int ac, char **av)
{
	char				**map;
	static t_m_config	map_config;

	map = NULL;
	if (ac != 2)
		return (1);
	is_right_extension(av[1]);
	map = parse(open(av[1], O_RDONLY), av);
	if (!map)
		return (1);
	get_map_config(&map_config, map);
	enemies_position(map, &map_config);
	ft_mlx_work(map, map_config);
	free_map(map);
	return (0);
}

/*
	free_map(map);
	free_int_arr(var.map_cnfg.enemies_positions, var.map_cnfg.enemies_count);
	free(var.mlx_connection);
*/