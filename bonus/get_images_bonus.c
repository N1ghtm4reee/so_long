/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:10:05 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/14 17:11:20 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void player_init(t_textures *all, t_window *var)
{
    var->last_key = '.';
    all->player.player_right.path_semi = "rsrcs/pacman/pac_semi_right.xpm";
    all->player.player_right.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_right.path_semi, &all->player.player_right.img_width_semi, &all->player.player_right.img_height_semi);
    all->player.player_right.path_open = "rsrcs/pacman/pac_open_right.xpm";
    all->player.player_right.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_right.path_open, &all->player.player_right.img_width_open, &all->player.player_right.img_height_open);
    all->player.player_left.path_semi = "rsrcs/pacman/pac_semi_left.xpm";
    all->player.player_left.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_left.path_semi, &all->player.player_left.img_width_semi, &all->player.player_left.img_height_semi);
    all->player.player_left.path_open = "rsrcs/pacman/pac_open_left.xpm";
    all->player.player_left.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_left.path_open, &all->player.player_left.img_width_open, &all->player.player_left.img_height_open);
    all->player.player_up.path_semi = "rsrcs/pacman/pac_semi_up.xpm";
    all->player.player_up.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_up.path_semi, &all->player.player_up.img_width_semi, &all->player.player_up.img_height_semi);
    all->player.player_up.path_open = "rsrcs/pacman/pac_open_up.xpm";
    all->player.player_up.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_up.path_open, &all->player.player_up.img_width_open, &all->player.player_up.img_height_open);
    all->player.player_down.path_semi = "rsrcs/pacman/pac_semi_down.xpm";
    all->player.player_down.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_down.path_semi, &all->player.player_down.img_width_semi, &all->player.player_down.img_height_semi);
    all->player.player_down.path_open = "rsrcs/pacman/pac_open_down.xpm";
    all->player.player_down.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_down.path_open, &all->player.player_down.img_width_open, &all->player.player_down.img_height_open);
}

void init_textures(t_textures *all, t_window *var)
{
    var->moves = 0;
    var->collected = 0;
    var->got_all = 0;
    all->exit.path = "rsrcs/exit.xpm";
    all->exit.img = mlx_xpm_file_to_image(var->mlx_connection, all->exit.path, &all->exit.img_width, &all->exit.img_height);
    all->collectable.path = "rsrcs/op_food.xpm";
    all->collectable.img = mlx_xpm_file_to_image(var->mlx_connection, all->collectable.path, &all->collectable.img_width, &all->collectable.img_height);
    player_init(all, var);
    all->wall.path = "rsrcs/1.0.xpm";
    all->wall.img = mlx_xpm_file_to_image(var->mlx_connection, all->wall.path, &all->wall.img_width, &all->wall.img_height);
    all->field.path = "rsrcs/1.1.xpm";
    all->field.img = mlx_xpm_file_to_image(var->mlx_connection, all->field.path, &all->field.img_width, &all->field.img_height);
    all->enemy.path_open = "rsrcs/ghost.xpm";
    all->enemy.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->enemy.path_open, &all->enemy.img_width_open, &all->enemy.img_height_open);
    all->font.path_open0 = "rsrcs/Fonts/0.xpm";
    all->font.img_open0 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open0, &all->font.img_width_open0, &all->font.img_height_open0);
    all->font.path_open1 = "rsrcs/Fonts/1.xpm";
    all->font.img_open1 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open1, &all->font.img_width_open1, &all->font.img_height_open1);
    all->font.path_open2 = "rsrcs/Fonts/2.xpm";
    all->font.img_open2 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open2, &all->font.img_width_open2, &all->font.img_height_open2);
    all->font.path_open3 = "rsrcs/Fonts/3.xpm";
    all->font.img_open3 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open3, &all->font.img_width_open3, &all->font.img_height_open3);
    all->font.path_open4 = "rsrcs/Fonts/4.xpm";
    all->font.img_open4 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open4, &all->font.img_width_open4, &all->font.img_height_open4);
    all->font.path_open5 = "rsrcs/Fonts/5.xpm";
    all->font.img_open5 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open5, &all->font.img_width_open5, &all->font.img_height_open5);
    all->font.path_open6 = "rsrcs/Fonts/6.xpm";
    all->font.img_open6 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open6, &all->font.img_width_open6, &all->font.img_height_open6);
    all->font.path_open7 = "rsrcs/Fonts/7.xpm";
    all->font.img_open7 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open7, &all->font.img_width_open7, &all->font.img_height_open7);
    all->font.path_open8 = "rsrcs/Fonts/8.xpm";
    all->font.img_open8 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open8, &all->font.img_width_open8, &all->font.img_height_open8);
    all->font.path_open9 = "rsrcs/Fonts/9.xpm";
    all->font.img_open9 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open9, &all->font.img_width_open9, &all->font.img_height_open9);
}
