/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:52:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:23:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// rewritten
void	draw_column( t_cub3d *cub3d, t_ray *ray, int x)
{
	mlx_texture_t	*texture;

	texture = load_wall_texture(cub3d, ray);
	draw_ceiling(cub3d, ray, x);
	draw_wall_pixels(cub3d, ray, x, texture);
	draw_floor_pixel(cub3d, x, ray->draw_end +1);
}

void	draw_ceiling(t_cub3d *cub3d, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(cub3d->img, x, y, r_ceil(cub3d));
		y++;
	}
}

void	draw_floor_pixel(t_cub3d *cub3d, int x, int start_y)
{
	int	y;

	y = start_y;
	while (y < (int)cub3d->window_height)
		mlx_put_pixel(cub3d->img, x, y++, r_floor(cub3d));
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
		| (cub3d->graphics->floor_colour[1] << 16)
		| (cub3d->graphics->floor_colour[2] << 8)
		| 0xFF;
	return (floor_color);
}

//texture x cordinate
// every ray gets one out of 4 wall_textures 
// finds the exact fractionl x value
// finds the texture position, x value given, y = 0 
// on this single x coordinate it loops up the y koordinte 
// as long as it finds ceiling it draws ceiling, then texture
// then only floor
//  x achse durch ray , x wert 3, 5 an der wand
//void	draw_column( t_cub3d *cub3d, t_ray *ray, int x)
//{
//	int				y;
//	int				text_x;
//	double			step;
//	double			texture_position;
//	uint32_t		color;

//	text_x = (int)(x_array_texture(ray) * load_wall_texture(cub3d, ray)->width);
//	step = (double)load_wall_texture(cub3d, ray)->height / ray->line_height;
//	texture_position = (ray->draw_start - cub3d->window_height
//			/ 2 + ray->line_height / 2) * step;
//	y = 0;
//	while (y < ray->draw_start)
//		mlx_put_pixel(cub3d->img, x, y++, r_ceil(cub3d));
//	while (y <= ray->draw_end)
//	{
//		color = ((uint32_t *)load_wall_texture(cub3d, ray)->pixels)[(int)
//			texture_position * load_wall_texture(cub3d, ray)->width + text_x];
//		mlx_put_pixel(cub3d->img, x, y, color);
//		texture_position += step;
//		y++;
//	}
//	while (y < (int)cub3d->window_height)
//		mlx_put_pixel(cub3d->img, x, y++, r_floor(cub3d));
//}

// gives a out of bounds reading for the color only in valgrind

//wall_texture = load_wall_texture(cub3d, ray);
	//mlx_texture_t	*wall_texture;
//color = (uint32_t*)load_wall_texture(cub3d, ray)->pixels(int)texture_position
//color = texture_pix[(int)texture_position
//	* load_wall_texture(cub3d, ray)->width + text_x];