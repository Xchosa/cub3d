/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:47:53 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/28 12:41:41 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void calculate_ray_direction(t_cub3d *cub3d, t_ray *ray, int x);
static void set_ray_starting_position(t_cub3d *cub3d, t_ray *ray);
static void setup_dda_variables(t_ray *ray);

void    init_ray(t_cub3d *cub3d, t_ray *ray, int x)
{
	// Selbst erklarend, nur aufrufen anderer Funktionen
    calculate_ray_direction(cub3d, ray, x);
    set_ray_starting_position(cub3d, ray);
    setup_dda_variables(ray);   
}

static void calculate_ray_direction(t_cub3d *cub3d, t_ray *ray, int x)
{
    double  camera_x; // Bildschiirm Position auf Kamera Ebene (-1 bis +1)
    double  player_rad; // Spieler Richtung in Radiant
    double  fov_rad; // Sichtfeld in Rad
    double  ray_rad; // Endgultiger Ray-Winkel in Rad
	double	angle_offset; // Winkel Offset von Spieler-Richtung

    camera_x = 2 * x / (double)cub3d->window_width - 1; 
    player_rad = cub3d->player.direction * M_PI / 180.0; // Spieler Richtung Grad in Rad
    fov_rad = FOV * M_PI / 180.0; // Sichtfeld Grad in Rad
	angle_offset = atan(camera_x * tan(fov_rad / 2.0));
    ray_rad = player_rad + angle_offset; // Offset addieren um de richtigen Ray-Winkel zu bekommen
    ray->delta_x = cos(ray_rad); // Berechnung (siehe Ray-Struct)
    ray->delta_y = sin(ray_rad); // Berechnung (siehe Ray-struct)
}

static void set_ray_starting_position(t_cub3d *cub3d, t_ray *ray)
{
    double  player_map_x; // Spieler x-Position in Grid-Koordinaten
    double  player_map_y; // Spieler y-Position in Grid-Koordinaten

    player_map_x = (cub3d->player.px_x - 1) / (double)cub3d->minimap.square_size; //Umrechnung vom x-wert ins Grid-System (-1 wegen den 1px abstand von den Zellen)
    player_map_y = (cub3d->player.px_y - 1) / (double)cub3d->minimap.square_size; //Umrechnung vom y-wert ins Grid-System (-1 wegen den 1px abstand von den Zellen)
    ray->ray_x = player_map_x; // Im endeffekt nur einsetzen der oberen rechnungen (man hatte die beiden lines oben auch weglassen konnen  und direkt hier rechnen konnen ;)
    ray->ray_y = player_map_y; // Im endeffekt nur einsetzen der oberen rechnungen (man hatte die beiden lines oben auch weglassen konnen  und direkt hier rechnen konnen ;)
    ray->map_x = (int)ray->ray_x; //Aktuelle Grid Zelle in ganzen Zahlen (x-Wert)
    ray->map_y = (int)ray->ray_y; //Aktuelle Grid Zelle in ganzen Zahlen (y-Wert)
    ray->hit = 0; // Erstmal keine Wand getroffen (standart wert)
}

static void setup_dda_variables(t_ray *ray)
{
    ray->delta_dist_x = fabs(1.0 / ray->delta_x); //Distanz die ein Ray zurucklegt um eine vertikale Grid-Line zu uberqueren
    ray->delta_dist_y = fabs(1.0 / ray->delta_y); // Das selbe nur horizontal
    if (ray->delta_x < 0) //Wenn das Ray nach links zeigt (negative X)
    {
        ray->step_x = -1; //Schritt Richtung
        ray->side_dist_x = (ray->ray_x - ray->map_x) * ray->delta_dist_x; //Distanz zur vorherigen vertikalen Grid-Line
    }
    else // Ray zeigt nach rechts (positive X)
    {
        ray->step_x = 1; //Schritt Richtung
        ray->side_dist_x = (ray->map_x + 1.0 - ray->ray_x) * ray->delta_dist_x; //Distanz zur nachste vertikalen Grid-Line
    }
    if (ray->delta_y < 0) // Falls Ray nach oben zeigt (negative Y)
    {
        ray->step_y = -1; //Schritt Richtung
        ray->side_dist_y = (ray->ray_y - ray->map_y) * ray->delta_dist_y; //Distanz zur vorherigen horizontalen Grid-Line
    }
    else // Ray zeigt nach unten (positive Y)
    {
        ray->step_y = 1; //Schritt Richtung
        ray->side_dist_y = (ray->map_y + 1.0 - ray->ray_y) * ray->delta_dist_y; //Distanz zur nachsten horizontalen Grid-Line
    }
}

