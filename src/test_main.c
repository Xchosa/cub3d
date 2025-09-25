/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:53:06 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/25 17:59:05 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	cleanup_cub3d(&cub3d);
	return (0);
}

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}



