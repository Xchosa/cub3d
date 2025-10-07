/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:06:12 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/07 11:23:55 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < (int)cub3d->window_width)
	{
		init_ray(cub3d, &ray, x);
		perform_dda(cub3d, &ray);
		calculation_projection(cub3d, &ray);
		draw_column(cub3d, &ray, x);
		x++;
	}
}

bool	check_vertical_wall_hit(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= cub3d->minimap.map_width
		|| ray->map_y < 0 || ray->map_y >= cub3d->minimap.map_height
		|| cub3d->minimap.map_grid[ray->map_y][ray->map_x] == '1')
		return (true);
	return (false);
}

bool	check_map_bounds(t_cub3d *cub3d, int x, int y)
{
	if (x < 0 || x >= cub3d->minimap.map_width || y < 0
		|| y >= cub3d->minimap.map_height)
		return (false);
	return (true);
}

// Digital Differential Analyzer DDA algo to find intersections
// check for wall collision
// check fpr vertical wall hit
// check for horizontal wall hit
void	perform_dda(t_cub3d *cub3d, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_vertical_wall_hit(cub3d, ray) == true)
		{
			ray->hit = 1;
			if (ray->map_x >= 0 && ray->map_x < cub3d->minimap.map_width
				&& ray->map_y >= 0 && ray->map_y < cub3d->minimap.map_height)
				ray->wall_type = cub3d->minimap.map_grid[ray->map_y]
				[ray->map_x];
			else
				ray->wall_type = '1';
		}
	}
}

// 1. degree to radian 270 degree to 4.71
// atan2 radius angel (-pie , pie]
// angle diff (difference between ray and Centre ray ) 
// -> centrer rays have angle diff 0; 

// calculate wall height on screen
// calculate where to start drawing the wall - vertically 
// cacculate where to stop drawing the wall 
// if ray->side == 1 ,its a horizontal wall 
// ensure for positive wall distance
//
//multiply wall_dist * coss (angle_diff)  
//  as bigger the angle_diff -> smaller cos(angle_diff)
//
void	calculation_projection(t_cub3d *cub3d, t_ray *ray)
{
	double	player_rad;
	double	ray_angle;
	double	angle_diff;

	player_rad = cub3d->player.direction * M_PI / 180.0;
	ray_angle = atan2(ray->delta_y, ray->delta_x);
	angle_diff = ray_angle - player_rad;
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - ray->ray_x + (1 - ray->step_x) / 2)
			/ ray->delta_x;
	else
		ray->wall_dist = (ray->map_y - ray->ray_y + (1 - ray->step_y) / 2)
			/ ray->delta_y;
	ray->wall_dist = fabs(ray->wall_dist);
	ray->wall_dist *= cos(angle_diff);
	ray->line_height = (int)(cub3d->window_height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub3d->window_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub3d->window_height / 2;
	if (ray->draw_end >= (int)cub3d->window_height)
		ray->draw_end = cub3d->window_height - 1;
}

// void	draw_column(t_cub3d *cub3d, t_ray *ray, int x)
// {
// 	uint32_t	wall_color;
// 	uint32_t	ceiling_color;
// 	uint32_t	floor_color;
// 	int			y;

// 	//ceiling_color = (red << 24) | (green << 16) | (blue << 8) | alpha;
// 	ceiling_color = (cub3d->graphics->ceiling_colour[0] << 24) |
// 					(cub3d->graphics->ceiling_colour[1] << 16) |
// 					(cub3d->graphics->ceiling_colour[2] << 8) |
// 					0xFF;

// 	floor_color = (cub3d->graphics->floor_colour[0] << 24) |
// 					(cub3d->graphics->floor_colour[1] << 16) |
// 					(cub3d->graphics->floor_colour[2] << 8) |
// 					0xFF;

// 	if (ray->side == 1)
// 		wall_color = 0x808080FF; // Darker
// 	else
// 		wall_color = 0xFFFFFFFF; // brighter for vertical wall
// 	y = 0;
// 	while (y < ray->draw_start)
// 	{
// 		mlx_put_pixel(cub3d->img, x, y, ceiling_color);
// 		y++;
// 	}
// 	while (y <= ray->draw_end)
// 	{
// 		mlx_put_pixel(cub3d->img, x, y, wall_color);
// 		y++;
// 	}
// 	while (y < (int)cub3d->window_height)
// 	{
// 		mlx_put_pixel(cub3d->img, x, y, floor_color);
// 		y++;
// 	}
// }
