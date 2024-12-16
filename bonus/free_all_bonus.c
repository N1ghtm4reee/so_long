/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:46:45 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 11:38:08 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_int_arr(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

void	destroy_player(t_window *var)
{
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_down.img_open);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_down.img_semi);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_up.img_open);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_up.img_semi);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_left.img_open);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_left.img_semi);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_right.img_open);
	mlx_destroy_image(var->mlx_connection,
		var->all_textures.player.player_right.img_semi);
}

void	destroy_images(t_window *var)
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
	destroy_player(var);
	mlx_destroy_image(var->mlx_connection, var->all_textures.exit.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.collectable.img);
}

int	close_window(t_window *var)
{
	destroy_images(var);
	mlx_destroy_window(var->mlx_connection, var->mlx_window);
	mlx_destroy_display(var->mlx_connection);
	free(var->mlx_connection);
	free_map(var->tmap);
	free_int_arr(var->map_cnfg.enemies_positions, var->map_cnfg.enemies_count);
	exit(0);
}
