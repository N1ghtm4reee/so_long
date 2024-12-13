#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void move_left(char **map, t_m_config *map_config)
{
    if (map[map_config->player_position[0]][map_config->player_position[1] - 1] != '1')
    {
        if (map[map_config->player_position[0]][map_config->player_position[1] - 1] == '0' || map[map_config->player_position[0]][map_config->player_position[1] - 1] == 'C')
        {
            map[map_config->player_position[0]][map_config->player_position[1] - 1] = 'P';
            map[map_config->player_position[0]][map_config->player_position[1] - 1] = '0';
        }
    }
}

static char	*ft_itoa2(char *d, int len, long nb)
{
	d[len] = '\0';
	if (nb == 0)
	{
		d[0] = '0';
		return (d);
	}
	if (nb < 0)
	{
		nb = -nb;
		d[0] = '-';
	}
	while (nb > 0)
	{
		d[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*d;

	nb = n;
	len = 0;
	if (n <= 0)
		len++;
	if (n == 0)
		return (ft_strdup1("0"));
	while (n)
	{
		len++;
		n /= 10;
	}
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	d = ft_itoa2(d, len, nb);
	return (d);
}

void print_number_on_screen(char *nbr, t_textures *all, t_window *var)
{
    int i = 0;
    int x_offset = var->map_cnfg.x_size;
    int y_offset = var->map_cnfg.y_size;
    while(nbr[i])
    {
        if (nbr[i] == '0')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open0, x_offset, y_offset);
        if (nbr[i] == '1')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open1, x_offset, y_offset);
        if (nbr[i] == '2')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open2, x_offset, y_offset);
        if (nbr[i] == '3')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open3, x_offset, y_offset);
        if (nbr[i] == '4')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open4, x_offset, y_offset);
        if (nbr[i] == '5')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open5, x_offset, y_offset);
        if (nbr[i] == '6')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open6, x_offset, y_offset);
        if (nbr[i] == '7')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open7, x_offset, y_offset);
        if (nbr[i] == '8')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open8, x_offset, y_offset);
        if (nbr[i] == '9')
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->font.img_open9, x_offset, y_offset);
        i++;
        x_offset += all->font.img_width_open0 + 3;
    }
}

void print_map_on_screen(char **map, t_m_config map_config, t_window *var, t_textures *all)
{
    int x_offset = 0;
    int y_offset = 0;

    int x;
    int y = 0;
    while(map[y])
    {
        x = 0;
        x_offset = 0;
        while(map[y][x + 1])
        {
            mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->field.img, x_offset, y_offset);
            if (map[y][x] == '1')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->wall.img, x_offset, y_offset);
            if (map[y][x] == 'P')
            {
                if (var->last_key == 'D')
                    mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_right.img_semi, x_offset, y_offset);
                if (var->last_key == 'A')
                    mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_left.img_semi, x_offset, y_offset);
                if (var->last_key == 'S')
                    mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_down.img_semi, x_offset, y_offset);
                if (var->last_key == 'W')
                    mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_up.img_semi, x_offset, y_offset);
                if (var->last_key == '.')
                    mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->player.player_left.img_semi, x_offset, y_offset);
            }
            if (map[y][x] == 'C')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->collectable.img, x_offset, y_offset);
            if (map[y][x] == 'E' && var->got_all == 1)
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->exit.img, x_offset, y_offset);
            if (map[y][x] == 'F')
                mlx_put_image_to_window(var->mlx_connection, var->mlx_window, all->enemy.img_open, x_offset, y_offset);
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
}

int key_hook(int keycode, t_window *var)
{
    int y;
    int x;
    int player_x = var->map_cnfg.player_position[1];
    int player_y = var->map_cnfg.player_position[0];
    if (keycode == 113 || 65307 == keycode)//q
    {
        mlx_destroy_window(var->mlx_connection, var->mlx_window);
        exit(0);
    }
    if (keycode == 97)//move left a
    {
        if (var->tmap[player_y][player_x - 1] != '1' || (var->tmap[player_y][player_x - 1] == 'E' && var->got_all == 1))
        {
            if (var->tmap[player_y][player_x - 1] == 'F')
            {
                write(1, "TRY AGAIN\n", 10);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y][player_x - 1] == 'E')
            {
                write(1, "YOU WON!\n", 9);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y][player_x - 1] == '0' || var->tmap[player_y][player_x - 1] == 'C')
            {
                if (var->tmap[player_y][player_x - 1] == 'C')
                    var->collected++;
                var->tmap[player_y][player_x] = '0';
                var->tmap[player_y][player_x - 1] = 'P';
            }
            var->map_cnfg.player_position[1]--;
            var->last_key = 'A';
            var->moves++;
        }
    }
    else if (keycode == 100)//move right d
    {
        if (var->tmap[player_y][player_x + 1] != '1' || (var->tmap[player_y][player_x + 1] == 'E' && var->got_all == 1))
        {
            if (var->tmap[player_y][player_x + 1] == 'F')
            {
                write(1, "TRY AGAIN\n", 10);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
                if (var->tmap[player_y][player_x + 1] == 'E') 
                {
                    write(1, "YOU WON!\n", 9);
                    mlx_destroy_window(var->mlx_connection, var->mlx_window);
                    exit(0);
                }
            if (var->tmap[player_y][player_x + 1] == '0' || var->tmap[player_y][player_x + 1] == 'C')
            {
                if (var->tmap[player_y][player_x + 1] == 'C')
                    var->collected++;
                var->tmap[player_y][player_x] = '0';
                var->tmap[player_y][player_x + 1] = 'P';
            }
            var->map_cnfg.player_position[1]++;
            var->last_key = 'D';
            var->moves++;
        }
    }
    else if (keycode == 119)//move up
    {
        if (var->tmap[player_y - 1][player_x] != '1' || (var->tmap[player_y - 1][player_x] == 'E' && var->got_all == 1))
        {
            if (var->tmap[player_y - 1][player_x] == 'F')
            {
                write(1, "TRY AGAIN\n", 10);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y - 1][player_x] == 'E')
            {
                write(1, "YOU WON!\n", 9);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y - 1][player_x] == '0' || var->tmap[player_y - 1][player_x] == 'C')
            {
                if (var->tmap[player_y - 1][player_x] == 'C')
                    var->collected++;
                var->tmap[player_y][player_x] = '0';
                var->tmap[player_y - 1][player_x] = 'P';
            }
            var->map_cnfg.player_position[0]--;
            var->last_key = 'W';
            var->moves++;
        }
    }
    if (keycode == 115)//move down
    {
        if (var->tmap[player_y + 1][player_x] != '1' || (var->tmap[player_y + 1][player_x] == 'E' && var->got_all == 1))
        {
            if (var->tmap[player_y + 1][player_x] == 'F')
            {
                write(1, "TRY AGAIN\n", 10);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y + 1][player_x] == 'E')
            {
                write(1, "YOU WON!\n", 9);
                mlx_destroy_window(var->mlx_connection, var->mlx_window);
                exit(0);
            }
            if (var->tmap[player_y + 1][player_x] == '0' || var->tmap[player_y + 1][player_x] == 'C')
            {
                if (var->tmap[player_y + 1][player_x] == 'C')
                    var->collected++;
                var->tmap[player_y][player_x] = '0';
                var->tmap[player_y + 1][player_x] = 'P';
            }
            var->map_cnfg.player_position[0]++;
            var->last_key = 'S';
            var->moves++;
        }
    }
    if (var->collected == var->map_cnfg.c_count)
        var->got_all = 1;
    print_map_on_screen(var->tmap, var->map_cnfg, var, &var->all_textures);
    return 0;
}

void player_init(t_textures *all, t_window *var)
{
    var->last_key = '.';
    all->player.player_right.path_semi = "rsrcs/pacman/pac_semi_right.xpm";
    all->player.player_right.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_right.path_semi, &all->player.player_right.img_width_semi, &all->player.player_right.img_height_semi);
    all->player.player_right.path_open = "rsrcs/pacman/pac_open_right.xpm";
    all->player.player_right.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_right.path_open, &all->player.player_right.img_width_open, &all->player.player_right.img_height_open);
    all->player.player_left.path_semi = "rsrcs/pacman/pac_semi_left.xpm";
    all->player.player_left.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_left.path_semi, &all->player.player_left.img_width_semi, &all->player.player_left.img_height_semi);
    all->player.player_left.path_open = "rsrcs/pacman/pac_open_left.xpm";
    all->player.player_left.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_left.path_open, &all->player.player_left.img_width_open, &all->player.player_left.img_height_open);
    all->player.player_up.path_semi = "rsrcs/pacman/pac_semi_up.xpm";
    all->player.player_up.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_up.path_semi, &all->player.player_up.img_width_semi, &all->player.player_up.img_height_semi);
    all->player.player_up.path_open = "rsrcs/pacman/pac_open_up.xpm";
    all->player.player_up.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_up.path_open, &all->player.player_up.img_width_open, &all->player.player_up.img_height_open);
    all->player.player_down.path_semi = "rsrcs/pacman/pac_semi_down.xpm";
    all->player.player_down.img_semi = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_down.path_semi, &all->player.player_down.img_width_semi, &all->player.player_down.img_height_semi);
    all->player.player_down.path_open = "rsrcs/pacman/pac_open_down.xpm";
    all->player.player_down.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->player.player_down.path_open, &all->player.player_down.img_width_open, &all->player.player_down.img_height_open);
}

void init_textures(t_textures *all, t_window *var)
{
    var->moves = 0;
    var->collected = 0;
    var->got_all = 0;
    all->exit.path = "rsrcs/exit.xpm";
    all->exit.img = mlx_xpm_file_to_image(var->mlx_connection, all->exit.path, &all->exit.img_width, &all->exit.img_height);
    all->collectable.path = "rsrcs/op_food.xpm";
    all->collectable.img = mlx_xpm_file_to_image(var->mlx_connection, all->collectable.path, &all->collectable.img_width, &all->collectable.img_height);
    player_init(all, var);
    all->wall.path = "rsrcs/1.0.xpm";
    all->wall.img = mlx_xpm_file_to_image(var->mlx_connection, all->wall.path, &all->wall.img_width, &all->wall.img_height);
    all->field.path = "rsrcs/1.1.xpm";
    all->field.img = mlx_xpm_file_to_image(var->mlx_connection, all->field.path, &all->field.img_width, &all->field.img_height);
    all->enemy.path_open = "rsrcs/ghost.xpm";
    all->enemy.img_open = mlx_xpm_file_to_image(var->mlx_connection, all->enemy.path_open, &all->enemy.img_width_open, &all->enemy.img_height_open);
    all->font.path_open0 = "rsrcs/Fonts/0.xpm";
    all->font.img_open0 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open0, &all->font.img_width_open0, &all->font.img_height_open0);
    all->font.path_open1 = "rsrcs/Fonts/1.xpm";
    all->font.img_open1 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open1, &all->font.img_width_open1, &all->font.img_height_open1);
    all->font.path_open2 = "rsrcs/Fonts/2.xpm";
    all->font.img_open2 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open2, &all->font.img_width_open2, &all->font.img_height_open2);
    all->font.path_open3 = "rsrcs/Fonts/3.xpm";
    all->font.img_open3 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open3, &all->font.img_width_open3, &all->font.img_height_open3);
    all->font.path_open4 = "rsrcs/Fonts/4.xpm";
    all->font.img_open4 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open4, &all->font.img_width_open4, &all->font.img_height_open4);
    all->font.path_open5 = "rsrcs/Fonts/5.xpm";
    all->font.img_open5 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open5, &all->font.img_width_open5, &all->font.img_height_open5);
    all->font.path_open6 = "rsrcs/Fonts/6.xpm";
    all->font.img_open6 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open6, &all->font.img_width_open6, &all->font.img_height_open6);
    all->font.path_open7 = "rsrcs/Fonts/7.xpm";
    all->font.img_open7 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open7, &all->font.img_width_open7, &all->font.img_height_open7);
    all->font.path_open8 = "rsrcs/Fonts/8.xpm";
    all->font.img_open8 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open8, &all->font.img_width_open8, &all->font.img_height_open8);
    all->font.path_open9 = "rsrcs/Fonts/9.xpm";
    all->font.img_open9 = mlx_xpm_file_to_image(var->mlx_connection, all->font.path_open9, &all->font.img_width_open9, &all->font.img_height_open9);
}

void ft_mlx_work(char **map, t_m_config map_config)
{
    t_textures all_textures;
    t_window var;
    var.mlx_connection = mlx_init();
    if (!var.mlx_connection)
        exit(11);
    var.tmap = map;
    var.map_cnfg = map_config;
    init_textures(&all_textures, &var);
    var.all_textures = all_textures;
    var.mlx_window = mlx_new_window(var.mlx_connection, all_textures.wall.img_width * map_config.x_size, all_textures.wall.img_height * map_config.y_size, "so_long");
    if (NULL == var.mlx_window)
    {
        mlx_destroy_display(var.mlx_connection);
        free(var.mlx_connection);
        exit(11);
    }
    mlx_key_hook(var.mlx_window, key_hook, &var);
    mlx_loop(var.mlx_connection);
    mlx_destroy_window(var.mlx_connection, var.mlx_window);
    mlx_destroy_display(var.mlx_connection);
    free(var.mlx_connection);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    //check if .ber extension
    char **map = parse(open(av[1], O_RDONLY));
    static t_m_config map_config;
    get_map_config(&map_config, map);
    // ft_sound_work();
    ft_mlx_work(map, map_config);
    return (0);
}