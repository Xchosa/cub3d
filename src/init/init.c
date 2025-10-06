/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:52:53 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 13:52:54 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

bool	init_cub3d(t_cub3d *cub3d, char *map_path, int fd)
{
	set_up_cub3d_defaults(cub3d);
	if (init_textures(cub3d) == false)
		return (false);
	if (parse_map_file(cub3d, map_path, fd) == false)
		return (false);
	if (create_mlx(cub3d) == false)
		return (false);
	//if(fill_mlx_textures(cub3d) == false)
	//	return (false);
	if (load_texture(cub3d) == false) // instead of fill_mlx_textures
		return (false);
	
	if (init_minimap(cub3d) == false)
		return (false);
	render_map(cub3d);
	init_player(cub3d);
	cub3d->player.time = mlx_get_time();
	cub3d->show_minimap = 1;
	cub3d->show_rays = 1;
	return (true);
}

// only load one img for north/south east west the same 
bool	init_textures(t_cub3d *cub3d)
{
	cub3d->graphics = malloc(sizeof(t_graphics));
	ft_memset(cub3d->graphics, 0, sizeof(t_graphics));
	if (!cub3d->graphics)
	{
		ft_error(MALLOC_FAIL);
		return (false);
	}
	cub3d->graphics->north.used = false;
	cub3d->graphics->south.used = false;
	cub3d->graphics->east.used = false;
	cub3d->graphics->west.used = false;
	ft_memset(&cub3d->graphics->floor_colour, 0, sizeof(int));
	ft_memset(&cub3d->graphics->ceiling_colour, 0, sizeof(int));
	return (true);
}

//bool fill_correct_mlx_textures(t_cub3d *cub3d, char * sky_direction)
//{
//	if (sky_direction == 'NO')
//		cub3d->graphics->north.texture = mlx_load_png("textures/purplestone.png");
//}


bool	fill_mlx_textures(t_cub3d *cub3d)
{
	cub3d->graphics->north.texture = mlx_load_png("textures/purplestone.png");
	cub3d->graphics->north.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->north.texture);
	cub3d->graphics->south.texture = mlx_load_png("textures/bluestone.png");
	cub3d->graphics->south.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->south.texture);
	cub3d->graphics->west.texture = mlx_load_png("textures/wood.png");
	cub3d->graphics->west.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->west.texture);
	cub3d->graphics->east.texture = mlx_load_png("textures/eagle.png");
	cub3d->graphics->east.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->east.texture);
	if (!cub3d->graphics->north.img)
	{
		ft_error(MLX_IMG_FAIL);
		return (false);
	}
	cub3d->graphics->north.used = true;
	cub3d->graphics->south.used = true;
	cub3d->graphics->east.used = true;
	cub3d->graphics->west.used = true;
	return (true);
}

void	set_up_cub3d_defaults(t_cub3d *cub3d)
{
	cub3d->window_width = WINDOW_WIDTH;
	cub3d->window_height = WINDOW_HEIGHT;
	cub3d->minimap_img_width = MINIMAP_WIDTH;
	cub3d->minimap_img_height = MINIMAP_HEIGHT;
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
