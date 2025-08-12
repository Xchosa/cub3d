/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:14:56 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/11 15:40:36 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

void	draw_minimap(t_cub3d *cub3d)
{
	int		minimap_x;
	int		minimap_y;
	minimap_x = 0;// quader form 
	minimap_y = 0;
	// minimap_x = cub3d->minimap.map_width; // quader form 
	// minimap_y = cub3d->minimap.map_height;
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
	while (y < cub3d->minimap_img_height)
	{
		x = 0;
		while (x < cub3d->minimap_img_width)
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


void	draw_minimap_cells(t_cub3d *cub3d, int minimap_x, int minimap_y)
{
	int			x;
	int			y;
	uint32_t	cell_color;
	int 		pixel_x;
	int 		pixel_y;
	(void)minimap_x;
	(void)minimap_y;
	
	y = 0;
	while (y < cub3d->minimap.map_height)
	{
		x = 0;
		while (x < cub3d->minimap.map_width)
		{
			pixel_x = minimap_x + (x * (cub3d->minimap.square_size) + 0);
			//pixel_x = 1 + (x * cub3d->minimap.square_size);
			pixel_y = minimap_y + (y * (cub3d->minimap.square_size) + 0);
			//pixel_y = 1 + (y * cub3d->minimap.square_size);
			cell_color = get_cell_color(cub3d->minimap.map_grid[y][x]);
			draw_square(cub3d, cell_color, pixel_x, pixel_y ); // + 2?? 
			x++;
		}
		y++;
	}
}
// start punkt +1 damit background damit kacheln entstehen 

void	draw_square(t_cub3d *cub3d, uint32_t color, int start_x,
		int start_y)
{
	int	x;
	int y;
	int inner_size;

	inner_size = cub3d->minimap.square_size- MINIMAP_CELL_GAP;
	if (inner_size < 1)
        inner_size = 1;
	y = 0;
	while (y < inner_size)
	{
		x = 0;
		while (x < inner_size)
		{
			if (start_x + x + 1 >= 0 && start_x + x + 1 < (int)cub3d->window_width &&
					start_y + y + 1 >= 0 && start_y + y + 1 < (int)cub3d->window_height)
			{
				mlx_put_pixel(cub3d->img, start_x + x +1 , start_y + y + 1, color);
			}
			x++; 
		}
		y++;
	}
}

