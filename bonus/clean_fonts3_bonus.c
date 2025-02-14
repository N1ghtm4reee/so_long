/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fonts3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:29:13 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 12:55:37 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_ghost(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->field.img);
	mlx_destroy_image(var->mlx_connection, all->wall.img);
	mlx_destroy_image(var->mlx_connection, all->player.player_down.img_open);
	mlx_destroy_image(var->mlx_connection, all->player.player_down.img_semi);
	mlx_destroy_image(var->mlx_connection, all->player.player_up.img_open);
	mlx_destroy_image(var->mlx_connection, all->player.player_up.img_semi);
	mlx_destroy_image(var->mlx_connection, all->player.player_left.img_open);
	mlx_destroy_image(var->mlx_connection, all->player.player_left.img_semi);
	mlx_destroy_image(var->mlx_connection, all->player.player_right.img_open);
	mlx_destroy_image(var->mlx_connection, all->player.player_right.img_semi);
	mlx_destroy_image(var->mlx_connection, all->collectable.img);
	mlx_destroy_image(var->mlx_connection, all->exit.img);
	mlx_destroy_display(var->mlx_connection);
	free(var->mlx_connection);
	free_map(map);
	free_int_arr(var->map_cnfg->e_p, var->map_cnfg->enemies_count);
	exit(1);
}
