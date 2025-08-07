/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:10:15 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/07 11:17:45 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

void	render_map(t_cub3d *cub3d)
{
	uint32_t	i;

	i = 0;
	// clear image
	// printf("test");
	while (i < cub3d->window_width* cub3d->window_height)
	{
		cub3d->img->pixels[i] = 0;
		i++;
	}
	// printf("test");
	draw_minimap(cub3d);

}

void	draw_map_background(t_cub3d *cub3d)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;

	ceiling_color = *(cub3d->graphics->ceiling_colour);
	floor_color = *(cub3d->graphics->floor_colour);
	// split in two ti create 3d effect
	// draw ceiling
	y = 0;
	while (y < cub3d ->window_height / 2)
	{
		x = 0;
		while (x < cub3d->window_width)
		{
			mlx_put_pixel(cub3d->img, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	// Draw floor (bottom half)
	while (y < cub3d->window_height)
	{
		x = 0;
		while (x < cub3d->window_width)
		{
			mlx_put_pixel(cub3d->img, x, y, floor_color);
			x++;
		}
		y++;
	}
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
	{
		height++;
	}
	return (height);

}

int	get_map_width(char **map)
{
	int	width;
	int	max_width;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		width = ft_strlen(map[i]);
		if (width > max_width)
		{
			max_width = width;
		}
		i++;
	}
	return (max_width);
}



