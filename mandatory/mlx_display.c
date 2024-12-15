/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:47 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/14 16:19:57 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_image_options(t_window *var, t_textures *all, int x_offset, int y_offset, int rndm)
{
	if (var->last_key == 'D')
	{
		if (rndm % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_right.img_semi, x_offset, y_offset);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_right.img_open, x_offset, y_offset);
	}
	if (var->last_key == 'A')
	{
		if (rndm % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_left.img_semi, x_offset, y_offset);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_left.img_open, x_offset, y_offset);
	}
	if (var->last_key == 'S')
	{
		if (rndm % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_down.img_open, x_offset, y_offset);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_down.img_semi, x_offset, y_offset);
	}
	if (var->last_key == 'W')
	{
		if (rndm % 2 == 0)
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_up.img_semi, x_offset, y_offset);
		else
			mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_up.img_open, x_offset, y_offset);
	}
	if (var->last_key == '.')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_left.img_semi, x_offset, y_offset);
}

void	print_map_on_screen(char **map, t_m_config map_config, t_window *var, t_textures *all)
{
	int	x_offset = 0;
	int	y_offset = 0;

    int x;
    int rndm;
    int y = 0;
    while(map[y])
    {
        x = 0;
        x_offset = 0;
        while(map[y][x + 1])
        {
            rndm = rand();
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->field.img, x_offset, y_offset);
            if (map[y][x] == '1')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->wall.img, x_offset, y_offset);
            if (map[y][x] == 'P')
				player_image_options(var, all, x_offset, y_offset, rndm);
            if (map[y][x] == 'C')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->collectable.img, x_offset, y_offset);
            if (map[y][x] == 'E' && var->got_all == 1)
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->exit.img, x_offset, y_offset);
            x_offset += all->field.img_width;
            x++;
        }
        y_offset += all->field.img_height;
        y++;
    }
    if (map[y - 1][x] == '1')
        mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->wall.img, x_offset, y_offset - all->field.img_height);
    x_offset -= all->field.img_width;
	ft_putnbr(var->moves);
	write(1, "\n", 1);
}
