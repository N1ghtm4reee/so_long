/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghosts_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:13:10 by aakhrif           #+#    #+#             */
/*   Updated: 2024/12/16 10:51:26 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	left_right(t_window *var, int t_x, int t_y, int i)
{
	if (var->tmap[t_y][t_x + 1] != '1' && var->tmap[t_y][t_x + 1] != 'C'
		&& var->tmap[t_y][t_x + 1] != 'F' && var->tmap[t_y][t_x + 1] != 'E')
	{
		var->tmap[t_y][t_x] = '0';
		var->tmap[t_y][t_x + 1] = 'F';
		var->map_cnfg.enemies_positions[i][1]++;
	}
	else if (var->tmap[t_y][t_x - 1] != '1' && var->tmap[t_y][t_x - 1] != 'C'
		&& var->tmap[t_y][t_x - 1] != 'F' && var->tmap[t_y][t_x - 1] != 'E')
	{
		var->tmap[t_y][t_x] = '0';
		var->tmap[t_y][t_x - 1] = 'F';
		var->map_cnfg.enemies_positions[i][1]--;
	}
}

void	up_down(t_window *var, int t_x, int t_y, int i)
{
	if (var->tmap[t_y + 1][t_x] != '1' && var->tmap[t_y + 1][t_x] != 'C'
		&& var->tmap[t_y + 1][t_x] != 'F' && var->tmap[t_y + 1][t_x] != 'E')
	{
		var->tmap[t_y][t_x] = '0';
		var->tmap[t_y + 1][t_x] = 'F';
		var->map_cnfg.enemies_positions[i][0]++;
	}
	else if (var->tmap[t_y - 1][t_x] != '1' && var->tmap[t_y - 1][t_x] != 'C'
		&& var->tmap[t_y - 1][t_x] != 'F' && var->tmap[t_y - 1][t_x] != 'E')
	{
		var->tmap[t_y][t_x] = '0';
		var->tmap[t_y - 1][t_x] = 'F';
		var->map_cnfg.enemies_positions[i][0]--;
	}
}

void	move_ghosts(t_window *var)
{
	int	t_x;
	int	t_y;
	int	random;
	int	i;

	i = 0;
	while (i < var->map_cnfg.enemies_count)
	{
		random = rand();
		t_y = var->map_cnfg.enemies_positions[i][0];
		t_x = var->map_cnfg.enemies_positions[i][1];
		if (random % 2 == 0)
			left_right(var, t_x, t_y, i);
		else
			up_down(var, t_x, t_y, i);
		i++;
	}
}
