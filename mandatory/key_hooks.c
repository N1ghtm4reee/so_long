/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:15:17 by aakhrif           #+#    #+#             */
/*   Updated: 2025/01/04 11:27:57 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_key(t_window *var, int player_x, int player_y)
{
	if (var->tmap[player_y][player_x - 1] != '1')
	{
		if ((player_y == var->map_cnfg.exit_position[0]
				&& player_x -1 == var->map_cnfg.exit_position[1])
			&& var->collected == var->map_cnfg.c_count)
			return (write(1, "YOU WON!\n", 9), close_window(var), exit(0));
		if (((player_y == var->map_cnfg.exit_position[0])
				&& (player_x - 1 == var->map_cnfg.exit_position[1]))
			&& var->collected != var->map_cnfg.c_count)
			var->tmap[player_y][player_x - 1] = '0';
		if (var->tmap[player_y][player_x - 1] == '0'
			|| var->tmap[player_y][player_x - 1] == 'C')
		{
			if (var->tmap[player_y][player_x - 1] == 'C')
				var->collected++;
			var->tmap[player_y][player_x] = '0';
			var->tmap[player_y][player_x - 1] = 'P';
		}
		var->map_cnfg.player_pos[1]--;
		var->last_key = 'A';
		var->moves++;
		print_moves_nl(var->moves);
	}
}

void	right_key(t_window *var, int player_x, int player_y)
{
	if (var->tmap[player_y][player_x + 1] != '1')
	{
		if ((player_y == var->map_cnfg.exit_position[0]
				&& player_x +1 == var->map_cnfg.exit_position[1])
			&& var->collected == var->map_cnfg.c_count)
			return (write(1, "YOU WON!\n", 9), close_window(var), exit(0));
		if (((player_y == var->map_cnfg.exit_position[0])
				&& (player_x +1 == var->map_cnfg.exit_position[1]))
			&& var->collected != var->map_cnfg.c_count)
			var->tmap[player_y][player_x + 1] = '0';
		if (var->tmap[player_y][player_x + 1] == '0'
			|| var->tmap[player_y][player_x + 1] == 'C')
		{
			if (var->tmap[player_y][player_x + 1] == 'C')
				var->collected++;
			var->tmap[player_y][player_x] = '0';
			var->tmap[player_y][player_x + 1] = 'P';
		}
		var->map_cnfg.player_pos[1]++;
		var->last_key = 'D';
		var->moves++;
		print_moves_nl(var->moves);
	}
}

void	up_key(t_window *var, int player_x, int player_y)
{
	if (var->tmap[player_y - 1][player_x] != '1')
	{
		if ((player_y - 1 == var->map_cnfg.exit_position[0]
				&& player_x == var->map_cnfg.exit_position[1])
			&& var->collected == var->map_cnfg.c_count)
			return (write(1, "YOU WON!\n", 9), close_window(var), exit(0));
		if (((player_y - 1 == var->map_cnfg.exit_position[0])
				&& (player_x == var->map_cnfg.exit_position[1]))
			&& var->collected != var->map_cnfg.c_count)
			var->tmap[player_y - 1][player_x] = '0';
		if (var->tmap[player_y - 1][player_x] == '0'
			|| var->tmap[player_y -1][player_x] == 'C')
		{
			if (var->tmap[player_y - 1][player_x] == 'C')
				var->collected++;
			var->tmap[player_y][player_x] = '0';
			var->tmap[player_y - 1][player_x] = 'P';
		}
		var->map_cnfg.player_pos[0]--;
		var->last_key = 'W';
		var->moves++;
		print_moves_nl(var->moves);
	}
}

void	down_key(t_window *var, int player_x, int player_y)
{
	if (var->tmap[player_y + 1][player_x] != '1')
	{
		if (((player_y + 1 == var->map_cnfg.exit_position[0])
				&& (player_x == var->map_cnfg.exit_position[1]))
			&& var->collected == var->map_cnfg.c_count)
			return (write(1, "YOU WON!\n", 9), close_window(var), exit(0));
		if (((player_y + 1 == var->map_cnfg.exit_position[0])
				&& (player_x == var->map_cnfg.exit_position[1]))
			&& var->collected != var->map_cnfg.c_count)
			var->tmap[player_y + 1][player_x] = '0';
		if (var->tmap[player_y + 1][player_x] == '0'
			|| var->tmap[player_y + 1][player_x] == 'C')
		{
			if (var->tmap[player_y + 1][player_x] == 'C')
				var->collected++;
			var->tmap[player_y][player_x] = '0';
			var->tmap[player_y + 1][player_x] = 'P';
		}
		var->map_cnfg.player_pos[0]++;
		var->last_key = 'S';
		var->moves++;
		print_moves_nl(var->moves);
	}
}

int	key_hook(int keycode, t_window *var)
{
	int	player_x;
	int	player_y;

	player_x = var->map_cnfg.player_pos[1];
	player_y = var->map_cnfg.player_pos[0];
	if (keycode == 113 || 65307 == keycode)
		close_window(var);
	if (keycode == 97)
		left_key(var, player_x, player_y);
	else if (keycode == 100)
		right_key(var, player_x, player_y);
	else if (keycode == 119)
		up_key(var, player_x, player_y);
	if (keycode == 115)
		down_key(var, player_x, player_y);
	if (var->collected == var->map_cnfg.c_count)
	{
		var->got_all = 1;
		var->tmap[var->map_cnfg.exit_position[0]]
		[var->map_cnfg.exit_position[1]] = 'E';
	}
	print_map_on_screen(var->tmap, var, &var->all_textures);
	return (0);
}
