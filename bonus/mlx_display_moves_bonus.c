/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_moves_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:43:33 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 10:36:24 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wich_number2(t_window *var, t_textures *all, char c, int *arr)
{
	if (c == '0')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open0, arr[0], arr[1]);
	if (c == '1')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open1, arr[0], arr[1]);
	if (c == '2')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open2, arr[0], arr[1]);
	if (c == '3')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open3, arr[0], arr[1]);
	if (c == '4')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open4, arr[0], arr[1]);
	if (c == '5')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open5, arr[0], arr[1]);
}

void	wich_number(t_window *var, t_textures *all, char c, int *arr)
{
	if ((c - '0') < 5)
		wich_number2(var, all, c, arr);
	if (c == '6')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open6, arr[0], arr[1]);
	if (c == '7')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open7, arr[0], arr[1]);
	if (c == '8')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open8, arr[0], arr[1]);
	if (c == '9')
		mlx_put_image_to_window(var->mlx_connection,
			var->mlx_window, all->font.img_open9, arr[0], arr[1]);
}

void	print_number_on_screen(char *nbr, t_textures *all, t_window *var)
{
	int	i;
	int	arr[2];

	i = 0;
	arr[0] = var->map_cnfg.x_size;
	arr[1] = var->map_cnfg.y_size;
	while (nbr[i])
	{
		wich_number(var, all, nbr[i], arr);
		i++;
		arr[0] += all->font.img_width_open0 + 3;
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
