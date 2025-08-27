/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:17:19 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/27 14:25:59 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    cast_single_ray(t_cub3d *cub3d, double angle);

void    cast_rays(t_cub3d *cub3d)
{
    int     ray_index;
    double  player_angle;
    double  ray_angle;
    double  angle_step;

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

double  get_player_angle(char direction)
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

static void    cast_single_ray(t_cub3d *cub3d, double angle)
{
    double  ray_x;
    double  ray_y;
    double  dx;
    double  dy;
    double  step_size;
    int     steps;
    int     grid_x;
    int     grid_y;
    double  rad_angle;

    rad_angle = angle * M_PI / 180.0;
    dx = cos(rad_angle);
    dy = sin(rad_angle);
    ray_x = cub3d->player.px_x;
    ray_y = cub3d->player.px_y;
    step_size = 1.0;
    steps = 0;
    while (steps < RAY_LENGTH)
    {
        ray_x += dx * step_size;
        ray_y += dy * step_size;
        grid_x = (int)((ray_x - 1) / cub3d->minimap.square_size);
        grid_y = (int)((ray_y - 1) / cub3d->minimap.square_size);
        if (grid_x < 0 || grid_x >= cub3d->minimap.map_width ||
            grid_y < 0 || grid_y >= cub3d->minimap.map_width)
            break;
        if (cub3d->minimap.map_grid[grid_y][grid_x] == '1')
            break;
        if (ray_x >= 0 && ray_x < cub3d->window_width &&
            ray_y >= 0 && ray_y < cub3d->window_height)
            mlx_put_pixel(cub3d->img, (int)ray_x, (int)ray_y, RAY_COLOR);
        steps++;
    }
}