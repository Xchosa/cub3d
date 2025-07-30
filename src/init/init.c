
#include "cub3d.h"
#include "init.h"


bool	init_cub3d(t_cub3d *cub3d, char *map_path)
{
	// t_graphics	graphics;

	ft_memset(cub3d, 0, sizeof(cub3d));
	// alles auf Null setzen und malloc
	if (!cub3d)
		return (false);
	set_up_cub3d_defaults(cub3d);
	if (init_textures(cub3d) == false)
		return (false);
	if (parse_map_file(cub3d, map_path) == false)
    // meguels weg nehmen. 
		return (false);
	// for dynamic resizing of window 
	// extra function needed 
	if (create_mlx(cub3d) == false)
		return (false);
	render_map(cub3d);
	// cub3d->graphics = get_map(&graphics, argv[1]);
	return (true);
}

bool	init_textures(t_cub3d *cub3d)
{
	cub3d->graphics = ft_memset(cub3d->graphics, 0, sizeof(t_graphics));
	if (!cub3d->graphics)
	{
		ft_error(MALLOC_FAIL);
		return (false);
	}
	ft_memset(cub3d->graphics->floor_colour, 0, sizeof(int));
	ft_memset(cub3d->graphics->ceiling_colour, 0, sizeof(int));
	*(cub3d->graphics->floor_colour) = YELLOW_COLOR;
	*(cub3d->graphics->ceiling_colour) = GREY_COLOR;

	return (true);

}

void	set_up_cub3d_defaults(t_cub3d *cub3d)
{
	cub3d->window_width = MIN_WINDOW_WIDTH;
	cub3d->window_height = MIN_WINDOW_HEIGHT;
	cub3d->minimap_img_width = MINIMAP_WIDTH / 5;
	cub3d->minimap_img_height = MINIMAP_HEIGHT / 5;
}

bool	create_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(cub3d->window_width, cub3d->window_height,
			"CUB3D", true);
	if (!cub3d->mlx)
	{
		ft_error(MLX_INIT_FAIL);
		return (false);
	}
	cub3d->img = mlx_new_image(cub3d->mlx, cub3d->window_width,
			cub3d->window_height);
	if (!cub3d->img)
	{
		ft_error(MLX_IMG_FAIL);
		return (false);
	}
	mlx_set_window_limit(cub3d->mlx, MIN_WINDOW_WIDTH,
		MIN_WINDOW_HEIGHT, MAX_WINDOW_WIDTH, MAX_WINDOW_WIDTH);
	if (mlx_image_to_window(cub3d->mlx, cub3d->img, 0, 0) < 0)
	{
		ft_error(MLX_IMG_TO_WINDOW_FAIL);
		return (false);
	}
	return (true);

}



// t_graphics	*get_map(t_graphics *graphics, char **argv)
// {
// 	ft_memset(graphics, 0, sizeof(graphics));
// 	graphics->floor_colour = YELLOW_COLOR;
// 	graphics->ceiling_colour = GREY_COLOR;
// 	// graphics->north = upload_texture()
// }

// void	game_loop(void *param)
// {
// 	t_cub3d	*cub3d;

// 	cub3d = (t_cub3d* )param;
// 	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(cub3d->mlx);
// 	// movement of player logic

// }

// // t_img *upload_texture()
// // {

// // }
