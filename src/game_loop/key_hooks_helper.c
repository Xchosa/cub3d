/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:24:11 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:50:09 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player_keys(t_cub3d *cub3d, double fps)
{
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		rotate_player(cub3d, -ROTATION_SPEED * fps);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		rotate_player(cub3d, ROTATION_SPEED * fps);
}

bool	check_wall_rotate(t_cub3d *cub3d, double px_d,
		double py_d, double fps)
{
	static int		new_grid_x;
	static int		new_grid_y;

	rotate_player_keys(cub3d, fps);
	new_grid_x = (int)((cub3d->player.px_x + px_d - 1)
			/ cub3d->minimap.square_size);
	new_grid_y = (int)((cub3d->player.px_y + py_d - 1)
			/ cub3d->minimap.square_size);
	if (new_grid_x >= 0 && new_grid_x < cub3d->minimap.map_width
		&& new_grid_y >= 0 && new_grid_y < cub3d->minimap.map_height
		&& cub3d->minimap.map_grid[new_grid_y][new_grid_x] != '1')
		return (true);
	else
		return (false);
}

void	update_y_and_x(t_cub3d *cub3d, double px_d, double py_d)
{
	cub3d->player.px_x += px_d;
	cub3d->player.px_y += py_d;
}

//Relativ selbsterklarend, hier wird nur die Player Richtung 
// berechnet wenn man sich dreht
void	rotate_player(t_cub3d *cub3d, double angle_change)
{
	cub3d->player.direction += angle_change;
	if (cub3d->player.direction >= 360.0)
		cub3d->player.direction -= 360.0;
	if (cub3d->player.direction < 0.0)
		cub3d->player.direction += 360.0;
}
