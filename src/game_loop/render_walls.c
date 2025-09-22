

#include "cub3d.h"
/*
Calculate where on the wall the ray hit (0.0 to 1.0)
Map the wall position to texture coordinates
*/


void draw_column( t_cub3d , t_ray *ray, int x)
{
    uint32_t	ceiling_color;
    uint32_t	floor_color;
    double      wall_x;
    int         y;


    ceiling_color = (cub3d->graphics->ceiling_colour[0] << 24) |
                    (cub3d->graphics->ceiling_colour[1] << 16) |
                    (cub3d->graphics->ceiling_colour[2] << 8) |
                    0xFF;
    
    floor_color = (cub3d->graphics->floor_colour[0] << 24) |
                    (cub3d->graphics->floor_colour[1] << 16) |
                    (cub3d->graphics->floor_colour[2] << 8) |
                    0xFF;

    // calculate wall position of ray hit (0.0 to 1.0)
    if (ray->side == 0 )// vertical Wall
        wall_x = ray->ray_y + ray->wall_dist + ray->delta_y;
    else
        wall_x = ray->ray_x + ray->wall_dist + ray->delta_x;

    wall_x = wall_x - floor(wall_x); // rundet immer ab -1,3 = -2 / 
    // get decimalstellen/ franction part

    
}

