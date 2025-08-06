
#include "cub3d.h"
#include "init.h"

// t_object	*get_object(void)
// {
// 	static t_object	object;

// 	return (&object);
// }

// bool	init_object(t_cub3d *cub3d)
// {
// 	t_object	*object;

// 	object = get_object();

// 	object->map = ft_cpy_array_str(cub3d->map);
// 	if (!object->map)
// 		return (false);
// 	object->map_height = get_map_height(cub3d->map);
// 	object->map_width = get_map_width(cub3d->map);
// 	object->square_size = return_square_size(cub3d,
// 			object->map_width, object->map_height);

// 	return (true);
// }


bool	init_minimap(t_cub3d *cub3d)
{
	cub3d->minimap.map = ft_cpy_array_str(cub3d->map);
	if (!cub3d->minimap.map)
		return (false);
	cub3d->minimap.map_height = get_map_height(cub3d->map);
	cub3d->minimap.map_width = get_map_width(cub3d->map);
	cub3d->minimap.square_size = return_square_size(cub3d, 
		cub3d->minimap.map_width, cub3d->minimap.map_height);
	return (true);
}

void	init_player(t_cub3d *cub3d)
{
	uint32_t x;
	uint32_t y;

	y = 0;
	while(y < cub3d->minimap_img_height)
	{
		x = 0;
		while(x < cub3d->minimap_img_width)
		{
			if (ft_strchr("NSEW", cub3d->map[y][x] ) != 0)
			{
				cub3d->player.px_x = x * cub3d->minimap.square_size + (cub3d->minimap.square_size/2); // mitte vom square
				cub3d->player.px_y = y * cub3d->minimap.square_size + (cub3d->minimap.square_size /2);
				draw_player_minimap(cub3d, y, x);
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
	int player_color;
	int	x;
	int y;

	player_color = PLAYER_COLOR;

	// y = 0;
	// while(y < cub3d->minimap.square_size)
	// {
	// 	x = 0;
	// 	while(x < cub3d->minimap.square_size)
	// 	{
	// 		if (p_y + y  >= 0 && start_x + x < (int)cub3d->window_width &&
    //             start_y + y >= 0 && start_y + y < (int)cub3d->window_height)
	// 		{
	// 			mlx_put_pixel(cub3d->img, start_x + x, start_y + y, player_color);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	
	y = 0;
	while(y < 5)
	{
		x = 0;
		while( x < 5)
		{
			mlx_put_pixel(cub3d->img, p_y + y, p_x + x, player_color);
			x++;
		}
		y++;
	}
}