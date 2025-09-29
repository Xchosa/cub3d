/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:18:08 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/29 12:28:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	close_window(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *) param;

	if (cub3d->mlx)
		mlx_close_window(cub3d->mlx);
}


void	ft_free_array(char **arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
		i++;
	while (i >= 0)
	{
		free(arrays[i]);
		i--;
	}
	free(arrays);
}