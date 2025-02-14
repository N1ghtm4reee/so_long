/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_image2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:32:41 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/01 17:53:30 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_image6(char **map, t_textures *all, t_window *var)
{
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
	exit(1);
}

void	clean_image7(char **map, t_textures *all, t_window *var)
{
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
	exit(1);
}

void	clean_image8(char **map, t_textures *all, t_window *var)
{
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
	exit(1);
}

void	clean_image9(char **map, t_textures *all, t_window *var)
{
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
	exit(1);
}

void	clean_image10(char **map, t_textures *all, t_window *var)
{
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
	exit(1);
}
