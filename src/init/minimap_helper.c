/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:29:57 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/06 15:38:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

int	get_cell_color(char cell)
{
	if (cell == '1')
	{
		return (BLACK_COLOR);
	}
	else if (cell == '0')
	{
		return (WHITE_COLOR);
	}
	else if (ft_strchr("NSEW", cell ) != 0)
		// return (PLAYER_COLOR);
		return (WHITE_COLOR); // player danach drueber malen 
	else
		return (BLACK_TRANS_COLOR);
}


int	return_square_size(t_cub3d *cub3d, int map_width, int map_height)
{
	int	square_size;

	square_size = fmin(cub3d->minimap_img_width / map_width,
		cub3d->minimap_img_height / map_height);
	if (square_size < 1)
		square_size = 1;
	return (square_size);
}
