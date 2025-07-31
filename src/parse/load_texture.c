/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/07/31 10:09:50 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"

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
