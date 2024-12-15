#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

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

typedef struct player //player --> dying --> alive --> alive left
{
    t_p_left player_left;
    t_p_right player_right;
    t_p_up player_up; 
    t_p_down player_down;
}   t_player;

typedef struct textures
{
    t_exit exit;
    t_collec collectable;
    t_field field;
    t_wall wall;
    t_player player;
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
int get_width(char *line);
int get_lines(char **map, t_m_config *map_cnfg, int x_size);
// void is_valid_map(char **map);

//textures
void init_textures(t_textures *all, t_window *var);
void print_map_on_screen(char **map, t_m_config map_config, t_window *var, t_textures *all);
void is_winable(char **map, t_m_config *map_config);
char	*ft_itoa(int n);
//keys_hooks
int key_hook(int keycode, t_window *var);

//parse
char **map_copy(char **map, t_m_config *map_config);
char	**parse(int fd, char **av);
void ft_lst_addback(t_parse **lst, char *line);
int ft_lst_size(t_parse *lst);
char	*ft_strdup1(const char *s);

//free
void free_list(t_parse **lst);
void free_map(char **map);
int close_window(t_window *var);


//
void	ft_putnbr(int nb);

#endif