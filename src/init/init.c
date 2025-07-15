
#include "init.h"


bool	init_cub3d(t_cub3d *cub3d, char **argv)
{
	t_graphics	graphics;

	ft_memset(cub3d, 0, sizeof(cub3d));
	// alles auf Null setzen und malloc
	if (!cub3d)
		return (false);
	if (create_mlx(cub3d) == false)
		return (false);
	set_up_cub3d_defaults(cub3d);
	cub3d->graphics = get_map(&graphics, argv[1]);
	return (true);
}

t_graphics	*get_map(t_graphics *graphics, char **argv)
{
	ft_memset(graphics, 0, sizeof(graphics));
	graphics->floor_colour = YELLOW_COLOR;
	graphics->ceiling_colour = GREY_COLOR;
	// graphics->north = upload_texture()
}

void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d* )param;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);
	// movement of player logic

}

// t_img *upload_texture()
// {

// }
void	set_up_cub3d_defaults(t_cub3d *cub3d)
{
	cub3d->window_width = MIN_WINDOW_WIDTH;
	cub3d->window_height = MIN_WINDOW_HEIGHT;
	cub3d->minimap_img_width = MINIMAP_WIDTH / 5;
	cub3d->minimap_img_height = MINIMAP_HEIGHT / 5;
}

bool	create_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (cub3d->mlx)
		return (false);
	mlx_set_window_limit(cub3d->mlx, MIN_WINDOW_WIDTH,
		MIN_WINDOW_HEIGHT, MAX_WINDOW_WIDTH, MAX_WINDOW_WIDTH);
}
