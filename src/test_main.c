
# include "init.h"


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_cub3d cub3d;
	

	if(init_cub3d(&cub3d, argv[1]) == false)
		return(1); // free function
	mlx_loop_hook(cub3d.mlx, game_loop, &cub3d); // escape exit, player moving etc 
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (0);
}


// 