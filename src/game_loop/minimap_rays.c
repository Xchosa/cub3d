/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:17:19 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/28 11:25:11 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    cast_single_ray(t_cub3d *cub3d, double angle);

void    cast_rays(t_cub3d *cub3d)
{
    int     ray_index; // Rays Counter
    double  player_angle; // Richtung in die der Player guckt
    double  ray_angle; // Winkel fur den aktuellen Ray der geschossen wird
    double  angle_step; // Wie viel rotiert werden muss von ray zu ray

    player_angle = cub3d->player.direction; // Richtung in die der Player am Anfang guckt
    angle_step = FOV / NUM_RAYS; // Berechnung das die Rays um den Spieler gehen (Nicht alle in die selbe Richtung gucken)
    ray_index = 0; 
    while (ray_index < NUM_RAYS) // Bis die Angegeben Menge der Rays erreicht ist
    {
        ray_angle = player_angle - (FOV / 2.0) + (ray_index * angle_step); // Der Winkel fur den einzelnen Ray wird berechnet
        cast_single_ray(cub3d, ray_angle);
        ray_index++;
    }
    
}

// Gibt den Winkel vom Spieler wieder
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

// 
static void    cast_single_ray(t_cub3d *cub3d, double angle)
{
    double  ray_x; // Aktuelle Ray Position (in Pixel) x-Wert
    double  ray_y; // Aktuelle Ray Position (in Pixel) y-Wert
    double  dx; // Ray Richtungs Vektor - x-wert
    double  dy; // Ray Richtungs Vektor - y-wert
    double  step_size; // Wie weit ein Schritt ist
    int     steps; // Step Counter
    int     grid_x; // Aktuelle Grid Position - x-Wert
    int     grid_y; // Aktuelle Grid Position - y-Wert
    double  rad_angle; // Winkle in Rad

    rad_angle = angle * M_PI / 180.0; // Konvertiert Grad in Rad
    dx = cos(rad_angle); // X - Komponente der Richtung
    dy = sin(rad_angle); // Y - Komponente der Richtung
    ray_x = cub3d->player.px_x; // Start bei Player's Pixel X
    ray_y = cub3d->player.px_y; // Start bei Player's Pixel Y
    step_size = 1.0; // ! Pixel pro Schritt
    steps = 0; // Reset den Step Counter
    while (steps < RAY_LENGTH) // Bis die Lange eines Rays erreicht ist
    {
        ray_x += dx * step_size; //Ray vorwarts bewegen um 1 Schritt
        ray_y += dy * step_size; // |->
        grid_x = (int)((ray_x - 1) / cub3d->minimap.square_size); // Konvertierun in die Grid-Cells
        grid_y = (int)((ray_y - 1) / cub3d->minimap.square_size); // |->
        if (grid_x < 0 || grid_x >= cub3d->minimap.map_width ||
            grid_y < 0 || grid_y >= cub3d->minimap.map_height) // Boundary Check falls player aus der Map kommt
            break;
        if (cub3d->minimap.map_grid[grid_y][grid_x] == '1') // Wall Collision Check
            break;
        if (ray_x >= 0 && ray_x < cub3d->window_width &&
            ray_y >= 0 && ray_y < cub3d->window_height) // Hier wird der Pixel dann gemalt
            mlx_put_pixel(cub3d->img, (int)ray_x, (int)ray_y, RAY_COLOR);
        steps++; // Nachster Step
    }
}
