/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:32:45 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/25 11:46:48 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);

	move_player(cub3d);
	render_map(cub3d);

	// just for demonstration
	// draw_player_minimap(cub3d, cub3d->player.px_y, cub3d->player.px_x);
	// key hook for letting minimap appear 
}

// 1. bild initalisieren, dann player
// 2. in game loop 
// 		player moven, rays schiesen
//		minimap, und karte neu malen, player ort uebergaben 

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

	
	// if(cub3d->minimap.map_grid[p_y][p_x] == '1')
		//dann nicht updaten. 

}



void	update_player_pos(t_cub3d *cub3d, double fps, double px_d, double py_d)
{
	double	movement_speed;
	int		new_grid_x;
	int		new_grid_y;

	movement_speed = 50.0;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
		py_d -= movement_speed * fps; 
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
		py_d += movement_speed * fps;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
		px_d += movement_speed * fps; 
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
		px_d -= movement_speed * fps;
	
	new_grid_x = (int)((cub3d->player.px_x + px_d - 1) / cub3d->minimap.square_size);
	new_grid_y = (int)((cub3d->player.px_y + py_d - 1) / cub3d->minimap.square_size);
	
	if (new_grid_x >= 0 && new_grid_x < cub3d->minimap.map_width &&
		new_grid_y >= 0 && new_grid_y < cub3d->minimap.map_height &&
		cub3d->minimap.map_grid[new_grid_y][new_grid_x] != '1')
	{
		cub3d->player.px_x += px_d;
		cub3d->player.px_y += py_d;
	}
}