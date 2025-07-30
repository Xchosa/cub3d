


#include "cub3d.h"


void	cleanup_cub3d(t_cub3d *cub3d)
{
	if (cub3d->mlx)
	{
		mlx_terminate(cub3d->mlx);
		cub3d->mlx = NULL;
	}
	if (cub3d->graphics)
	{
		free(cub3d->graphics->floor_colour);
		free(cub3d->graphics->ceiling_colour);
		free(cub3d->graphics);
	}
}