/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:14:56 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/06 10:27:55 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

void	draw_minimap(t_cub3d *cub3d)
{
	int		minimap_x;
	int		minimap_y;

	// map_height = get_map_height(cub3d->map);
	// map_width = get_map_width(cub3d->map);
	// square_size = return_square_size(cub3d, map_width, map_height);
	
	minimap_x = cub3d->window_width - cub3d->minimap_img_width - 10;
	minimap_y = 10;
	draw_minimap_background(cub3d, minimap_x, minimap_y);
	
	draw_minimap_cells(cub3d, minimap_x, minimap_y);
}

void	draw_minimap_background(t_cub3d *cub3d, int start_x, int start_y)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	bg_color;

	bg_color = BLACK_TRANS_COLOR;
	y = 0;
	while(y < cub3d->minimap_img_height)
	{
		x = 0;
		while(x < cub3d->minimap_img_width)
		{
			if (start_x + x < cub3d->window_width &&
				start_y + y < cub3d->window_height )
				mlx_put_pixel(cub3d->img, start_x + x, start_y + y, 
					bg_color);
			x++;
		}
		y++;
	}
}
// map_height, map_width und sqaure size in eine static function auslagern 
// und so in der draw square callen 

void	draw_minimap_cells(t_cub3d *cub3d, int minimap_x, int minimap_y)
{
	int x;
	int y;
	uint32_t cell_color;
	int pixel_x;
	int pixel_y;

	// map_height = get_map_height(cub3d->map);
	// map_width = get_map_width(cub3d->map);
	// square_size = return_square_size(cub3d, map_width, map_height);

	(void)minimap_x;
	(void)minimap_y;
	
	y = 0;
	while (y < get_object()->map_height)
	{
		x = 0;
		while (x < get_object()-> map_width)
		{
			cell_color = get_cell_color(cub3d->map[y][x]);
			pixel_x = minimap_x + (x * get_object()-> square_size);
			pixel_y = minimap_y + (y * get_object()-> square_size);
			draw_square(cub3d, cell_color, pixel_x, pixel_y);
			x++;
		}
		y++;
	}
}

void	draw_square(t_cub3d *cub3d, uint32_t color, int start_x,
		int start_y)
{
	int	x;
	int y;

	y = 0;
	while(y < get_object()->square_size)
	{
		x = 0;
		while(x < get_object()->square_size)
		{
			if (start_x + x >= 0 && start_x + x < (int)cub3d->window_width &&
                start_y + y >= 0 && start_y + y < (int)cub3d->window_height)
			{
				mlx_put_pixel(cub3d->img, start_x + x, start_y + y, color);
			}
			x++;
		}
		y++;
	}
}

