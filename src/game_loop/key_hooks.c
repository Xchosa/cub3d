/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:32:45 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:13:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Selbst erklarend schatze ich (nur aufrufen anderer Funktionen)
void	game_loop(void *param)
{
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
	double	time_now;
	double	fps;
	double	px_d;
	double	py_d;

	px_d = 0.0;
	py_d = 0.0;
	time_now = mlx_get_time();
	fps = time_now - cub3d->player.time;
	if (fps > 0.1)
		fps = 0.1;
	cub3d->player.time = time_now;
	update_player_pos(cub3d, fps, px_d, py_d);
}

// movement_speed (50), rotation_speed (90) are defined 
void	update_player_pos(t_cub3d *cub3d, double fps, double px_d, double py_d)
{
	double	player_rad;

	player_rad = cub3d->player.direction * M_PI / 180.0;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
	{
		px_d += cos(player_rad) * movement_speed * fps;
		py_d += sin(player_rad) * movement_speed * fps;
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
	{
		px_d -= cos(player_rad) * movement_speed * fps;
		py_d -= sin(player_rad) * movement_speed * fps;
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
	{
		px_d -= cos(player_rad + half_circle) * movement_speed * fps;
		py_d -= sin(player_rad + half_circle) * movement_speed * fps;
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
	{
		px_d += cos(player_rad + half_circle) * movement_speed * fps;
		py_d += sin(player_rad + half_circle) * movement_speed * fps;
	}
	if (check_wall_rotate(cub3d, px_d, py_d, fps) == true)
		update_y_and_x(cub3d, px_d, py_d);
}

// Hier geht es nur darum mit 'R' die rays (auf der minimap)
// unsichtbar/sichtbar zu machen
// Und mit 'M' das selbe fur die ganze Minimap 
// (M macht logischerweise gleichzeitig auch Rays unsichtbar)
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
