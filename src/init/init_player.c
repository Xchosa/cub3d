
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