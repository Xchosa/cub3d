/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:44:12 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/24 09:44:40 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"


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
				set_player_view(cub3d, cub3d->minimap.map_grid[y][x]);
				cub3d->player.px_x = x * cub3d->minimap.square_size + (cub3d->minimap.square_size/2) + 1; // mitte vom square
				cub3d->player.px_y = y * cub3d->minimap.square_size + (cub3d->minimap.square_size /2) + 1;
				//mlx_put_pixel(cub3d->img, cub3d->player.px_x, cub3d->player.px_y, PLAYER_COLOR);
				//draw_player_minimap(cub3d, cub3d->player.px_y, cub3d->player.px_x);
				// player_view_direction(cub3d, y, x);
			}
			x++;
		}
		y++;
	}
	cub3d->player.direction = get_player_angle(cub3d->player.player_view);
}


void	draw_player_minimap(t_cub3d *cub3d, double p_y, double p_x)
{
	int	radius;
	int	x;
	int	y;

	radius = cub3d->minimap.square_size / 3.5;
	y = radius * (-1);

	while (y <= radius)
	{
		x = radius * (-1);
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				if(p_x + x >= 0 && p_y + y >= 0 && (p_x + x) < cub3d->window_width
					&& (p_y + y) < cub3d->window_height)
					mlx_put_pixel(cub3d->img, p_x + x, p_y + y, PLAYER_COLOR);
			}
			x++;
		}
		y++;
	}

}

void	set_player_view(t_cub3d *cub3d, char player_direction)
{
		cub3d->player.player_view = player_direction;
}

