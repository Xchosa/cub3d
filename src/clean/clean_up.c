/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:46:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/26 17:33:42 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_cub3d(t_cub3d *cub3d)
{
	clean_minimap(cub3d);
	if (cub3d->graphics)
	{
		free(cub3d->graphics->floor_colour);
		free(cub3d->graphics->ceiling_colour);
		free(cub3d->graphics);
	}
	
}


void	clean_minimap(t_cub3d *cub3d)
{
	if(cub3d->minimap.map_grid)
		(void)cub3d;
		//ft_free_array(cub3d->minimap.map_grid);
	//free(cub3d->minimap);
}



//void 	ft_free_array(char **arrays)
//{
	
//}