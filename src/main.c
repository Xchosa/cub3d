/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:53:06 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/08 11:58:59 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		fd;

	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	fd = argument_check(argc, argv);
	if (fd < 0)
		return (1);
	if (init_cub3d(&cub3d, argv[1], fd) == false)
	{
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

/*


// test fur valide map , exit mit close window
valgrind --tool=memcheck --leak-check=full --suppressions=mlx_suppress_2.supp
./cub3d maps/test.cub
too see gnl errors... --> gefixed 

*/
