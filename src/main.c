/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:43 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:55:15 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	t_cub3d	*data;

// 	ft_memset(data, 0, sizeof(t_cub3d)); // sonst is garbage im pointer
// 	//data = malloc(sizeof(t_cub3d));
// 	if (!data)
// 		return (ft_error(MALLOC_FAIL), MALLOC_FAIL);
// 	data->graphics = malloc(sizeof(t_graphics));
// 	if (!data->graphics)
// 		return (ft_error(MALLOC_FAIL), free(data), MALLOC_FAIL);
// 	fd = argument_check(argc, argv);
// 	ft_validate_parse_file(data, fd);
// 	ft_printf("North: %s\n", data->graphics->north.path);
// 	ft_printf("South: %s\n", data->graphics->south.path);
// 	ft_printf("West: %s\n", data->graphics->west.path);
// 	ft_printf("East: %s\n", data->graphics->east.path);
// 	ft_printf("Floor Colour: %d\n", *(data->graphics->floor_colour));
// 	ft_printf("Ceiling Colour: %d\n", *(data->graphics->ceiling_colour));

// 	mlx_loop_hook(data.mlx, game_loop, &cub3d); 
// escape exit, player moving etc
// 	mlx_loop(cub3d.mlx);
// 	mlx_terminate(cub3d.mlx);

// 	return (close(fd), 0);
// }
