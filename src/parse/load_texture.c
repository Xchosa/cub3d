/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 15:00:20 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

int	parse_texture_helper(t_cub3d *cub3d, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'O' && line[i + 2] == ' ')
	{
		if (ft_parse_texture(line + i + 3, &cub3d->graphics->north) == false)
			return (-1);
		return (1);
	}
	else if (line[i] == 'S' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'O' && line[i + 2] == ' ')
	{
		if (ft_parse_texture(line + i + 3, &cub3d->graphics->south) == false)
			return (-1);
		return (1);
	}
	else if (line[i] == 'W' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'E' && line[i + 2] == ' ')
	{
		if (ft_parse_texture(line + i + 3, &cub3d->graphics->west) == false)
			return (-1);
		return (1);
	}
	return (0);
}

// path ist schon e.g. cub3d->graphics->east
bool	ft_parse_texture(char *path, t_img *texture)
{
	int		fd;
	char	*tmp_path;
	char	*copy_path;

	if (!path || !*path)
		return (ft_error(CONFIGUARTION_LINE), false);
	if (texture->used == true)
	{
		return (ft_error(CONFIG_DUPLICATE), false);
	}
	while (path && (*path == ' ' || *path == '\t'))
		path++;
	tmp_path = ft_strdup(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error(IMAGE_OPEN_FAILED), false);
	close(fd);
	copy_path = ft_strtrim(tmp_path, "\t\n\v\f\r ");
	texture->path = copy_path;
	free(tmp_path);
	texture->used = true;
	if (!texture->path)
		return (ft_error(MALLOC_FAIL), false);
	texture->img = NULL;
	return (true);
}

bool	load_texture(t_cub3d *cub3d)
{
	cub3d->graphics->north.texture = mlx_load_png(cub3d->graphics->north.path);
	if (!cub3d->graphics->north.texture)
		return (false);
	cub3d->graphics->south.texture = mlx_load_png(cub3d->graphics->south.path);
	if (!cub3d->graphics->south.texture)
		return (false);
	cub3d->graphics->east.texture = mlx_load_png(cub3d->graphics->east.path);
	if (!cub3d->graphics->east.texture)
		return (false);
	cub3d->graphics->west.texture = mlx_load_png(cub3d->graphics->west.path);
	if (!cub3d->graphics->west.texture)
		return (false);
	if (load_texture_2(cub3d) == false)
		return (false);
	cub3d->graphics->north.used = true;
	cub3d->graphics->south.used = true;
	cub3d->graphics->east.used = true;
	cub3d->graphics->west.used = true;
	return (true);
}

bool	load_texture_2(t_cub3d *cub3d)
{
	cub3d->graphics->north.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->north.texture);
	if (!cub3d->graphics->north.img)
		return (false);
	cub3d->graphics->west.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->west.texture);
	if (!cub3d->graphics->west.img)
		return (false);
	cub3d->graphics->south.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->south.texture);
	if (!cub3d->graphics->south.img)
		return (false);
	cub3d->graphics->east.img = mlx_texture_to_image(cub3d->mlx,
			cub3d->graphics->east.texture);
	if (!cub3d->graphics->east.img)
		return (false);
	return (true);
}
