/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:08:50 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:18:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

//  // malloc minimap map mit allen max werten 
bool	init_minimap(t_cub3d *cub3d)
{
	cub3d->minimap.map_height = get_map_height(cub3d->map);
	cub3d->minimap.map_width = get_map_width(cub3d->map);
	cub3d->minimap.square_size = return_square_size(cub3d,
			cub3d->minimap.map_width, cub3d->minimap.map_height);
	if (malloc_minimap_grid(cub3d) == false)
		return (false);
	if (map_to_grid(cub3d) == false)
		return (false);
	return (true);
}

// ueberschreibt nicht 
//	print_array(cub3d->minimap.map_grid);
bool	map_to_grid(t_cub3d *cub3d)
{
	int	y;
	int	x;
	int	y_height_map;

	y = 0;
	y_height_map = get_map_height(cub3d->map);
	while (y < cub3d->minimap.map_height)
	{
		x = 0;
		while (x < cub3d->minimap.map_width)
		{
			if (y < y_height_map && x < (int)ft_strlen(cub3d->map[y]))
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
	return (true);
}
