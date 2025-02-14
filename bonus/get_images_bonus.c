/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:10:05 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/02 13:03:14 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_init2(char **map, t_textures *all, t_window *var)
{
	all->player.player_left.path_open = "textures/pacman/pac_open_left.xpm";
	all->player.player_left.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_left.path_open,
			&all->player.player_left.img_width_open,
			&all->player.player_left.img_height_open);
	if (!all->player.player_left.img_semi)
		clean_image4(map, all, var);
	all->player.player_up.path_semi = "textures/pacman/pac_semi_up.xpm";
	all->player.player_up.img_semi = mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_up.path_semi,
			&all->player.player_up.img_width_semi,
			&all->player.player_up.img_height_semi);
	if (!all->player.player_up.img_semi)
		clean_image5(map, all, var);
}

void	player_init1(char **map, t_textures *all, t_window *var)
{
	all->player.player_right.path_semi = "textures/pacman/pac_semi_right.xpm";
	all->player.player_right.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_right.path_semi,
			&all->player.player_right.img_width_semi,
			&all->player.player_right.img_height_semi);
	if (!all->player.player_right.img_semi)
		clean_image1(map, all, var);
	all->player.player_right.path_open = "textures/pacman/pac_open_right.xpm";
	all->player.player_right.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_right.path_open,
			&all->player.player_right.img_width_open,
			&all->player.player_right.img_height_open);
	if (!all->player.player_right.img_open)
		clean_image2(map, all, var);
	all->player.player_left.path_semi = "textures/pacman/pac_semi_left.xpm";
	all->player.player_left.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_left.path_semi,
			&all->player.player_left.img_width_semi,
			&all->player.player_left.img_height_semi);
	if (!all->player.player_left.img_semi)
		clean_image3(map, all, var);
	player_init2(map, all, var);
}

void	player_init3(char **map, t_textures *all, t_window *var)
{
	all->wall.path = "textures/1.0.xpm";
	all->wall.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->wall.path, &all->wall.img_width,
			&all->wall.img_height);
	if (!all->wall.img)
		clean_image9(map, all, var);
	all->field.path = "textures/1.1.xpm";
	all->field.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->field.path, &all->field.img_width,
			&all->field.img_height);
	if (!all->field.img)
		clean_image10(map, all, var);
	all->enemie.path_open = "textures/ghost.xpm";
	all->enemie.img_open = mlx_xpm_file_to_image(var->mlx_connection,
			all->enemie.path_open, &all->enemie.img_width_open,
			&all->enemie.img_height_open);
	if (!all->enemie.img_open)
		clean_ghost(map, all, var);
	get_fonts(map, all, var);
}

void	player_init(char **map, t_textures *all, t_window *var)
{
	player_init1(map, all, var);
	all->player.player_up.path_open = "textures/pacman/pac_open_up.xpm";
	all->player.player_up.img_open = mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_up.path_open,
			&all->player.player_up.img_width_open,
			&all->player.player_up.img_height_open);
	if (!all->player.player_up.img_open)
		clean_image6(map, all, var);
	all->player.player_down.path_semi = "textures/pacman/pac_semi_down.xpm";
	all->player.player_down.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_down.path_semi,
			&all->player.player_down.img_width_semi,
			&all->player.player_down.img_height_semi);
	if (!all->player.player_down.img_semi)
		clean_image7(map, all, var);
	all->player.player_down.path_open = "textures/pacman/pac_open_down.xpm";
	all->player.player_down.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_down.path_open,
			&all->player.player_down.img_width_open,
			&all->player.player_down.img_height_open);
	if (!all->player.player_down.img_open)
		clean_image8(map, all, var);
	player_init3(map, all, var);
}

void	init_textures(char **map, t_textures *all, t_window *var)
{
	var->moves = 0;
	var->collected = 0;
	var->got_all = 0;
	var->last_key = '.';
	all->exit.path = "textures/exit.xpm";
	all->exit.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->exit.path, &all->exit.img_width,
			&all->exit.img_height);
	if (!all->exit.img)
		return (mlx_destroy_display(var->mlx_connection),
			free(var->mlx_connection),
			free_map(map), free_int_arr(var->map_cnfg->e_p,
				var->map_cnfg->enemies_count), exit(1));
	all->collectable.path = "textures/op_food.xpm";
	all->collectable.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->collectable.path, &all->collectable.img_width,
			&all->collectable.img_height);
	if (!all->collectable.img)
		return (mlx_destroy_image(var->mlx_connection, all->exit.img),
			mlx_destroy_display(var->mlx_connection), free(var->mlx_connection),
			free_int_arr(var->map_cnfg->e_p, var->map_cnfg->enemies_count),
			free_map(map), exit(1));
	player_init(map, all, var);
}
