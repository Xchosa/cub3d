/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 13:53:52 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"
#include "init.h"


int parse_texture_helper(t_cub3d *cub3d, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'O' && line[i + 2] == ' ')
	{
		if(ft_parse_texture(line + i + 3, &cub3d->graphics->north) == false)
			return (-1);
		return (1);
	}
	else if (line[i] == 'S' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'O' && line[i + 2] == ' ')
	{
		if(ft_parse_texture(line + i + 3, &cub3d->graphics->south) == false)
			return (-1);
		return (1);
	}
	else if (line[i] == 'W' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'E' && line[i + 2] == ' ')
	{
		if(ft_parse_texture(line + i + 3, &cub3d->graphics->west) == false)
			return (-1);
		return (1);
	}
	return (0);
}


// path ist schon e.g. cub3d->graphics->east
bool	ft_parse_texture(char *path, t_img *texture)
{
	//int	fd;
	char *tmp_path;
	//char *sky_direction;
	char *copy_path;
	if (!path || !*path)
		return(ft_error(CONFIGUARTION_LINE), false);
	if (texture->used == true)
	{
		return(ft_error(CONFIG_DUPLICATE), false);
	}
	//// skip whitepace
	//ft_strlcpy(sky_direction, path, 2);
	while (path && (*path == ' ' || *path == '\t'))
		path++;
	tmp_path = ft_strdup(path);
	// fd = open(path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error(IMAGE_OPEN_FAILED);
	// close(fd);
	copy_path = ft_strtrim(tmp_path, "\t\n\v\f\r ");
	// texture->path = ft_strdup(copy_path);
	texture->path = copy_path;
	
	//printf("path texture png:   %s", texture->path);
	//fill_correct_mlx_textures(cub3d, sky_direction, path);
	
	free(tmp_path); // freed helper path duped
	// pointed e.g. an 3 stelle von gemaloced path 
	texture->used = true;
	if (!texture->path)
		return(ft_error(MALLOC_FAIL), false);
	texture->img = NULL;
	printf("path:'%s' \n", texture->path);
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
	//if (!cub3d->graphics->north.img)
	//{
	//	ft_error(MLX_IMG_FAIL);
	//	return (false);
	//
	// check if all graphics are set 
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
