/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/07/31 11:12:58 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"



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
	cub3d->graphics->north.img = mlx_load_png(cub3d->graphics->north.path);
	if (!cub3d->graphics->north.img)
		return (false);
	cub3d->graphics->south.img = mlx_load_png(cub3d->graphics->south.path);
	if (!cub3d->graphics->south.img)
		return (false);
	cub3d->graphics->west.img = mlx_load_png(cub3d->graphics->west.path);
	if (!cub3d->graphics->west.img)
		return (false);
	cub3d->graphics->east.img = mlx_load_png(cub3d->graphics->east.path);
	if (!cub3d->graphics->east.img)
		return (false);
}
