/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:47 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 14:36:51 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wich_number(t_window *var, t_textures *all, char c, int x_offset, int y_offset)
{
	if (c == '0')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open0, x_offset, y_offset);
	if (c == '1')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open1, x_offset, y_offset);
	if (c == '2')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open2, x_offset, y_offset);
	if (c == '3')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open3, x_offset, y_offset);
	if (c == '4')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open4, x_offset, y_offset);
	if (c == '5')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open5, x_offset, y_offset);
	if (c == '6')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open6, x_offset, y_offset);
	if (c == '7')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open7, x_offset, y_offset);
	if (c == '8')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open8, x_offset, y_offset);
	if (c == '9')
		mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open9, x_offset, y_offset);
}

void	print_number_on_screen(char *nbr, t_textures *all, t_window *var)
{
	int	i;
	int	x_offset;
	int	y_offset;

	i = 0;
	x_offset = var->map_cnfg.x_size;
	y_offset = var->map_cnfg.y_size;
	while (nbr[i])
	{
		wich_number(var, all, nbr[i], x_offset, y_offset);
		i++;
		x_offset += all->font.img_width_open0 + 3;
	}
}

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
            if (map[y][x] == 'F')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->enemie.img_open, x_offset, y_offset);
            x_offset += all->field.img_width;
            x++;
        }
        y_offset += all->field.img_height;
        y++;
    }
    if (map[y - 1][x] == '1')
        mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->wall.img, x_offset, y_offset - all->field.img_height);
    x_offset -= all->field.img_width;
    char *nbr = ft_itoa(var->moves);
    print_number_on_screen(nbr, all, var);
	free(nbr);
}
