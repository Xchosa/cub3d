#include "cub3d.h"


void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);
	move_player(cub3d);
	render_map(cub3d);
	// key hook for letting minimap appear 
}

// 1. bild initalisieren, dann player
// 2. in game loop 
// 		player moven, rays schiesen
//		minimap, und karte neu malen, player ort uebergaben 

void	move_player(t_cub3d *cub3d)
{
	double time_now;
	double fps;

	// int p_x;
	// int p_y;
	double px_d;
	double py_d;

	px_d = 0.0;
	py_d = 0.0;
	// p_x = (int)cub3d->player.px_x;
	// p_y = (int)cub3d->player.px_y;

	time_now = mlx_get_time();
	fps = time_now - cub3d->player.time;
	if (fps > 0.1)
		fps = 0.1;
	cub3d->player.time = time_now;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
	{	
		py_d += 0.1 * fps; 
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
	{	
		py_d-= 0.1 * fps; 
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
	{	
		px_d += 0.1 * fps; 
	}
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
	{	
		px_d -= 0.1 * fps;
	}
	
	// if(cub3d->minimap.map_grid[cub3d->player.px_y + py_d ][p_x] == '1')

	printf("player x Wert %f",  cub3d->player.px_x);
	printf("player y Wert %f",  cub3d->player.px_y);
	
	// if(cub3d->minimap.map_grid[p_y][p_x] == '1')
		//dann nicht updaten. 

}
