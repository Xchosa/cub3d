/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/04 11:36:37 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"
#include "init.h"



void	ft_parse_texture(char *path, t_img *texture)
{
	//int	fd;

	if (!path || !*path)
		ft_error(CONFIGUARTION_LINE);
	if (texture->used == true)
	{
		ft_error(CONFIG_DUPLICATE);
	}
	while (path && (*path == ' ' || *path == '\t'))
		path++;
	// fd = open(path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error(IMAGE_OPEN_FAILED);
	// close(fd);
	texture->path = ft_strtrim(ft_strdup(path), "\t\n\v\f\r ");
	texture->used = true;
	if (!texture->path)
		ft_error(MALLOC_FAIL);
	texture->img = NULL;
}




bool	load_texture(t_cub3d *cub3d)
{
	cub3d->graphics->north.texture = mlx_load_png(cub3d->graphics->north.path);
	if (!cub3d->graphics->north.texture)
		return (false);
	cub3d->graphics->north.img = mlx_texture_to_image(cub3d->mlx, cub3d->graphics->north.texture);
	if (!cub3d->graphics->north.img)
		return (false);
	cub3d->graphics->south.texture = mlx_load_png(cub3d->graphics->south.path);
	if (!cub3d->graphics->south.texture)
		return (false);
	cub3d->graphics->south.img = mlx_texture_to_image(cub3d->mlx, cub3d->graphics->south.texture);
	if (!cub3d->graphics->south.img)
		return (false);
	cub3d->graphics->west.texture = mlx_load_png(cub3d->graphics->west.path);
	if (!cub3d->graphics->west.texture)
		return (false);
	cub3d->graphics->west.img = mlx_texture_to_image(cub3d->mlx, cub3d->graphics->west.texture);
	if (!cub3d->graphics->west.img)
		return (false);
	cub3d->graphics->east.texture = mlx_load_png(cub3d->graphics->east.path);
	if (!cub3d->graphics->east.texture)
		return (false);
	cub3d->graphics->east.img = mlx_texture_to_image(cub3d->mlx, cub3d->graphics->east.texture);
	if (!cub3d->graphics->east.img)
		return (false);
	return (true);
}


