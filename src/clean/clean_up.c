/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:46:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:12:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_cub3d(t_cub3d *cub3d)
{
	clean_minimap(cub3d);
	clean_img(cub3d);
	clean_texture(cub3d);
	clean_graphics(cub3d);
}

void	clean_minimap(t_cub3d *cub3d)
{
	if (cub3d->minimap.map_grid)
		ft_free_array(cub3d->minimap.map_grid);
	cub3d->minimap.map_grid = NULL;
	if (cub3d->map)
		ft_free_array(cub3d->map);
	cub3d->map = NULL;
}

void	clean_texture(t_cub3d *cub3d)
{
	//if(cub3d->graphics->north.path)
	//	free(cub3d->graphics->north.path); /// fier east west etc 
	if (cub3d->graphics->north.texture)
		mlx_delete_texture(cub3d->graphics->north.texture);
	if (cub3d->graphics->south.texture)
		mlx_delete_texture(cub3d->graphics->south.texture);
	if (cub3d->graphics->west.texture)
		mlx_delete_texture(cub3d->graphics->west.texture);
	if (cub3d->graphics->east.texture)
		mlx_delete_texture(cub3d->graphics->east.texture);
}

void	clean_img(t_cub3d *cub3d)
{
	if (cub3d->graphics->north.img)
		mlx_delete_image(cub3d->mlx, cub3d->graphics->north.img);
	if (cub3d->graphics->south.img)
		mlx_delete_image(cub3d->mlx, cub3d->graphics->south.img);
	if (cub3d->graphics->west.img)
		mlx_delete_image(cub3d->mlx, cub3d->graphics->west.img);
	if (cub3d->graphics->east.img)
		mlx_delete_image(cub3d->mlx, cub3d->graphics->east.img);
	if (cub3d->graphics->north.path)
		free(cub3d->graphics->north.path);
	if (cub3d->graphics->south.path)
		free(cub3d->graphics->south.path);
	if (cub3d->graphics->west.path)
		free(cub3d->graphics->west.path);
	if (cub3d->graphics->east.path)
		free(cub3d->graphics->east.path);
}

void	clean_graphics(t_cub3d *cub3d)
{
	if (cub3d->graphics->floor_colour)
		free(cub3d->graphics->floor_colour);
	if (cub3d->graphics->ceiling_colour)
		free(cub3d->graphics->ceiling_colour);
	if (cub3d->graphics)
		free(cub3d->graphics);
	cub3d->graphics = NULL;
}
