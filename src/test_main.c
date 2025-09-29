/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:53:06 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/29 12:30:37 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		fd;

	(void)argc;
	(void)argv;

	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	fd = argument_check(argc, argv);
	if (fd < 0)
		return (1);
	if (init_cub3d(&cub3d, argv[1], fd) == false)
	{
		printf("error case works, it can be cleaned \n");
		close(fd);
		cleanup_cub3d(&cub3d);
		return (1);
	}
	mlx_close_hook(cub3d.mlx, &close_window, &cub3d);
	mlx_loop_hook(cub3d.mlx, game_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	cleanup_cub3d(&cub3d);
	mlx_terminate(cub3d.mlx);
	return (0);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}



// issues 
/*
The buffer overflow  in draw_column

Ray calculations producing invalid texture coordinates
Window resize events not being handled properly
Array indexing without proper bounds checking in draw_column

*/
