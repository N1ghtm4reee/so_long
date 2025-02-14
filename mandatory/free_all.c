/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:46:45 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/01 18:12:41 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_image(t_window *var)
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
	mlx_destroy_image(var->mlx_connection, var->all_textures.collectable.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.exit.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.field.img);
	mlx_destroy_image(var->mlx_connection, var->all_textures.wall.img);
}
