/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:52:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/26 13:04:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(int y, t_cub3d *cub3d, t_ray *ray, int x)
{
	uint32_t	ceiling_color;

	ceiling_color = (cub3d->graphics->ceiling_colour[0] << 24)
					| (cub3d->graphics->ceiling_colour[1] << 16)
					| (cub3d->graphics->ceiling_colour[2] << 8)
					| 0xFF;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, ceiling_color);
		y++;
	}
}

uint32_t	r_ceil(t_cub3d *cub3d)
{
	uint32_t	ceiling_color;

	ceiling_color = (cub3d->graphics->ceiling_colour[0] << 24)
					| (cub3d->graphics->ceiling_colour[1] << 16)
					| (cub3d->graphics->ceiling_colour[2] << 8)
					| 0xFF;
	return (ceiling_color);
}

uint32_t	r_floor(t_cub3d *cub3d)
{
	uint32_t	floor_color;

	floor_color = (cub3d->graphics->floor_colour[0] << 24)
					| (cub3d->graphics->ceiling_colour[1] << 16)
					| (cub3d->graphics->ceiling_colour[2] << 8)
					| 0xFF;
	return (floor_color);
}

// exact x cordinate on texture for one singe ray
// vertical Wall  // calculate wall position of ray hit (0.0 to 1.0)
// rundet immer ab -1,3 = -2 /  / get decimalstellen/ franction part
double	x_array_texture(t_ray *ray)
{
	double			wall_x;

	if (ray->side == 0)
		wall_x = ray->ray_y + ray->wall_dist * ray->delta_y;
	else
		wall_x = ray->ray_x + ray->wall_dist * ray->delta_x;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}

//texture x cordinate
// every ray gets one out of 4 wall_textures 
// finds the exact fractionl x value
// finds the texture position, x value given, y = 0 
// on this single x coordinate it loops up the y koordinte 
// as long as it finds ceiling it draws ceiling, then texture
// then only floor
//  x achse durch ray , x wert 3, 5 an der wand
void	draw_column( t_cub3d *cub3d, t_ray *ray, int x)
{
	int				y;
	int				text_x;
	uint32_t		*texture_pix;
	double			step;
	double			texture_position;
	uint32_t		color;

	texture_pix = (uint32_t*)load_wall_texture(cub3d, ray)->pixels;
	text_x = (int)(x_array_texture(ray) * load_wall_texture(cub3d, ray)->width);
	step = (double)load_wall_texture(cub3d, ray)->height / ray->line_height;
	texture_position = (ray->draw_start - cub3d->window_height
			/ 2 + ray->line_height / 2) * step;
	y = 0;
	while (y < ray->draw_start)
		mlx_put_pixel(cub3d->img, x, y++, r_ceil(cub3d));
	while (y <= ray->draw_end)
	{
		//color = (uint32_t*)load_wall_texture(cub3d, ray)->pixels(int)texture_position
		color = texture_pix[(int)texture_position
			* load_wall_texture(cub3d, ray)->width + text_x];
		mlx_put_pixel(cub3d->img, x, y, color);
		texture_position += step;
		y++;
	}
	while (y < (int)cub3d->window_height)
		mlx_put_pixel(cub3d->img, x, y++, r_floor(cub3d));
}
//wall_texture = load_wall_texture(cub3d, ray);
	//mlx_texture_t	*wall_texture;