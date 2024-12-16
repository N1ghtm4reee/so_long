/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fonts_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:55:54 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 11:01:57 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_fonts1(t_textures *all, t_window *var)
{
	all->font.path_open0 = "rsrcs/Fonts/0.xpm";
	all->font.img_open0 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open0, &all->font.img_width_open0,
			&all->font.img_height_open0);
	all->font.path_open1 = "rsrcs/Fonts/1.xpm";
	all->font.img_open1 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open1, &all->font.img_width_open1,
			&all->font.img_height_open1);
	all->font.path_open2 = "rsrcs/Fonts/2.xpm";
	all->font.img_open2 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open2, &all->font.img_width_open2,
			&all->font.img_height_open2);
	all->font.path_open3 = "rsrcs/Fonts/3.xpm";
	all->font.img_open3 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open3, &all->font.img_width_open3,
			&all->font.img_height_open3);
}

void	get_fonts(t_textures *all, t_window *var)
{
	get_fonts1(all, var);
	all->font.path_open4 = "rsrcs/Fonts/4.xpm";
	all->font.img_open4 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open4, &all->font.img_width_open4,
			&all->font.img_height_open4);
	all->font.path_open5 = "rsrcs/Fonts/5.xpm";
	all->font.img_open5 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open5, &all->font.img_width_open5,
			&all->font.img_height_open5);
	all->font.path_open6 = "rsrcs/Fonts/6.xpm";
	all->font.img_open6 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open6, &all->font.img_width_open6,
			&all->font.img_height_open6);
	all->font.path_open7 = "rsrcs/Fonts/7.xpm";
	all->font.img_open7 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open7, &all->font.img_width_open7,
			&all->font.img_height_open7);
	all->font.path_open8 = "rsrcs/Fonts/8.xpm";
	all->font.img_open8 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open8, &all->font.img_width_open8,
			&all->font.img_height_open8);
	all->font.path_open9 = "rsrcs/Fonts/9.xpm";
	all->font.img_open9 = mlx_xpm_file_to_image(var->mlx_connection,
			all->font.path_open9, &all->font.img_width_open9,
			&all->font.img_height_open9);
}
