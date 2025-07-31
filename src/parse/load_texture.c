/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/07/31 15:44:58 by mimalek          ###   ########.fr       */
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
	// if (texture->path[0] != '\0')
	// {
	// 	ft_error(CONFIG_DUPLICATE);
	// }
	while (path && (*path == ' ' || *path == '\t'))
		path++;
	// fd = open(path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error(IMAGE_OPEN_FAILED);
	// close(fd);
	texture->path = ft_strdup(path);
	if (!texture->path)
		ft_error(MALLOC_FAIL);
	texture->img = NULL;
}




bool	load_texture(t_cub3d *cub3d)
{
	ft_printf("%s\n", cub3d->graphics->north.path);
	ft_printf("%s\n", cub3d->graphics->south.path);
	ft_printf("%s\n", cub3d->graphics->west.path);
	ft_printf("%s\n", cub3d->graphics->east.path);
	cub3d->graphics->north.texture = mlx_load_png(cub3d->graphics->north.path);
	if (!cub3d->graphics->north.texture)
		return (false);
	cub3d->graphics->south.texture = mlx_load_png(cub3d->graphics->south.path);
	if (!cub3d->graphics->south.texture)
		return (false);
	cub3d->graphics->west.texture = mlx_load_png(cub3d->graphics->west.path);
	if (!cub3d->graphics->west.texture)
		return (false);
	cub3d->graphics->east.texture = mlx_load_png(cub3d->graphics->east.path);
	if (!cub3d->graphics->east.texture)
		return (false);
	return (true);
}


