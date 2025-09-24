/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:47:53 by mimalek           #+#    #+#             */
/*   Updated: 2025/09/24 10:15:26 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void calculate_ray_direction(t_cub3d *cub3d, t_ray *ray, int x);
static void set_ray_starting_position(t_cub3d *cub3d, t_ray *ray);
static void setup_dda_variables(t_ray *ray);

void    init_ray(t_cub3d *cub3d, t_ray *ray, int x)
{
    calculate_ray_direction(cub3d, ray, x);
    set_ray_starting_position(cub3d, ray);
    setup_dda_variables(ray);   
}

// camera_x Bildschiirm Position auf Kamera Ebene (-1 bis +1)
//player_rad Spieler Richtung in Radiant
//fov_rad  Sichtfeld in Rad fov_rad; 180 grad 
//angle_offset  Endgultiger Ray-Winkel in Rad ray_rad;
// Winkel Offset von Spieler-Richtung angle_offset, werden addiert fuer richtigen ray winkel
static void calculate_ray_direction(t_cub3d *cub3d, t_ray *ray, int x)
{
    double  camera_x;
    double  player_rad;
    double  fov_rad;
    double  ray_rad;
	double	angle_offset;

    camera_x = 2 * x / (double)cub3d->window_width - 1; 
    player_rad = cub3d->player.direction * M_PI / 180.0;
    fov_rad = FOV * M_PI / 180.0;
	angle_offset = atan(camera_x * tan(fov_rad / 2.0));
    ray_rad = player_rad + angle_offset;
    ray->delta_x = cos(ray_rad);
    ray->delta_y = sin(ray_rad);
}

// Spieler y-Position in Grid-Koordinaten
//Umrechnung vom x-wert ins Grid-System (-1 wegen den 1px abstand von den Zellen)
// ray->map_x = (int)ray->ray_x; Aktuelle Grid Zelle in ganzen Zahlen (x-Wert)
//  // Erstmal keine Wand getroffen (standart wert)
static void set_ray_starting_position(t_cub3d *cub3d, t_ray *ray)
{
    double  player_map_x;
    double  player_map_y;

    player_map_x = (cub3d->player.px_x - 1) / (double)cub3d->minimap.square_size;
    player_map_y = (cub3d->player.px_y - 1) / (double)cub3d->minimap.square_size;
    ray->ray_x = player_map_x;
    ray->ray_y = player_map_y;
    ray->map_x = (int)ray->ray_x;
    ray->map_y = (int)ray->ray_y;
    ray->hit = 0;
}
//Distanz die ein Ray zurucklegt um eine vertikale Grid-Line zu uberqueren, and horizontal (y)
// ray->delta_x < 0 Wenn das Ray nach links zeigt (negative X)
// ray->side_dist_x Distanz zur vorherigen vertikalen Grid-Line
// ray->side_dist_x Distanz zur nachste vertikalen Grid-Line
// ray->delta_y < 0 Falls Ray nach oben zeigt (negative Y)
static void setup_dda_variables(t_ray *ray)
{
    ray->delta_dist_x = fabs(1.0 / ray->delta_x);
    ray->delta_dist_y = fabs(1.0 / ray->delta_y);
    if (ray->delta_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->ray_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - ray->ray_x) * ray->delta_dist_x;
    }
    if (ray->delta_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->ray_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - ray->ray_y) * ray->delta_dist_y;
    }
}

