/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_image1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:09:16 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 21:27:55 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_image1(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->collectable.img);
	mlx_destroy_image(var->mlx_connection, all->exit.img);
	mlx_destroy_display(var->mlx_connection);
	free(var->mlx_connection);
	free_map(map);
	free_int_arr(var->map_cnfg->e_p, var->map_cnfg->enemies_count);
	exit(1);
}

void	clean_image2(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->player.player_right.img_semi);
	mlx_destroy_image(var->mlx_connection, all->collectable.img);
	mlx_destroy_image(var->mlx_connection, all->exit.img);
	mlx_destroy_display(var->mlx_connection);
	free(var->mlx_connection);
	free_map(map);
	free_int_arr(var->map_cnfg->e_p, var->map_cnfg->enemies_count);
	exit(1);
}

void	clean_image3(char **map, t_textures *all, t_window *var)
{
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

void	clean_image4(char **map, t_textures *all, t_window *var)
{
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

void	clean_image5(char **map, t_textures *all, t_window *var)
{
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
