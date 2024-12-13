#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include "minilibx-linux/mlx.h"
// #include "minilibx-linux/mlx_int.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#define WIDTH 1400
#define HEIGHT 750
#define X 50
#define Y 50

int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

typedef struct map_config
{
    int reachable_c;
    int **c_arr;
    int all_collectables;
    int winable;
    int x_size;
    int y_size;
    int c_count;
    int exit;
    int enemy;
    int player;
    int player_position[2];//0 -> y | 1 -> x
    int exit_position[2];//0 -> y | 1 -> x
}   t_m_config;

typedef struct parse
{
    char *line;
    struct parse *next;
}   t_parse;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct wall
{
    void *img;
    char *path;
    int img_width;
    int img_height;
}   t_wall;

typedef struct field
{
    void *img;
    char *path;
    int img_width;
    int img_height;
}   t_field;


typedef struct collectable
{
    void *img;
    char *path;
    int img_width;
    int img_height;
}   t_collec;

typedef struct exit
{
    void *img;
    char *path;
    int img_width;
    int img_height;
}   t_exit;

typedef struct player_left
{
    void *img_open;
    char *path_open;
    int img_width_open;
    int img_height_open;
    void *img_semi;
    char *path_semi;
    int img_width_semi;
    int img_height_semi;
}   t_p_left;

typedef struct player_right
{
    void *img_open;
    char *path_open;
    int img_width_open;
    int img_height_open;
    void *img_semi;
    char *path_semi;
    int img_width_semi;
    int img_height_semi;
}   t_p_right;

typedef struct player_down
{
    void *img_open;
    char *path_open;
    int img_width_open;
    int img_height_open;
    void *img_semi;
    char *path_semi;
    int img_width_semi;
    int img_height_semi;
}   t_p_down;

typedef struct player_up
{
    void *img_open;
    char *path_open;
    int img_width_open;
    int img_height_open;
    void *img_semi;
    char *path_semi;
    int img_width_semi;
    int img_height_semi;
}   t_p_up;

typedef struct player_dead
{
    void *img_open1;
    char *path_open1;
    int img_width_open1;
    int img_height_open1;
    void *img_open2;
    char *path_open2;
    int img_width_open2;
    int img_height_open2;
    void *img_open3;
    char *path_open3;
    int img_width_open3;
    int img_height_open3;
    void *img_open4;
    char *path_open4;
    int img_width_open4;
    int img_height_open4;
    void *img_open5;
    char *path_open5;
    int img_width_open5;
    int img_height_open5;
    void *img_open6;
    char *path_open6;
    int img_width_open6;
    int img_height_open6;
    void *img_open7;
    char *path_open7;
    int img_width_open7;
    int img_height_open7;
    void *img_open8;
    char *path_open8;
    int img_width_open8;
    int img_height_open8;
    void *img_open9;
    char *path_open9;
    int img_width_open9;
    int img_height_open9;
    void *img_open10;
    char *path_open10;
    int img_width_open10;
    int img_height_open10;
    void *img_open11;
    char *path_open11;
    int img_width_open11;
    int img_height_open11;
}   t_p_dead;

typedef struct player //player --> dying --> alive --> alive left
{
    t_p_dead player_dead;
    t_p_left player_left;
    t_p_right player_right;
    t_p_up player_up; 
    t_p_down player_down;
}   t_player;

typedef struct enemy
{
    void *img_open;
    char *path_open;
    int img_width_open;
    int img_height_open;
}   t_enemy;

typedef struct font
{
    void *img_open1;
    char *path_open1;
    int img_width_open1;
    int img_height_open1;
    void *img_open2;
    char *path_open2;
    int img_width_open2;
    int img_height_open2;
    void *img_open3;
    char *path_open3;
    int img_width_open3;
    int img_height_open3;
    void *img_open4;
    char *path_open4;
    int img_width_open4;
    int img_height_open4;
    void *img_open5;
    char *path_open5;
    int img_width_open5;
    int img_height_open5;
    void *img_open6;
    char *path_open6;
    int img_width_open6;
    int img_height_open6;
    void *img_open7;
    char *path_open7;
    int img_width_open7;
    int img_height_open7;
    void *img_open8;
    char *path_open8;
    int img_width_open8;
    int img_height_open8;
    void *img_open9;
    char *path_open9;
    int img_width_open9;
    int img_height_open9;
    void *img_open0;
    char *path_open0;
    int img_width_open0;
    int img_height_open0;
}   t_font;

typedef struct textures
{
    t_exit exit;
    t_collec collectable;
    t_field field;
    t_wall wall;
    t_player player;
    t_enemy enemy;
    t_font font;
}   t_textures;

typedef struct window
{
    int moves;
    char last_key;
    int got_all;
    int collected;
    t_textures all_textures;
    t_m_config map_cnfg;
    char **tmap;
    void *mlx_connection;
    void *mlx_window;
    t_data image;
}   t_window;

// map config
void get_map_config(t_m_config *map_config, char **map);

//map check
// void is_valid_map(char **map);

//parse
char **map_copy(char **map, t_m_config *map_config);
char **parse(int fd);
void ft_lst_addback(t_parse **lst, char *line);
int ft_lst_size(t_parse *lst);
char	*ft_strdup1(const char *s);

#endif