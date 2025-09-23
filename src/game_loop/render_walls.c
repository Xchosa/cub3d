

#include "cub3d.h"
// // load textures in cub3d->graphics->north
// // load img in cub3d->graphics->north correctly


// // flippling pictures pixesl / mirror it -> coordinate system sees everything backwards
// /*
// Calculate where on the wall the ray hit (0.0 to 1.0)
// Map the wall position to texture coordinates
// */


mlx_image_t load_texture(t_cub3d *cub3d)
{
    mlx_image_t	wall_texture;
    

    wall_texture = cub3d->graphics->north.img;
    return(wall_texture);
}

void draw_column( t_cub3d *cub3d, t_ray *ray, int x)
{
    uint32_t	ceiling_color;
    uint32_t	floor_color;
    double      wall_x;
    int         y;
    int         text_x;
    mlx_texture_t	wall_texture;

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
    // horizontl
        wall_x = ray->ray_x + ray->wall_dist + ray->delta_x;

    wall_x = wall_x - floor(wall_x); // rundet immer ab -1,3 = -2 / 
    // get decimalstellen/ franction part

    wall_texture = load_texture;
    // texture x cordinate
    text_x = (int)(wall_x *cub3d->graphics->north.texture->width);
    
    // check for horizontall flip 
    // ray looks east  pos x direction && ray points north (neg y direction )
    
    if ((ray->side == 0  && ray->delta_x > 0 ) || (ray->side == 1 && ray->delta_y < 0))
        text_x = cub3d->graphics->north.texture->width - text_x -1; // for 64 pixel img, 63 last valid 
    // 

    // x achse durch ray , x wert 3, 5 an der wand 
    // brechnen wo der ray an y

    // ceiling
    y = 0;
    while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, ceiling_color);
		y++;
	}
    // while (y <= ray->draw_end)
	// {
	// 	mlx_put_pixel(cub3d->img, x, y, wall_color);
	// 	y++;
	// }
	while (y < (int)cub3d->window_height)
	{
		mlx_put_pixel(cub3d->img, x, y, floor_color);
		y++;
	}
}


// 

