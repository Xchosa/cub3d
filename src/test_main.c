
# include "cub3d.h"


int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		fd;

	(void)argc;
	(void)argv;

	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	fd = argument_check(argc, argv);
	if (fd <0)
		return (1); 
	if (init_cub3d(&cub3d, argv[1], fd) == false)
	{
		close(fd);
		cleanup_cub3d(&cub3d);
		return (1);
	}
	mlx_loop_hook(cub3d.mlx, game_loop, &cub3d);
	// escape exit, player moving etc
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (0);
}



