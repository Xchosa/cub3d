/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:08:50 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/07 14:09:41 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"


bool	init_minimap(t_cub3d *cub3d)
{
	cub3d->minimap.map_height = get_map_height(cub3d->map);
	cub3d->minimap.map_width = get_map_width(cub3d->map);
	cub3d->minimap.square_size = return_square_size(cub3d,
			cub3d->minimap.map_width, cub3d->minimap.map_height);
	if (malloc_minimap_grid(cub3d) == false) // malloc minimap map mit allen max werten 
	 	return (false);
	if (map_to_grid(cub3d) == false)
		return (false);
	// printf("print grid \n");
	// print_array(cub3d->minimap.map_grid);

	return (true);
}


// ueberschreibt nicht 
bool	map_to_grid(t_cub3d *cub3d)
{
	int	y;
	int	x;
	int y_height_map;
	y = 0;
	y_height_map  = get_map_height(cub3d->map);


 	printf("before \n");
	print_array(cub3d->minimap.map_grid);
	while (y < cub3d->minimap.map_height)
	{
		x = 0;
		while (x < cub3d->minimap.map_width)
		{
			if(y < y_height_map && x < (int)ft_strlen(cub3d->map[y]))
			{
				if (ft_strchr("01NESW", cub3d->map[y][x]) != NULL)
					cub3d->minimap.map_grid[y][x] = cub3d->map[y][x];
				else if (ft_strchr(" \t", cub3d->map[y][x]) != NULL)
					cub3d->minimap.map_grid[y][x] = '2';
				else
					cub3d->minimap.map_grid[y][x] = '2';
			}
			x++;
		}
		y++;
	}
	printf("after \n");
	print_array(cub3d->minimap.map_grid);
	return (true);
}





void	init_player(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->minimap.map_height)
	{
		x = 0;
		while (x < cub3d->minimap.map_width)
		{
			
			if (ft_strchr("NSEW", cub3d->minimap.map_grid[y][x] ) != 0)
			{
				cub3d->player.px_x = x * cub3d->minimap.square_size + (cub3d->minimap.square_size/2); // mitte vom square
				cub3d->player.px_y = y * cub3d->minimap.square_size + (cub3d->minimap.square_size /2);
				//mlx_put_pixel(cub3d->img, cub3d->player.px_x, cub3d->player.px_y, PLAYER_COLOR);
				draw_player_minimap(cub3d, cub3d->player.px_y, cub3d->player.px_x);
				// player_view_direction(cub3d, y, x);
			}
			x++;
		}
		y++;
	}
}

// void	player_view_direction(t_cub3d *cub3d, int y, int x)
// {
// 	if ((ft_strchr("N", cub3d->map[y][x] ) != 0))
// 		cub3d->player.direction = // 90 grad im bogenmas
// 	else if ((ft_strchr("S", cub3d->map[y][x]) != 0))
// 					// 270
// 	else if ((ft_strchr("E", cub3d->map[y][x]) != 0))
// 		cub3d->player.direction = 180;
// 	else if ((ft_strchr("W", cub3d->map[y][x]) != 0))
// 		cub3d->player.direction = 0;
// }

void	draw_player_minimap(t_cub3d *cub3d, int p_y, int p_x)
{
	int radius;
	int	x;
	int	y;

	radius = cub3d->minimap.square_size / 4;
	y = radius * (-1);

	while (y <= radius)
	{
		x = radius * (-1);
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				mlx_put_pixel(cub3d->img, p_x + x, p_y + y, PLAYER_COLOR);
			}
			x++;
		}
		y++;
	}

}
