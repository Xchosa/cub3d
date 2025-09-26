/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:49:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/26 12:12:30 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// // load textures in cub3d->graphics->north
// // load img in cub3d->graphics->north correctly

// east, west, north, south walls bekommen unterschiedliche graphics 
mlx_texture_t	*load_wall_texture(t_cub3d *cub3d, t_ray *ray)
{
	mlx_texture_t	*wall_texture;

	if (ray->side == 0 && ray->delta_x > 0)
		wall_texture = cub3d->graphics->east.texture;
	else if (ray->side == 0 && ray->delta_x < 0)
		wall_texture = cub3d->graphics->west.texture;
	else if (ray->side == 1 && ray->delta_y > 0)
		wall_texture = cub3d->graphics->south.texture;
	else
		wall_texture = cub3d->graphics->north.texture;
    return (wall_texture);
}

int	return_x_cor_texture(int wall_x, t_cub3d *cub3d,
	mlx_texture_t *wall_texture)
{
	if (wall_texture == cub3d->graphics->north.texture)
		return ((int)(wall_x * cub3d->graphics->north.texture->width));
	else if (wall_texture == cub3d->graphics->east.texture)
		return ((int)(wall_x * cub3d->graphics->east.texture->width));
	else if (wall_texture == cub3d->graphics->west.texture)
		return ((int)(wall_x * cub3d->graphics->west.texture->width));
	else
		return ((int)(wall_x * cub3d->graphics->south.texture->width));
}
