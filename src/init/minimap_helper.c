/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:29:57 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/07 14:05:53 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

int	get_cell_color(char cell)
{
	if (cell == '1')
	{
		return (BLACK_COLOR);
	}
	else if (cell == '0')
	{
		return (WHITE_COLOR);
	}
	else if (cell == ' ')
		return (BLACK_TRANS_COLOR);
	else if (ft_strchr("NSEW", cell ) != 0)
		// return (PLAYER_COLOR);
		return (WHITE_COLOR); // player danach drueber malen 
	else
		return (BLACK_TRANS_COLOR);
}


int	return_square_size(t_cub3d *cub3d, int map_width, int map_height)
{
	int	square_size;

	square_size = fmin(cub3d->minimap_img_width / map_width,
		cub3d->minimap_img_height / map_height);
	if (square_size < 1)
		square_size = 1;
	return (square_size);
}

void replace_spaces_with_2(char **map)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == ' ')
                map[i][j] = '2';
            j++;
        }
        i++;
    }
	
}


bool	malloc_minimap_grid(t_cub3d *cub3d)
{
	int	y;

	y = 0;

	cub3d->minimap.map_grid = malloc((cub3d->minimap.map_height + 1) *  sizeof(char *));
	if (!cub3d->minimap.map_grid)
        return (false);
	cub3d->minimap.map_grid[cub3d->minimap.map_height] = NULL;
	while (y < cub3d->minimap.map_height)
	{

		cub3d->minimap.map_grid[y] = malloc(cub3d->minimap.map_width + 1 * sizeof(char));
		if (!cub3d->minimap.map_grid[y])
			return (false);
		ft_memset(cub3d->minimap.map_grid[y], '2', cub3d->minimap.map_width);
		cub3d->minimap.map_grid[y][cub3d->minimap.map_width] = '\0';
		y++;
	}
	// for (int y = 0; y < cub3d->minimap.map_height; y++)
    // 	ft_memset(cub3d->minimap.map_grid[y][x], '1', cub3d->minimap.map_width);
	// printf("print grid \n");
	// print_array(cub3d->minimap.map_grid);
	return (true);
}