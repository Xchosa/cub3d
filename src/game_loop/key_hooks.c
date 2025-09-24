/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:32:45 by mimalek           #+#    #+#             */
/*   Updated: 2025/09/24 10:23:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(void *param)
{
	//Selbst erklarend schatze ich (nur aufrufen anderer Funktionen)
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);

	handle_toggles(cub3d);
	move_player(cub3d);
	render_map(cub3d);
}

void	move_player(t_cub3d *cub3d)
{
	double time_now;
	double fps;
	double px_d;
	double py_d;

	px_d = 0.0;
	py_d = 0.0;
	time_now = mlx_get_time();
	fps = time_now - cub3d->player.time;
	if (fps > 0.1)
		fps = 0.1;
	cub3d->player.time = time_now;
	update_player_pos(cub3d, fps, px_d, py_d);
}


void rotate_player_keys(t_cub3d *cub3d, double fps)
{
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		rotate_player(cub3d, -rotation_speed * fps);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		rotate_player(cub3d, rotation_speed * fps);
}

bool check_for_wall(int	new_grid_x, int new_grid_y, t_cub3d *cub3d)
{
	if (new_grid_x >= 0 && new_grid_x < cub3d->minimap.map_width &&
		new_grid_y >= 0 && new_grid_y < cub3d->minimap.map_height &&
		cub3d->minimap.map_grid[new_grid_y][new_grid_x] != '1')
		return true;
	else
		return false;
}


void update_player_pos(t_cub3d *cub3d, double px_d, double py_d)
{
	cub3d->player.px_x += px_d;
	cub3d->player.px_y += py_d;
}


// movement_speed (50), rotation_speed (90) are defined 
void	update_player_pos(t_cub3d *cub3d, double fps, double px_d, double py_d)
{
	int		new_grid_x;
	int		new_grid_y;
	double	player_rad;
	double	forward_x;
	double	forward_y;
	double	right_x;
	double	right_y;
	
	player_rad = cub3d->player.direction * M_PI / 180.0;
	forward_x = cos(player_rad);
	forward_y = sin(player_rad);
	right_x = cos(player_rad + M_PI / 2.0);
	right_y = sin(player_rad + M_PI / 2.0);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
	{
		px_d += forward_x * movement_speed * fps;
		py_d += forward_y * movement_speed * fps;	
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
	{
		px_d -= forward_x * movement_speed * fps;
		py_d -= forward_y * movement_speed * fps;
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
	{
		px_d -= right_x * movement_speed * fps;
		py_d -= right_y * movement_speed * fps;		
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
	{
		px_d += right_x * movement_speed * fps;
		py_d += right_y * movement_speed * fps;			
	}
	rotate_player_keys(cub3d, fps);
	new_grid_x = (int)((cub3d->player.px_x + px_d - 1) / cub3d->minimap.square_size);
	new_grid_y = (int)((cub3d->player.px_y + py_d - 1) / cub3d->minimap.square_size);

	if (check_for_wall(new_grid_x, new_grid_y,cub3d) == true)
		update_player_pos(cub3d,px_d,py_d);
	
	//if (new_grid_x >= 0 && new_grid_x < cub3d->minimap.map_width &&
	//	new_grid_y >= 0 && new_grid_y < cub3d->minimap.map_height &&
	//	cub3d->minimap.map_grid[new_grid_y][new_grid_x] != '1')
	//{
	//	cub3d->player.px_x += px_d;
	//	cub3d->player.px_y += py_d;
	//}
}
//Relativ selbsterklarend, hier wird nur die Player Richtung berechnet wenn man sich dreht
void	rotate_player(t_cub3d *cub3d, double angle_change)
{
	cub3d->player.direction += angle_change;
	if (cub3d->player.direction >= 360.0)
		cub3d->player.direction -= 360.0;
	if (cub3d->player.direction < 0.0)
		cub3d->player.direction += 360.0;
}


// Hier geht es nur darum mit 'R' die rays (auf der minimap) unsichtbar/sichtbar zu machen
// Und mit 'M' das selbe fur die ganze Minimap (M macht logischerweise gleichzeitig auch Rays unsichtbar)
void	handle_toggles(t_cub3d *cub3d)
{
	static int	m_key_pressed = 0;
	static int	r_key_pressed = 0;
	
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_M))
	{
		if (!m_key_pressed)
		{
			cub3d->show_minimap = !cub3d->show_minimap;
			m_key_pressed = 1;
		}
	}
	else
		m_key_pressed = 0;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_R))
	{
		if (!r_key_pressed)
		{
			cub3d->show_rays = !cub3d->show_rays;
			r_key_pressed = 1;
		}
	}
	else
		r_key_pressed = 0;
}
