/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:47 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 17:40:28 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left_right(t_window *var, t_textures *all, int x, int y)
{
	int	r;

	r = rand();
	if (var->last_key == 'D')
	{
		if (r % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection,
				var->mlx_window, all->player.player_right.img_semi, x, y);
		else
			mlx_put_image_to_window(var->mlx_connection,
				var->mlx_window, all->player.player_right.img_open, x, y);
	}
	if (var->last_key == 'A')
	{
		if (r % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection,
				var->mlx_window, all->player.player_left.img_semi, x, y);
		else
			mlx_put_image_to_window(var->mlx_connection,
				var->mlx_window, all->player.player_left.img_open, x, y);
	}
}

void	move_up_down(t_window *var, t_textures *all, int x, int y)
{
	int	r;

	r = rand();
	if (var->last_key == 'S')
	{
		if (r % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
				all->player.player_down.img_open, x, y);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
				all->player.player_down.img_semi, x, y);
	}
	if (var->last_key == 'W')
	{
		if (r % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
				all->player.player_up.img_semi, x, y);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
				all->player.player_up.img_open, x, y);
	}
}

void	player_image_opt(t_window *var, t_textures *all, int x, int y)
{
	if (var->last_key == 'D' || var->last_key == 'A')
		move_left_right(var, all, x, y);
	if (var->last_key == 'S' || var->last_key == 'W')
		move_up_down(var, all, x, y);
	if (var->last_key == '.')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
			all->player.player_left.img_semi, x, y);
}

void	put_image(char c, t_window *var, int x_offset, int y_offset)
{
	if (c == '1')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, var->all_textures.wall.img, x_offset, y_offset);
	if (c == 'P')
		player_image_opt(var, &var->all_textures, x_offset, y_offset);
	if (c == 'C')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
			var->all_textures.collectable.img, x_offset, y_offset);
	if (c == 'E' && var->got_all == 1)
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
			var->all_textures.exit.img, x_offset, y_offset);
}

void	print_map_on_screen(char **map, t_window *var, t_textures *all)
{
	int	x_offset;
	int	y_offset;
	int	x;
	int	y;

	y_offset = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		x_offset = 0;
		while (map[y][++x + 1])
		{
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
				all->field.img, x_offset, y_offset);
			put_image(map[y][x], var, x_offset, y_offset);
			x_offset += all->field.img_width;
		}
		y_offset += all->field.img_height;
	}
	if (map[y - 1][x] == '1')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window,
			all->wall.img, x_offset, y_offset - all->field.img_height);
	x_offset -= all->field.img_width;
	print_moves_nl(var->moves);
}
