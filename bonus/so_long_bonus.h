/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:27:14 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 11:43:48 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <string.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

typedef struct map_config
{
	int	enemies_count;
	int	reachable_c;
	int	**c_arr;
	int	all_collectables;
	int	winable;
	int	x_size;
	int	y_size;
	int	c_count;
	int	exit;
	int	enemie;
	int	player;
	int	player_position[2];
	int	**enemies_positions;
	int	exit_position[2];
}	t_m_config;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct wall
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_wall;

typedef struct field
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_field;

typedef struct collectable
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_collec;

typedef struct exit
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_exit;

typedef struct player_left
{
	void	*img_open;
	char	*path_open;
	int		img_width_open;
	int		img_height_open;
	void	*img_semi;
	char	*path_semi;
	int		img_width_semi;
	int		img_height_semi;
}	t_p_left;

typedef struct player_right
{
	void	*img_open;
	char	*path_open;
	int		img_width_open;
	int		img_height_open;
	void	*img_semi;
	char	*path_semi;
	int		img_width_semi;
	int		img_height_semi;
}	t_p_right;

typedef struct player_down
{
	void	*img_open;
	char	*path_open;
	int		img_width_open;
	int		img_height_open;
	void	*img_semi;
	char	*path_semi;
	int		img_width_semi;
	int		img_height_semi;
}	t_p_down;

typedef struct player_up
{
	void	*img_open;
	char	*path_open;
	int		img_width_open;
	int		img_height_open;
	void	*img_semi;
	char	*path_semi;
	int		img_width_semi;
	int		img_height_semi;
}	t_p_up;

typedef struct player
{
	t_p_left	player_left;
	t_p_right	player_right;
	t_p_up		player_up;
	t_p_down	player_down;
}	t_player;

typedef struct enemie
{
	void	*img_open;
	char	*path_open;
	int		img_width_open;
	int		img_height_open;
}	t_enemie;

typedef struct font
{
	void	*img_open1;
	char	*path_open1;
	int		img_width_open1;
	int		img_height_open1;
	void	*img_open2;
	char	*path_open2;
	int		img_width_open2;
	int		img_height_open2;
	void	*img_open3;
	char	*path_open3;
	int		img_width_open3;
	int		img_height_open3;
	void	*img_open4;
	char	*path_open4;
	int		img_width_open4;
	int		img_height_open4;
	void	*img_open5;
	char	*path_open5;
	int		img_width_open5;
	int		img_height_open5;
	void	*img_open6;
	char	*path_open6;
	int		img_width_open6;
	int		img_height_open6;
	void	*img_open7;
	char	*path_open7;
	int		img_width_open7;
	int		img_height_open7;
	void	*img_open8;
	char	*path_open8;
	int		img_width_open8;
	int		img_height_open8;
	void	*img_open9;
	char	*path_open9;
	int		img_width_open9;
	int		img_height_open9;
	void	*img_open0;
	char	*path_open0;
	int		img_width_open0;
	int		img_height_open0;
}	t_font;

typedef struct textures
{
	t_exit		exit;
	t_collec	collectable;
	t_field		field;
	t_wall		wall;
	t_player	player;
	t_enemie	enemie;
	t_font		font;
}	t_textures;

typedef struct window
{
	int			moves;
	char		last_key;
	int			got_all;
	int			collected;
	t_textures	all_textures;
	t_m_config	map_cnfg;
	char		**tmap;
	void		*mlx_connection;
	void		*mlx_window;
	t_data		image;
}	t_window;

// map config
void	get_map_config(t_m_config *map_config, char **map);

//map check
int		get_width(char *line, char **map);
int		get_lines(char **map, t_m_config *map_cnfg, int x_size);
// void is_valid_map(char **map);

void	move_left_right(t_window *var, t_textures *all, int x, int y);
void	move_up_down(t_window *var, t_textures *all, int x, int y);
void	get_fonts(t_textures *all, t_window *var);
void	player_image_opt(t_window *var, t_textures *all, int x, int y);
void	print_number_on_screen(char *nbr, t_textures *all, t_window *var);

//textures
void	init_textures(t_textures *all, t_window *var);
void	move_ghosts(t_window *var);
void	print_map_on_screen(char **map, t_window *var, t_textures *all);
void	is_winable(char **map, t_m_config *map_config);
char	*ft_itoa(int n);
//keys_hooks
int		key_hook(int keycode, t_window *var);

//parse
char	**map_copy(char **map, t_m_config *map_config);
char	**parse(int fd, char **av);
char	*ft_strdup1(const char *s);
void	enemies_position(char **map, t_m_config *map_cnfg);
void	is_right_extension(char *str);

//free
void	free_map(char **map);
int		close_window(t_window *var);
void	free_int_arr(int **arr, int size);
void	destroy_images(t_window *var);

#endif