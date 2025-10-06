/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:00:52 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:14:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_pixels(t_cub3d *cub3d, t_ray *ray, int x,
		mlx_texture_t *texture)
{
	int				y;
	int				text_x;
	double			step;
	double			texture_position;

	text_x = (int)(x_array_texture(ray) * texture->width);
	if (text_x < 0)
		text_x = 0;
	if (text_x >= (int)texture->width)
		text_x = texture->width - 1;
	step = (double)texture->height / ray->line_height;
	texture_position = (ray->draw_start - cub3d->window_height / 2 
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		mlx_put_pixel(cub3d->img, x, y, get_texture_pixel(texture,
				(int)texture_position, text_x));
		texture_position += step;
		y++;
	}
}

uint32_t	get_texture_pixel(mlx_texture_t *texture, int tex_y, int text_x)
{
	int	pixel_index;

	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= (int)texture->height)
		tex_y = texture->height - 1;
	pixel_index = tex_y * texture->width + text_x;
	if (pixel_index >= 0 && pixel_index
		< (int)(texture->width * texture->height))
	{
		return (((uint32_t *)texture->pixels)[pixel_index]);
	}
	return (0x00000080);
}
// instead of color = ((uint32_t *)texture->pixels)[pixel_index];
// avoiding out of bounds read , returns a semi transparent black

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
