/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:14:56 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/01 11:25:00 by poverbec         ###   ########.fr       */
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

	(void)square_size;

	map_height = get_map_height(cub3d->map);
	map_width = get_map_width(cub3d->map);

	square_size = fmin(cub3d->minimap_img_width / map_width,
			cub3d->minimap_img_height / map_height);
	if (square_size < 1)
        square_size = 1;
	minimap_x = cub3d->window_width -cub3d->minimap_img_width - 10;
	minimap_y = 10;
	draw_minimap_background(cub3d, minimap_x ,minimap_y);
	draw_minimap_cells()
}




void	draw_minimap_background(t_cub3d *cub3d, int start_x, int start_y)
{
	int	x;
	int	y;
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

void	draw_minimap_cells(t_cub3d *cub3d, int map_height, int map_width)
{
	int cell_type;
	int x;
	
	x = 0;
	while(x < map_height )
	{
		
		cell_type = get_cell_color(cub3d->map)
		
	}
}
	
int	get_cell_color(t_cub3d *cub3d)
{
	
}