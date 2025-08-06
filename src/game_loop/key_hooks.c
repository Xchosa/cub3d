#include "cub3d.h"


void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
	{
		
	}
	// key hook for letting minimap appear 
}
