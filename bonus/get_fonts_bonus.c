/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fonts_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:55:54 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/01 17:27:00 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_fonts1(char **map, t_textures *all, t_window *var)
{
	all->font.path_open0 = "textures/Fonts/0.xpm";
	all->font.img_open0 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open0, &all->font.img_width_open0,
			&all->font.img_height_open0);
	if (!all->font.img_open0)
		font_clean1(map, all, var);
	all->font.path_open1 = "textures/Fonts/1.xpm";
	all->font.img_open1 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open1, &all->font.img_width_open1,
			&all->font.img_height_open1);
	if (!all->font.img_open1)
		font_clean2(map, all, var);
	all->font.path_open2 = "textures/Fonts/2.xpm";
	all->font.img_open2 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open2, &all->font.img_width_open2,
			&all->font.img_height_open2);
	if (!all->font.img_open2)
		font_clean3(map, all, var);
	all->font.path_open3 = "textures/Fonts/3.xpm";
	all->font.img_open3 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open3, &all->font.img_width_open3,
			&all->font.img_height_open3);
	if (!all->font.img_open3)
		font_clean4(map, all, var);
}

void	get_fonts2(char **map, t_textures *all, t_window *var)
{
	all->font.path_open4 = "textures/Fonts/4.xpm";
	all->font.img_open4 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open4, &all->font.img_width_open4,
			&all->font.img_height_open4);
	if (!all->font.img_open4)
		font_clean5(map, all, var);
	all->font.path_open5 = "textures/Fonts/5.xpm";
	all->font.img_open5 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open5, &all->font.img_width_open5,
			&all->font.img_height_open5);
	if (!all->font.img_open5)
		font_clean6(map, all, var);
	all->font.path_open6 = "textures/Fonts/6.xpm";
	all->font.img_open6 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open6, &all->font.img_width_open6,
			&all->font.img_height_open6);
	if (!all->font.img_open6)
		font_clean7(map, all, var);
}

void	get_fonts(char **map, t_textures *all, t_window *var)
{
	get_fonts1(map, all, var);
	get_fonts2(map, all, var);
	all->font.path_open7 = "textures/Fonts/7.xpm";
	all->font.img_open7 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open7, &all->font.img_width_open7,
			&all->font.img_height_open7);
	if (!all->font.img_open7)
		font_clean8(map, all, var);
	all->font.path_open8 = "textures/Fonts/8.xpm";
	all->font.img_open8 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open8, &all->font.img_width_open8,
			&all->font.img_height_open8);
	if (!all->font.img_open8)
		font_clean9(map, all, var);
	all->font.path_open9 = "textures/Fonts/9.xpm";
	all->font.img_open9 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open9, &all->font.img_width_open9,
			&all->font.img_height_open9);
	if (!all->font.img_open9)
		font_clean10(map, all, var);
}
