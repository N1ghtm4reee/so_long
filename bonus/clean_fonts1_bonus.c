/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fonts1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:31:00 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 12:58:00 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	font_clean1(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->enemie.img_open);
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

void	font_clean2(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->font.img_open0);
	mlx_destroy_image(var->mlx_connection, all->enemie.img_open);
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

void	font_clean3(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->font.img_open1);
	mlx_destroy_image(var->mlx_connection, all->font.img_open0);
	mlx_destroy_image(var->mlx_connection, all->enemie.img_open);
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

void	font_clean4(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->font.img_open2);
	mlx_destroy_image(var->mlx_connection, all->font.img_open1);
	mlx_destroy_image(var->mlx_connection, all->font.img_open0);
	mlx_destroy_image(var->mlx_connection, all->enemie.img_open);
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

void	font_clean5(char **map, t_textures *all, t_window *var)
{
	mlx_destroy_image(var->mlx_connection, all->font.img_open3);
	mlx_destroy_image(var->mlx_connection, all->font.img_open2);
	mlx_destroy_image(var->mlx_connection, all->font.img_open1);
	mlx_destroy_image(var->mlx_connection, all->font.img_open0);
	mlx_destroy_image(var->mlx_connection, all->enemie.img_open);
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
