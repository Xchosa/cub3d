/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:52:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/23 15:18:43 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
// // load textures in cub3d->graphics->north
// // load img in cub3d->graphics->north correctly


// // flippling pictures pixesl / mirror it -> coordinate system sees everything backwards
// /*
// Calculate where on the wall the ray hit (0.0 to 1.0)
// Map the wall position to texture coordinates
// */


mlx_texture_t *load_wall_texture(t_cub3d *cub3d, t_ray *ray)
{
    mlx_texture_t	*wall_texture;

	if (ray->side == 0 && ray->delta_x > 0) // vertical wall, ray points to positive x direction (east)
		wall_texture = cub3d->graphics->east.texture;
	else if (ray->side == 0 && ray->delta_x < 0) // vertical wall, ray points to negative x direction (west)
		wall_texture = cub3d->graphics->west.texture;
	else if (ray->side == 1 && ray->delta_y > 0) // horizontal wall, ray points to positive y direction (south)
		wall_texture = cub3d->graphics->south.texture;
	else // horizontal wall, ray points to negative y direction (north)
    	wall_texture = cub3d->graphics->north.texture;
	
    return(wall_texture);
}

int return_x_cor_texture(int wall_x, t_cub3d *cub3d, mlx_texture_t *wall_texture)
{
	if( wall_texture == cub3d->graphics->north.texture)
		return ((int)(wall_x *cub3d->graphics->north.texture->width));
	else  if( wall_texture == cub3d->graphics->east.texture)
		return ((int)(wall_x *cub3d->graphics->east.texture->width));
	else if( wall_texture == cub3d->graphics->west.texture)
		return ((int)(wall_x *cub3d->graphics->west.texture->width));
	else
		return ((int)(wall_x *cub3d->graphics->south.texture->width));

	}

void draw_ceiling(int y, t_cub3d *cub3d, t_ray *ray, int x)
{
	uint32_t ceiling_color; 
	ceiling_color = (cub3d->graphics->ceiling_colour[0] << 24) |
                    (cub3d->graphics->ceiling_colour[1] << 16) |
                    (cub3d->graphics->ceiling_colour[2] << 8) |
                    0xFF;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, ceiling_color);
		y++;
	}
}



void draw_column( t_cub3d *cub3d, t_ray *ray, int x)
{
    uint32_t	ceiling_color;
    uint32_t	floor_color;
    double      wall_x;
    int         y;
    int         text_x;
    mlx_texture_t	*wall_texture;
	uint32_t	*texture_pix;
	double		step;
	double		texture_position;
	uint32_t	color;
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
        wall_x = ray->ray_y + ray->wall_dist * ray->delta_y;
    else
    // horizontal
        wall_x = ray->ray_x + ray->wall_dist * ray->delta_x;



	
    wall_x = wall_x - floor(wall_x); // rundet immer ab -1,3 = -2 / 
    // get decimalstellen/ franction part

    wall_texture = load_wall_texture(cub3d, ray);
	// text_x = return_x_cor_texture(wall_x, cub3d, wall_texture);
	texture_pix = (uint32_t*)wall_texture->pixels;
	text_x = (int)(wall_x * wall_texture->width);

    // texture x cordinate
	
    
    // check for horizontall flip 
    // ray looks east  pos x direction && ray points north (neg y direction )
    if ((ray->side == 0  && ray->delta_x > 0 ) || (ray->side == 1 && ray->delta_y < 0))
        text_x = cub3d->graphics->north.texture->width - text_x -1; // for 64 pixel img, 63 last valid 
    // 

    // x achse durch ray , x wert 3, 5 an der wand 
    // brechnen wo der ray an y
	step = (double)wall_texture->height / ray->line_height;
	texture_position = (ray->draw_start - cub3d->window_height / 2 + ray->line_height / 2) * step;
    // ceiling
    y = 0;

	//draw_ceiling(y, cub3d, ray, x);
    while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, ceiling_color);
		y++;
	}
    while (y <= ray->draw_end)
	{
		color = texture_pix[(int)texture_position * wall_texture->width + text_x];
		mlx_put_pixel(cub3d->img, x, y, color);
		texture_position += step;
		y++;
	}
	while (y < (int)cub3d->window_height)
	{
		mlx_put_pixel(cub3d->img, x, y, floor_color);
		y++;
	}
}


// 
