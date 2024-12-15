/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:13:40 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 14:52:40 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(char **map, t_m_config *m_con)
{
	if (map[m_con->player_position[0]][m_con->player_position[1] - 1] != '1')
	{
		if (map[m_con->player_position[0]][m_con->player_position[1] - 1] == '0'
			|| map[m_con->player_position[0]][m_con->player_position[1] - 1] == 'C')
		{
			map[m_con->player_position[0]][m_con->player_position[1] - 1] = 'P';
			map[m_con->player_position[0]][m_con->player_position[1] - 1] = '0';
		}
	}
}

int close_window(t_window *var)
{
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open0);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open1);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open2);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open3);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open4);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open5);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open6);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open7);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open8);
	mlx_destroy_image(var->mlx_connection, var->all_textures.font.img_open9);
	mlx_destroy_image(var->mlx_connection, var->all_textures.enemie.img_open);
	mlx_destroy_image(var->mlx_connection, var->all_textures.wall.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.field.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_down.img_open);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_down.img_semi);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_up.img_open);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_up.img_semi);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_left.img_open);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_left.img_semi);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_right.img_open);
	mlx_destroy_image(var->mlx_connection, var->all_textures.player.player_right.img_semi);
	mlx_destroy_image(var->mlx_connection, var->all_textures.exit.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.collectable.img);
	mlx_destroy_window(var->mlx_connection, var->mlx_window);
	mlx_destroy_display(var->mlx_connection);
	free(var->mlx_connection);
	free_map(var->tmap);
	free_int_arr(var->map_cnfg.enemies_positions, var->map_cnfg.enemies_count);
    exit(0);
}

void	ft_mlx_work(char **map, t_m_config map_config)
{
	t_textures all_textures;
	t_window var;
	var.mlx_connection = mlx_init();
	if (!var.mlx_connection)
		exit(11);
	var.tmap = map;
	var.map_cnfg = map_config;
	init_textures(&all_textures, &var);
	var.all_textures = all_textures;
	if (all_textures.wall.img_width * map_config.x_size > MAX_HEIGHT || all_textures.wall.img_height * map_config.y_size > MAX_HEIGHT)
	{
		free_map(map);
		free_int_arr(var.map_cnfg.enemies_positions, var.map_cnfg.enemies_count);
		write(2, "INVALID RESOLUTION\n", 19);
		exit(2);
	}
	var.mlx_window = mlx_new_window(var.mlx_connection, all_textures.wall.img_width * map_config.x_size,
						all_textures.wall.img_height * map_config.y_size, "so_long");
	if (NULL == var.mlx_window)
	{
		mlx_destroy_display(var.mlx_connection);
		free(var.mlx_connection);
		free_int_arr(var.map_cnfg.enemies_positions, var.map_cnfg.enemies_count);
		exit(11);
	}
	mlx_hook(var.mlx_window, 17, 0, close_window, &var);
	mlx_key_hook(var.mlx_window, key_hook, &var);
	mlx_loop(var.mlx_connection);
	mlx_destroy_window(var.mlx_connection, var.mlx_window);
	mlx_destroy_display(var.mlx_connection);
	free_map(map);
	free_int_arr(var.map_cnfg.enemies_positions, var.map_cnfg.enemies_count);
	free(var.mlx_connection);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void is_right_extension(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	i -= 3;
	if (ft_strcmp(str + i, "ber"))
	{
		write(2, "INVALID FILE EXTENSION\n", 23);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	char	**map;
	static t_m_config map_config;

	map = NULL;
	if (ac != 2)
		return (1);
	is_right_extension(av[1]);
	map = parse(open(av[1], O_RDONLY), av);
	if (!map)
		return 1;
	get_map_config(&map_config, map);
	enemies_position(map, &map_config);
	ft_mlx_work(map, map_config);
	return (0);
}
