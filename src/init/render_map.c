

#include "cub3d.h"
#include "init.h"

void	render_map(t_cub3d *cub3d)
{
	uint32_t	i;

	i = 0;
	// clear image
	while (i < cub3d->window_width* cub3d->window_height)
	{
		cub3d->img->pixels[i] = 0;
		i++;
	}
	draw_map_background(cub3d);
	// draw_minimap(cub3d);

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
		height++;
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

void	draw_minimap(t_cub3d *cub3d)
{
	int		map_height;
    int		map_width;
	int		square_size;
	int		x;
	int		y;

	(void)square_size;
	(void)x;
	(void)y;
	map_height = get_map_height(cub3d->map);
	map_width = get_map_width(cub3d->map);

	square_size = fmin(cub3d->minimap_img_width / map_width,
			cub3d->minimap_img_height / map_height);
	if (square_size < 1)
        square_size = 1;
	
}


