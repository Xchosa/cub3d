/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:14:56 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/04 16:46:38 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

void	draw_minimap(t_cub3d *cub3d)
{
	int		map_height;
    int		map_width;
	int		square_size;
	int		minimap_x;
	int		minimap_y;
	int		

	map_height = get_map_height(cub3d->map);
	map_width = get_map_width(cub3d->map);
	square_size = return_square_size(cub3d, map_width, map_height);
	
	minimap_x = cub3d->window_width - cub3d->minimap_img_width - 10;
	minimap_y = 10;
	draw_minimap_background(cub3d, minimap_x ,minimap_y);
	
	// draw_minimap_cells(cub3d, minimap_x, minimap_y, );
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

// void	draw_minimap_cells(t_cub3d *cub3d, int map_height, int map_width, int minimap_x, int minimap_y)
// {
// 	int square_size;
// 	int map_height;
// 	int map_width;
// 	int x;
// 	int y;
// 	uint32_t cell_color;

// 	map_height = get_map_height(cub3d->map);
// 	map_width = get_map_width(cub3d->map);
// 	square_size = return_square_size(cub3d, map_width, map_height);
	
// 	(void)minimap_x;
// 	(void)minimap_y;
// 	// change x to y 
// 	x = 0;
// 	while (x < map_width )
// 	{
// 		y = 0;
// 		while (y < map_height)
// 		{
// 			cell_color = get_cell_color(cub3d->map[x][y]);
// 			draw_square(cub3d, cell_color, x, y, square_size);
// 			y++;
// 		}
// 		x++;
// 	}
// }
	
