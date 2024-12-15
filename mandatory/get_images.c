/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:10:05 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/15 18:55:53 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init1(t_textures *all, t_window *var)
{
	all->player.player_right.path_semi = "rsrcs/pacman/pac_semi_right.xpm";
	all->player.player_right.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_right.path_semi,
			&all->player.player_right.img_width_semi,
			&all->player.player_right.img_height_semi);
	all->player.player_right.path_open = "rsrcs/pacman/pac_open_right.xpm";
	all->player.player_right.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_right.path_open,
			&all->player.player_right.img_width_open,
			&all->player.player_right.img_height_open);
	all->player.player_left.path_semi = "rsrcs/pacman/pac_semi_left.xpm";
	all->player.player_left.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_left.path_semi,
			&all->player.player_left.img_width_semi,
			&all->player.player_left.img_height_semi);
	all->player.player_left.path_open = "rsrcs/pacman/pac_open_left.xpm";
	all->player.player_left.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_left.path_open,
			&all->player.player_left.img_width_open,
			&all->player.player_left.img_height_open);
}

void	player_init(t_textures *all, t_window *var)
{
	player_init1(all, var);
	all->player.player_up.path_semi = "rsrcs/pacman/pac_semi_up.xpm";
	all->player.player_up.img_semi = mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_up.path_semi,
			&all->player.player_up.img_width_semi,
			&all->player.player_up.img_height_semi);
	all->player.player_up.path_open = "rsrcs/pacman/pac_open_up.xpm";
	all->player.player_up.img_open = mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_up.path_open,
			&all->player.player_up.img_width_open,
			&all->player.player_up.img_height_open);
	all->player.player_down.path_semi = "rsrcs/pacman/pac_semi_down.xpm";
	all->player.player_down.img_semi
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_down.path_semi,
			&all->player.player_down.img_width_semi,
			&all->player.player_down.img_height_semi);
	all->player.player_down.path_open = "rsrcs/pacman/pac_open_down.xpm";
	all->player.player_down.img_open
		= mlx_xpm_file_to_image(var->mlx_connection,
			all->player.player_down.path_open,
			&all->player.player_down.img_width_open,
			&all->player.player_down.img_height_open);
}

void	init_textures(t_textures *all, t_window *var)
{
	var->moves = 0;
	var->collected = 0;
	var->got_all = 0;
	var->last_key = '.';
	all->exit.path = "rsrcs/exit.xpm";
	all->exit.img = mlx_xpm_file_to_image(var->mlx_connection, all->exit.path,
			&all->exit.img_width, &all->exit.img_height);
	all->collectable.path = "rsrcs/op_food.xpm";
	all->collectable.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->collectable.path, &all->collectable.img_width,
			&all->collectable.img_height);
	player_init(all, var);
	all->wall.path = "rsrcs/1.0.xpm";
	all->wall.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->wall.path, &all->wall.img_width, &all->wall.img_height);
	all->field.path = "rsrcs/1.1.xpm";
	all->field.img = mlx_xpm_file_to_image(var->mlx_connection,
			all->field.path, &all->field.img_width, &all->field.img_height);
}

int	lines_count(int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			get_next_line(-2);
	}
	return (y);
}

char	**parse(int fd, char **av)
{
	char		**map;
	static int	t_y;
	int			y;
	char		*line;

	if (fd == -1)
		exit(1);
	y = lines_count(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	map = malloc(sizeof(char *) * (y + 1));
	line = get_next_line(fd);
	map[t_y++] = line;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			get_next_line(-2);
			break ;
		}
		map[t_y++] = line;
	}
	map[t_y] = NULL;
	return (map);
}
