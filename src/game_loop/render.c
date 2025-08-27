/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:06:12 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/27 14:03:58 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_dda(t_cub3d *cub3d, t_ray *ray);
static void	calculation_projection(t_cub3d *cub3d, t_ray *ray);
static void	draw_column(t_cub3d *cub3d, t_ray *ray, int x);

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

static void	perform_dda(t_cub3d *cub3d, t_ray *ray)
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
		if (ray->map_x < 0 || ray->map_x >= cub3d->minimap.map_width ||
			ray->map_y < 0 || ray->map_y >= cub3d->minimap.map_height ||
			cub3d->minimap.map_grid[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
			if (ray->map_x >= 0 && ray->map_x < cub3d->minimap.map_width &&
				ray->map_y >= 0 && ray->map_y < cub3d->minimap.map_height)
				ray->wall_type = cub3d->minimap.map_grid[ray->map_y][ray->map_x];
			else
				ray->wall_type = '1';
		}
	}
}

static void	calculation_projection(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - ray->ray_x + (1 - ray->step_x) / 2) / ray->delta_x;
	else
		ray->wall_dist = (ray->map_y - ray->ray_y + (1 - ray->step_y) / 2) / ray->delta_y;
	ray->wall_dist = fabs(ray->wall_dist);
	ray->line_height = (int)(cub3d->window_height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub3d->window_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub3d->window_height / 2;
	if (ray->draw_end >= (int)cub3d->window_height)
		ray->draw_end = cub3d->window_height - 1;
}

static void	draw_column(t_cub3d *cub3d, t_ray *ray, int x)
{
	uint32_t	wall_color;
	int			y;
	
	if (ray->side == 1)
		wall_color = 0x808080FF;
	else
		wall_color = 0xFFFFFFFF;
	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, *(cub3d->graphics->ceiling_colour));
		y++;
	}
	while (y <= ray->draw_end)
	{
		mlx_put_pixel(cub3d->img, x, y, wall_color);
		y++;
	}
	while (y < (int)cub3d->window_height)
	{
		mlx_put_pixel(cub3d->img, x, y, *(cub3d->graphics->floor_colour));
		y++;
	}
}
