# include "init.h"


bool	init_cub3d(t_cub3d *cub3d, char **argv)
{
	t_graphics graphics;
	ft_memset(cub3d, 0, sizeof(cub3d)); // alles auf Null setzen und malloc
	if(!cub3d)
		return (false);
	cub3d->window_width = MIN_WINDOW_WIDTH;
	cub3d->window_height = MIN_WINDOW_HEIGHT;
	cub3d->minimap_img_width = MINIMAP_WIDTH;
	cub3d->minimap_img_height = MINIMAP_HEIGHT;
	cub3d->graphics = get_map(&graphics, argv[1]);
	return (true);
}

t_graphics	*get_map(t_graphics *graphics, char **argv)
{
	ft_memset(graphics, 0, sizeof(graphics));
	graphics->floor_colour = YELLOW_COLOR;
	graphics->ceiling_colour = GREY_COLOR;

}