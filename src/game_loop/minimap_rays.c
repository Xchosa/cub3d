/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:17:19 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:47:19 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Sichtfeld von 60 grad und 60 geschossenen rays. alle in 
// einem anderen windel geschossen
// jeweils eine ray geschossen bis 60 erreicht sind
void	cast_rays(t_cub3d *cub3d)
{
	int		ray_index;
	double	player_angle;
	double	ray_angle;
	double	angle_step;

	player_angle = cub3d->player.direction;
	angle_step = FOV / NUM_RAYS;
	ray_index = 0;
	while (ray_index < NUM_RAYS)
	{
		ray_angle = player_angle - (FOV / 2.0) + (ray_index * angle_step);
		cast_single_ray(cub3d, ray_angle);
		ray_index++;
	}
}

// Gibt den Winkel vom Spieler wieder
double	get_player_angle(char direction)
{
	if (direction == 'N')
		return (270.0);
	else if (direction == 'S')
		return (90.0);
	else if (direction == 'E')
		return (0.0);
	else if (direction == 'W')
		return (180.0);
	return (0.0);
}

void	draw_single_ray(t_cub3d *cub3d, double ray_x, double ray_y)
{
	if (ray_x >= 0 && ray_x < cub3d->window_width
		&& ray_y >= 0 && ray_y < cub3d->window_height)
	{
		mlx_put_pixel(cub3d->img, (int)ray_x, (int)ray_y, RAY_COLOR);
	}
}

// Boundary Check falls player aus der Map kommt
// Wall Collision Check
bool	boundary_and_wall_collision_check(t_cub3d *cub3d,
	int grid_x, int grid_y)
{
	if (grid_x < 0 || grid_x >= cub3d->minimap.map_width
		|| grid_y < 0 || grid_y >= cub3d->minimap.map_height)
		return (false);
	if (cub3d->minimap.map_grid[grid_y][grid_x] == '1')
		return (false);
	return (true);
}

// rad angle, konvertiert gradzahl in dezimal
// max ray length 200, ray max 200 pixel so lange wird gezeichnet, 
// 1 pixel pro Schritt(max 200 px)
// im loop 1 pixel forwaerts und nach boundary und wall check, 
// wird ein pixelmehr rot gemalt
void	cast_single_ray(t_cub3d *cub3d, double angle)
{
	double	ray_x;
	double	ray_y;
	int		steps;
	int		grid_x;
	int		grid_y;

	ray_x = cub3d->player.px_x;
	ray_y = cub3d->player.px_y;
	steps = 0;
	while (steps < RAY_LENGTH)
	{
		ray_x += cos(angle * M_PI / 180.0) * STEP_SIZE;
		ray_y += sin(angle * M_PI / 180.0) * STEP_SIZE;
		grid_x = (int)((ray_x - 1) / cub3d->minimap.square_size);
		grid_y = (int)((ray_y - 1) / cub3d->minimap.square_size);
		if (boundary_and_wall_collision_check(cub3d, grid_x, grid_y) == false)
			break ;
		draw_single_ray(cub3d, ray_x, ray_y);
		steps++;
	}
}
	//double	rad_angle;
	//rad_angle = angle * M_PI / 180.0;
